#include "stdafx.h"
#include "MainWindow.h"
#include "DlgLameConvertor.h"
#include "DlgSettings.h"
#include "DlgRun.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <FEBio/FEBioExport25.h>
#include "DlgFEBioOptimize.h"
#include <QFileDialog>
#include <QApplication>

void CMainWindow::on_actionCurveEditor_triggered()
{
	ui->showCurveEditor();
}

void CMainWindow::on_actionMeshInspector_triggered()
{
	ui->showMeshInspector();
}

void CMainWindow::on_actionElasticityConvertor_triggered()
{
	CDlgLameConvertor dlg(this);
	dlg.exec();
}

void CMainWindow::on_actionFEBioRun_triggered()
{
	// First, check that a job is not running yet
	if (ui->m_process && (ui->m_process->state()!=QProcess::NotRunning))
	{
		QMessageBox::information(this, "PreView2", "An FEBio job is already running.\nYou must wait till the job is finished or stop it.");
		return;
	}

	// get the document
	CDocument* doc = GetDocument();

	// get the project folder and name
	QString projectName = QString::fromStdString(doc->GetDocFileBase());
	QString projectFolder = QString::fromStdString(doc->GetDocFolder());

	// create a name for this job
	QString jobName = projectName;
	jobName += QString("_job");

	// By default, the job path will be the project folder
	// unless the project folder is not defined, in which case we'll reuse the last path
	static QString lastPath;
	QString jobPath;
	if (projectFolder.isEmpty()) jobPath = lastPath;
	else jobPath = "$(ProjectDir)";

	// this keeps track of the FEBio selection that was used last
	static int lastFEBioIndex = 0;

	static int lastFEBioFileVersion = 0;

	// setup the run dialog
	CDlgRun dlg(this);
	dlg.SetWorkingDirectory(jobPath);
	dlg.SetJobName(jobName);
	dlg.SetFEBioPath(ui->m_febio_path, ui->m_febio_info, lastFEBioIndex);
	dlg.Init();
	if (dlg.exec())
	{
		// get the working directory and job name
		jobPath = dlg.GetWorkingDirectory();
		jobName = dlg.GetJobName();

		// store the last path
		lastPath = jobPath;

		// see if a job with this name already exists
		CFEBioJob* job = doc->FindFEBioJob(jobName.toStdString());

		// if not, create a new job
		if (job == nullptr)
		{
			// create a new new job
			job = new CFEBioJob(doc, jobName.toStdString(), jobPath.toStdString());
			doc->AddFEbioJob(job);

			// show it in the model viewer
			UpdateModel(job);
		}

		// get the selected FEBio version
		lastFEBioIndex = dlg.GetFEBioPath();

		// get the selected FEBio file vesion
		lastFEBioFileVersion = dlg.GetFEBioFileVersion();

		// run the job
		RunFEBioJob(job, lastFEBioIndex, lastFEBioFileVersion, dlg.WriteNodes(), dlg.CommandLine());
	}
}

void CMainWindow::on_actionFEBioStop_triggered()
{
	if (ui->m_process && (ui->m_process->state() == QProcess::Running))
	{
		ui->m_bkillProcess = true;
		ui->m_process->kill();

		CFEBioJob* job = GetDocument()->GetActiveJob();
		if (job)
		{
			job->SetStatus(CFEBioJob::CANCELLED);
			GetDocument()->SetActiveJob(nullptr);
			ShowInModelViewer(job);
		}
	}
	else QMessageBox::information(this, "PreView2", "No FEBio job is running.");
}

void CMainWindow::on_actionFEBioOptimize_triggered()
{
	CDlgFEBioOptimize dlg(this);
	if (dlg.exec() == QDialog::Accepted)
	{
		QString fileName = QFileDialog::getSaveFileName(this, "Save", "", "*.feb");
		if (fileName.isEmpty() == false)
		{
			FEBioOpt opt = dlg.GetFEBioOpt();
			if (GetDocument()->GenerateFEBioOptimizationFile(fileName.toStdString(), opt) == false)
			{
				QMessageBox::critical(this, "Generate FEBio Optimization file", "Something went terribly wrong!");
			}
			else
			{
				QMessageBox::information(this, "Generate FEBio Optimization file", "Success writing FEBio optimization file!");
			}
		}
	}
}

void CMainWindow::on_actionOptions_triggered()
{
	CDlgSettings dlg(this);
	dlg.exec();
}

void CMainWindow::onRunFinished(int exitCode, QProcess::ExitStatus es)
{
	if (exitCode == 0)
	{
		QMessageBox::information(this, "Run FEBio", "Normal termination");
		AddLogEntry("FEBio exited: Normal termination\n");
	}
	else
	{
		QMessageBox::information(this, "Run FEBio", "Error termination");
		AddLogEntry("FEBio exited: Error termination\n");
	}

	CFEBioJob* job = GetDocument()->GetActiveJob();
	if (job)
	{
		job->SetStatus(exitCode == 0 ? CFEBioJob::COMPLETED : CFEBioJob::FAILED);
		ShowInModelViewer(job);
		GetDocument()->SetActiveJob(nullptr);
	}

	delete ui->m_process;
	ui->m_process = 0;
}

void CMainWindow::onReadyRead()
{
	if (ui->m_process == 0) return;

	QByteArray output = ui->m_process->readAll();
	QString s(output);
	AddOutputEntry(s);
}

void CMainWindow::onErrorOccurred(QProcess::ProcessError err)
{
	// suppress an error if user stopped FEBio job
	if (ui->m_bkillProcess && (err==QProcess::Crashed))
	{
		return;
	}

	QString errString;
	switch (err)
	{
	case QProcess::FailedToStart: errString = "Failed to start"; break;
	case QProcess::Crashed      : errString = "Crashed"; break;
	case QProcess::Timedout     : errString = "Timed out"; break;
	case QProcess::WriteError   : errString = "Write error"; break;
	case QProcess::ReadError    : errString = "Read error"; break;
	case QProcess::UnknownError : errString = "Unknown error"; break;
	default:
		errString = QString("Error code = %1").arg(err);
	}

	QString t = "An error has occurred.\nError = " + errString;
	AddLogEntry(t);
	QMessageBox::critical(this, "Run FEBio", t);
}
