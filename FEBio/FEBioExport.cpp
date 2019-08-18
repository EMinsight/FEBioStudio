#include "stdafx.h"
#include "FEBioExport.h"
#include <MeshTools/FERigidConstraint.h>
#include <MeshTools/FEMultiMaterial.h>

FEBioExport::FEBioExport()
{
	m_compress = false;
	m_exportSelections = false;

	// initialize section flags
	for (int i = 0; i<FEBIO_MAX_SECTIONS; ++i) m_section[i] = true;
}

void FEBioExport::SetPlotfileCompressionFlag(bool b)
{
	m_compress = b;
}

void FEBioExport::SetExportSelectionsFlag(bool b)
{
	m_exportSelections = b;
}

//-----------------------------------------------------------------------------
void FEBioExport::WriteParam(Param &p)
{
	// don't export hidden parameters
	if (p.IsReadWrite() == false) return;

	// get the (short) name
	const char* szname = p.GetShortName();

	// get the index data (if any)
	const char* szindex = p.GetIndexName();
	int nindex = p.GetIndexValue();

	// setup the xml-element
	XMLElement e;
	e.name(szname);
	if (szindex) e.add_attribute(szindex, nindex);
	FELoadCurve* plc = p.GetLoadCurve();
	if (plc && plc->Size())
	{
		assert(plc->GetID() > 0);
		e.add_attribute("lc", plc->GetID());
	}
	switch (p.GetParamType())
	{
	case Param_CHOICE: 
		{
			int n = p.GetIntValue() + p.GetOffset();
			e.value(n); 
		}
		break;
	case Param_INT   : e.value(p.GetIntValue  ()); break;
	case Param_FLOAT : e.value(p.GetFloatValue()); break;
	case Param_BOOL  : e.value(p.GetBoolValue ()); break;
	case Param_VEC3D : e.value(p.GetVecValue  ()); break;
	case Param_MATH  :
	{
		e.add_attribute("type", "math");
		std::string smath = p.GetMathString();
		e.value(smath.c_str());
	}
	break;
    default:
		assert(false);
	}

	// write the xml-element
	m_xml.add_leaf(e);
}

//-----------------------------------------------------------------------------
void FEBioExport::WriteParamList(ParamContainer& c)
{
	int NP = c.Parameters();
	for (int i = 0; i<NP; ++i) WriteParam(c.GetParam(i));
}

//-----------------------------------------------------------------------------
void FEBioExport::AddLoadCurve(FELoadCurve* plc)
{
	assert(plc);
	m_pLC.push_back(plc);
	plc->SetID((int)m_pLC.size());
}

//-----------------------------------------------------------------------------
void FEBioExport::AddLoadCurves(ParamContainer& PC)
{
	int N = PC.Parameters();
	for (int i = 0; i<N; ++i)
	{
		Param& p = PC.GetParam(i);
		FELoadCurve* plc = p.GetLoadCurve();
		if (plc) AddLoadCurve(plc);
	}
}

//-----------------------------------------------------------------------------
void FEBioExport::Clear()
{
	m_pLC.clear();
}

//-----------------------------------------------------------------------------
bool FEBioExport::PrepareExport(FEProject& prj)
{
	Clear();

	FEModel& fem = prj.GetFEModel();

	// set nodal ID's
	GModel& model = fem.GetModel();
	int noff = 1;
	for (int i = 0; i<model.Objects(); ++i)
	{
		FECoreMesh* pm = model.Object(i)->GetFEMesh();
		if (pm == 0) return errf("Not all objects are meshed.");
		for (int j = 0; j<pm->Nodes(); ++j) pm->Node(j).m_nid = noff++;
	}

	// set material tags
	for (int i = 0; i<fem.Materials(); ++i) fem.GetMaterial(i)->m_ntag = i + 1;

	// build the load curve list
	BuildLoadCurveList(fem);

	return true;
}

//-----------------------------------------------------------------------------
void FEBioExport::BuildLoadCurveList(FEModel& fem)
{
	// must point load curves
	for (int j = 0; j<fem.Steps(); ++j)
	{
		FEAnalysisStep* pstep = dynamic_cast<FEAnalysisStep*>(fem.GetStep(j));
		if (pstep && pstep->GetSettings().bmust) AddLoadCurve(pstep->GetMustPointLoadCurve());
	}

	// material curves
	for (int i = 0; i<fem.Materials(); ++i)
	{
		GMaterial* pgm = fem.GetMaterial(i);
		FEMaterial* pm = pgm->GetMaterialProperties();
		if (pm)
		{
			AddLoadCurves(*pm);
			MultiMaterialCurves(pm);
		}
	}

	// see if any of the body force load curves are active
	for (int i = 0; i<fem.Steps(); ++i)
	{
		FEStep* pstep = fem.GetStep(i);
		for (int j = 0; j<pstep->BCs(); ++j)
		{
			FEBoundaryCondition* pbc = pstep->BC(j);
			if (pbc && pbc->IsActive()) AddLoadCurves(*pbc);
		}
	}

	// see if any of the body force load curves are active
	for (int i = 0; i<fem.Steps(); ++i)
	{
		FEStep* pstep = fem.GetStep(i);
		for (int j = 0; j<pstep->Loads(); ++j)
		{
			FEBoundaryCondition* pbc = pstep->Load(j);
			if (pbc && pbc->IsActive()) AddLoadCurves(*pbc);
		}
	}

	// add interface loadcurves
	for (int i = 0; i<fem.Steps(); ++i)
	{
		FEStep* pstep = fem.GetStep(i);
		for (int j = 0; j<pstep->Interfaces(); ++j)
		{
			FEInterface* pci = pstep->Interface(j);
			if (pci && pci->IsActive()) AddLoadCurves(*pci);
		}
	}

	// add connector loadcurves
	for (int i = 0; i<fem.Steps(); ++i)
	{
		FEStep* pstep = fem.GetStep(i);
		for (int j = 0; j<pstep->Connectors(); ++j)
		{
			FEConnector* pci = pstep->Connector(j);
			if (pci->IsActive()) AddLoadCurves(*pci);
		}
	}

	// see if there are any rigid body constraints
	for (int i = 0; i<fem.Steps(); ++i)
	{
		FEStep* ps = fem.GetStep(i);
		for (int j = 0; j<ps->RCs(); ++j)
		{
			FERigidPrescribed* prc = dynamic_cast<FERigidPrescribed*>(ps->RC(j));
			if (prc && prc->GetDOF() >= 0)
			{
				AddLoadCurve(prc->GetLoadCurve());
			}
		}
	}

	// spring loadcurves
	GModel& mdl = fem.GetModel();
	for (int i = 0; i<(int)mdl.DiscreteObjects(); ++i)
	{
		GDiscreteObject* pg = mdl.DiscreteObject(i);
		AddLoadCurves(*pg);
	}
}

//-----------------------------------------------------------------------------
void FEBioExport::MultiMaterialCurves(FEMaterial* pm)
{
	if (pm->Properties() > 0) {
		for (int k = 0; k<pm->Properties(); ++k)
		{
			FEMaterialProperty& mc = pm->GetProperty(k);
			for (int l = 0; l<mc.Size(); ++l)
			{
				FEMaterial* pmat = mc.GetMaterial(l);
				if (pmat)
				{
					AddLoadCurves(*pmat);
					MultiMaterialCurves(pmat);
				}
			}
		}
	}
	return;
}