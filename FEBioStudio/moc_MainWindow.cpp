/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMainWindow_t {
    QByteArrayData data[235];
    char stringdata0[5543];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMainWindow_t qt_meta_stringdata_CMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CMainWindow"
QT_MOC_LITERAL(1, 12, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(4, 60, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(5, 84, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(6, 110, 27), // "on_actionSnapShot_triggered"
QT_MOC_LITERAL(7, 138, 23), // "on_actionInfo_triggered"
QT_MOC_LITERAL(8, 162, 32), // "on_actionImportFEModel_triggered"
QT_MOC_LITERAL(9, 195, 32), // "on_actionExportFEModel_triggered"
QT_MOC_LITERAL(10, 228, 33), // "on_actionImportGeometry_trigg..."
QT_MOC_LITERAL(11, 262, 33), // "on_actionExportGeometry_trigg..."
QT_MOC_LITERAL(12, 296, 32), // "on_actionImportProject_triggered"
QT_MOC_LITERAL(13, 329, 32), // "on_actionExportProject_triggered"
QT_MOC_LITERAL(14, 362, 30), // "on_actionImportImage_triggered"
QT_MOC_LITERAL(15, 393, 29), // "on_actionConvertFeb_triggered"
QT_MOC_LITERAL(16, 423, 29), // "on_actionConvertGeo_triggered"
QT_MOC_LITERAL(17, 453, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(18, 477, 24), // "on_recentFiles_triggered"
QT_MOC_LITERAL(19, 502, 8), // "QAction*"
QT_MOC_LITERAL(20, 511, 6), // "action"
QT_MOC_LITERAL(21, 518, 26), // "on_recentFEFiles_triggered"
QT_MOC_LITERAL(22, 545, 28), // "on_recentGeomFiles_triggered"
QT_MOC_LITERAL(23, 574, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(24, 598, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(25, 622, 34), // "on_actionInvertSelection_trig..."
QT_MOC_LITERAL(26, 657, 33), // "on_actionClearSelection_trigg..."
QT_MOC_LITERAL(27, 691, 34), // "on_actionDeleteSelection_trig..."
QT_MOC_LITERAL(28, 726, 32), // "on_actionHideSelection_triggered"
QT_MOC_LITERAL(29, 759, 33), // "on_actionHideUnselected_trigg..."
QT_MOC_LITERAL(30, 793, 28), // "on_actionUnhideAll_triggered"
QT_MOC_LITERAL(31, 822, 23), // "on_actionFind_triggered"
QT_MOC_LITERAL(32, 846, 30), // "on_actionSelectRange_triggered"
QT_MOC_LITERAL(33, 877, 32), // "on_actionToggleVisible_triggered"
QT_MOC_LITERAL(34, 910, 32), // "on_actionNameSelection_triggered"
QT_MOC_LITERAL(35, 943, 28), // "on_actionTransform_triggered"
QT_MOC_LITERAL(36, 972, 36), // "on_actionCollapseTransform_tr..."
QT_MOC_LITERAL(37, 1009, 24), // "on_actionClone_triggered"
QT_MOC_LITERAL(38, 1034, 28), // "on_actionCloneGrid_triggered"
QT_MOC_LITERAL(39, 1063, 31), // "on_actionCloneRevolve_triggered"
QT_MOC_LITERAL(40, 1095, 24), // "on_actionMerge_triggered"
QT_MOC_LITERAL(41, 1120, 24), // "on_actionPurge_triggered"
QT_MOC_LITERAL(42, 1145, 25), // "on_actionDetach_triggered"
QT_MOC_LITERAL(43, 1171, 26), // "on_actionExtract_triggered"
QT_MOC_LITERAL(44, 1198, 30), // "on_actionEditProject_triggered"
QT_MOC_LITERAL(45, 1229, 29), // "on_actionFaceToElem_triggered"
QT_MOC_LITERAL(46, 1259, 24), // "on_actionAddBC_triggered"
QT_MOC_LITERAL(47, 1284, 31), // "on_actionAddNodalLoad_triggered"
QT_MOC_LITERAL(48, 1316, 30), // "on_actionAddSurfLoad_triggered"
QT_MOC_LITERAL(49, 1347, 30), // "on_actionAddBodyLoad_triggered"
QT_MOC_LITERAL(50, 1378, 24), // "on_actionAddIC_triggered"
QT_MOC_LITERAL(51, 1403, 29), // "on_actionAddContact_triggered"
QT_MOC_LITERAL(52, 1433, 32), // "on_actionAddConstraint_triggered"
QT_MOC_LITERAL(53, 1466, 37), // "on_actionAddRigidConstraint_t..."
QT_MOC_LITERAL(54, 1504, 36), // "on_actionAddRigidConnector_tr..."
QT_MOC_LITERAL(55, 1541, 30), // "on_actionAddMaterial_triggered"
QT_MOC_LITERAL(56, 1572, 26), // "on_actionAddStep_triggered"
QT_MOC_LITERAL(57, 1599, 30), // "on_actionAddReaction_triggered"
QT_MOC_LITERAL(58, 1630, 30), // "on_actionSoluteTable_triggered"
QT_MOC_LITERAL(59, 1661, 27), // "on_actionSBMTable_triggered"
QT_MOC_LITERAL(60, 1689, 30), // "on_actionCurveEditor_triggered"
QT_MOC_LITERAL(61, 1720, 32), // "on_actionMeshInspector_triggered"
QT_MOC_LITERAL(62, 1753, 38), // "on_actionElasticityConvertor_..."
QT_MOC_LITERAL(63, 1792, 26), // "on_actionKinemat_triggered"
QT_MOC_LITERAL(64, 1819, 26), // "on_actionPlotMix_triggered"
QT_MOC_LITERAL(65, 1846, 27), // "on_actionFEBioRun_triggered"
QT_MOC_LITERAL(66, 1874, 28), // "on_actionFEBioStop_triggered"
QT_MOC_LITERAL(67, 1903, 32), // "on_actionFEBioOptimize_triggered"
QT_MOC_LITERAL(68, 1936, 26), // "on_actionOptions_triggered"
QT_MOC_LITERAL(69, 1963, 28), // "on_actionLayerInfo_triggered"
QT_MOC_LITERAL(70, 1992, 27), // "on_actionPlaneCut_triggered"
QT_MOC_LITERAL(71, 2020, 30), // "on_actionMirrorPlane_triggered"
QT_MOC_LITERAL(72, 2051, 29), // "on_actionVectorPlot_triggered"
QT_MOC_LITERAL(73, 2081, 29), // "on_actionTensorPlot_triggered"
QT_MOC_LITERAL(74, 2111, 33), // "on_actionIsosurfacePlot_trigg..."
QT_MOC_LITERAL(75, 2145, 28), // "on_actionSlicePlot_triggered"
QT_MOC_LITERAL(76, 2174, 34), // "on_actionDisplacementMap_trig..."
QT_MOC_LITERAL(77, 2209, 33), // "on_actionStreamLinePlot_trigg..."
QT_MOC_LITERAL(78, 2243, 35), // "on_actionParticleFlowPlot_tri..."
QT_MOC_LITERAL(79, 2279, 33), // "on_actionVolumeFlowPlot_trigg..."
QT_MOC_LITERAL(80, 2313, 30), // "on_actionImageSlicer_triggered"
QT_MOC_LITERAL(81, 2344, 31), // "on_actionVolumeRender_triggered"
QT_MOC_LITERAL(82, 2376, 32), // "on_actionMarchingCubes_triggered"
QT_MOC_LITERAL(83, 2409, 24), // "on_actionGraph_triggered"
QT_MOC_LITERAL(84, 2434, 26), // "on_actionSummary_triggered"
QT_MOC_LITERAL(85, 2461, 24), // "on_actionStats_triggered"
QT_MOC_LITERAL(86, 2486, 28), // "on_actionIntegrate_triggered"
QT_MOC_LITERAL(87, 2515, 28), // "on_actionRecordNew_triggered"
QT_MOC_LITERAL(88, 2544, 30), // "on_actionRecordStart_triggered"
QT_MOC_LITERAL(89, 2575, 30), // "on_actionRecordPause_triggered"
QT_MOC_LITERAL(90, 2606, 29), // "on_actionRecordStop_triggered"
QT_MOC_LITERAL(91, 2636, 33), // "on_actionUndoViewChange_trigg..."
QT_MOC_LITERAL(92, 2670, 33), // "on_actionRedoViewChange_trigg..."
QT_MOC_LITERAL(93, 2704, 29), // "on_actionZoomSelect_triggered"
QT_MOC_LITERAL(94, 2734, 30), // "on_actionZoomExtents_triggered"
QT_MOC_LITERAL(95, 2765, 28), // "on_actionViewCapture_toggled"
QT_MOC_LITERAL(96, 2794, 8), // "bchecked"
QT_MOC_LITERAL(97, 2803, 22), // "on_actionOrtho_toggled"
QT_MOC_LITERAL(98, 2826, 1), // "b"
QT_MOC_LITERAL(99, 2828, 25), // "on_actionShowGrid_toggled"
QT_MOC_LITERAL(100, 2854, 30), // "on_actionShowMeshLines_toggled"
QT_MOC_LITERAL(101, 2885, 30), // "on_actionShowEdgeLines_toggled"
QT_MOC_LITERAL(102, 2916, 32), // "on_actionBackfaceCulling_toggled"
QT_MOC_LITERAL(103, 2949, 27), // "on_actionViewSmooth_toggled"
QT_MOC_LITERAL(104, 2977, 28), // "on_actionShowNormals_toggled"
QT_MOC_LITERAL(105, 3006, 27), // "on_actionShowFibers_toggled"
QT_MOC_LITERAL(106, 3034, 28), // "on_actionShowMatAxes_toggled"
QT_MOC_LITERAL(107, 3063, 29), // "on_actionShowDiscrete_toggled"
QT_MOC_LITERAL(108, 3093, 30), // "on_actionToggleLight_triggered"
QT_MOC_LITERAL(109, 3124, 24), // "on_actionFront_triggered"
QT_MOC_LITERAL(110, 3149, 23), // "on_actionBack_triggered"
QT_MOC_LITERAL(111, 3173, 23), // "on_actionLeft_triggered"
QT_MOC_LITERAL(112, 3197, 24), // "on_actionRight_triggered"
QT_MOC_LITERAL(113, 3222, 22), // "on_actionTop_triggered"
QT_MOC_LITERAL(114, 3245, 25), // "on_actionBottom_triggered"
QT_MOC_LITERAL(115, 3271, 26), // "on_actionWireframe_toggled"
QT_MOC_LITERAL(116, 3298, 25), // "on_actionSnap3D_triggered"
QT_MOC_LITERAL(117, 3324, 22), // "on_actionTrack_toggled"
QT_MOC_LITERAL(118, 3347, 29), // "on_actionViewVPSave_triggered"
QT_MOC_LITERAL(119, 3377, 29), // "on_actionViewVPPrev_triggered"
QT_MOC_LITERAL(120, 3407, 29), // "on_actionViewVPNext_triggered"
QT_MOC_LITERAL(121, 3437, 28), // "on_actionSyncViews_triggered"
QT_MOC_LITERAL(122, 3466, 29), // "on_actionOnlineHelp_triggered"
QT_MOC_LITERAL(123, 3496, 27), // "on_actionFEBioURL_triggered"
QT_MOC_LITERAL(124, 3524, 29), // "on_actionFEBioForum_triggered"
QT_MOC_LITERAL(125, 3554, 33), // "on_actionFEBioResources_trigg..."
QT_MOC_LITERAL(126, 3588, 28), // "on_actionFEBioPubs_triggered"
QT_MOC_LITERAL(127, 3617, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(128, 3642, 23), // "on_actionSelect_toggled"
QT_MOC_LITERAL(129, 3666, 26), // "on_actionTranslate_toggled"
QT_MOC_LITERAL(130, 3693, 23), // "on_actionRotate_toggled"
QT_MOC_LITERAL(131, 3717, 22), // "on_actionScale_toggled"
QT_MOC_LITERAL(132, 3740, 34), // "on_selectCoord_currentIndexCh..."
QT_MOC_LITERAL(133, 3775, 1), // "n"
QT_MOC_LITERAL(134, 3777, 30), // "on_actionSelectObjects_toggled"
QT_MOC_LITERAL(135, 3808, 28), // "on_actionSelectParts_toggled"
QT_MOC_LITERAL(136, 3837, 31), // "on_actionSelectSurfaces_toggled"
QT_MOC_LITERAL(137, 3869, 29), // "on_actionSelectCurves_toggled"
QT_MOC_LITERAL(138, 3899, 28), // "on_actionSelectNodes_toggled"
QT_MOC_LITERAL(139, 3928, 31), // "on_actionSelectDiscrete_toggled"
QT_MOC_LITERAL(140, 3960, 21), // "on_selectRect_toggled"
QT_MOC_LITERAL(141, 3982, 23), // "on_selectCircle_toggled"
QT_MOC_LITERAL(142, 4006, 21), // "on_selectFree_toggled"
QT_MOC_LITERAL(143, 4028, 30), // "on_actionMeasureTool_triggered"
QT_MOC_LITERAL(144, 4059, 33), // "on_selectData_currentValueCha..."
QT_MOC_LITERAL(145, 4093, 1), // "i"
QT_MOC_LITERAL(146, 4095, 21), // "on_actionPlay_toggled"
QT_MOC_LITERAL(147, 4117, 26), // "on_actionRefresh_triggered"
QT_MOC_LITERAL(148, 4144, 24), // "on_actionFirst_triggered"
QT_MOC_LITERAL(149, 4169, 23), // "on_actionPrev_triggered"
QT_MOC_LITERAL(150, 4193, 23), // "on_actionNext_triggered"
QT_MOC_LITERAL(151, 4217, 23), // "on_actionLast_triggered"
QT_MOC_LITERAL(152, 4241, 31), // "on_actionTimeSettings_triggered"
QT_MOC_LITERAL(153, 4273, 25), // "on_actionColorMap_toggled"
QT_MOC_LITERAL(154, 4299, 26), // "on_selectTime_valueChanged"
QT_MOC_LITERAL(155, 4326, 31), // "on_fontStyle_currentFontChanged"
QT_MOC_LITERAL(156, 4358, 4), // "font"
QT_MOC_LITERAL(157, 4363, 24), // "on_fontSize_valueChanged"
QT_MOC_LITERAL(158, 4388, 19), // "on_fontBold_toggled"
QT_MOC_LITERAL(159, 4408, 7), // "checked"
QT_MOC_LITERAL(160, 4416, 21), // "on_fontItalic_toggled"
QT_MOC_LITERAL(161, 4438, 29), // "on_actionProperties_triggered"
QT_MOC_LITERAL(162, 4468, 21), // "on_tab_currentChanged"
QT_MOC_LITERAL(163, 4490, 24), // "on_tab_tabCloseRequested"
QT_MOC_LITERAL(164, 4515, 24), // "OnPostObjectStateChanged"
QT_MOC_LITERAL(165, 4540, 24), // "OnPostObjectPropsChanged"
QT_MOC_LITERAL(166, 4565, 16), // "Post::CGLObject*"
QT_MOC_LITERAL(167, 4582, 2), // "po"
QT_MOC_LITERAL(168, 4585, 35), // "on_modelViewer_currentObjectC..."
QT_MOC_LITERAL(169, 4621, 9), // "FSObject*"
QT_MOC_LITERAL(170, 4631, 17), // "OnSelectMeshLayer"
QT_MOC_LITERAL(171, 4649, 2), // "ac"
QT_MOC_LITERAL(172, 4652, 30), // "OnSelectObjectTransparencyMode"
QT_MOC_LITERAL(173, 4683, 9), // "CloseView"
QT_MOC_LITERAL(174, 4693, 9), // "CPostDoc*"
QT_MOC_LITERAL(175, 4703, 7), // "postDoc"
QT_MOC_LITERAL(176, 4711, 15), // "SetCurrentState"
QT_MOC_LITERAL(177, 4727, 10), // "closeEvent"
QT_MOC_LITERAL(178, 4738, 12), // "QCloseEvent*"
QT_MOC_LITERAL(179, 4751, 2), // "ev"
QT_MOC_LITERAL(180, 4754, 13), // "keyPressEvent"
QT_MOC_LITERAL(181, 4768, 10), // "QKeyEvent*"
QT_MOC_LITERAL(182, 4779, 19), // "finishedReadingFile"
QT_MOC_LITERAL(183, 4799, 7), // "success"
QT_MOC_LITERAL(184, 4807, 11), // "errorString"
QT_MOC_LITERAL(185, 4819, 23), // "finishedReadingPostFile"
QT_MOC_LITERAL(186, 4843, 17), // "checkFileProgress"
QT_MOC_LITERAL(187, 4861, 21), // "checkPostFileProgress"
QT_MOC_LITERAL(188, 4883, 13), // "StopAnimation"
QT_MOC_LITERAL(189, 4897, 7), // "onTimer"
QT_MOC_LITERAL(190, 4905, 21), // "on_glview_pointPicked"
QT_MOC_LITERAL(191, 4927, 5), // "vec3d"
QT_MOC_LITERAL(192, 4933, 1), // "r"
QT_MOC_LITERAL(193, 4935, 26), // "on_glview_selectionChanged"
QT_MOC_LITERAL(194, 4962, 13), // "onRunFinished"
QT_MOC_LITERAL(195, 4976, 8), // "exitCode"
QT_MOC_LITERAL(196, 4985, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(197, 5006, 2), // "es"
QT_MOC_LITERAL(198, 5009, 11), // "onReadyRead"
QT_MOC_LITERAL(199, 5021, 15), // "onErrorOccurred"
QT_MOC_LITERAL(200, 5037, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(201, 5060, 3), // "err"
QT_MOC_LITERAL(202, 5064, 17), // "onExportMaterials"
QT_MOC_LITERAL(203, 5082, 18), // "vector<GMaterial*>"
QT_MOC_LITERAL(204, 5101, 7), // "matList"
QT_MOC_LITERAL(205, 5109, 20), // "onExportAllMaterials"
QT_MOC_LITERAL(206, 5130, 17), // "onImportMaterials"
QT_MOC_LITERAL(207, 5148, 18), // "DeleteAllMaterials"
QT_MOC_LITERAL(208, 5167, 11), // "DeleteAllBC"
QT_MOC_LITERAL(209, 5179, 14), // "DeleteAllLoads"
QT_MOC_LITERAL(210, 5194, 11), // "DeleteAllIC"
QT_MOC_LITERAL(211, 5206, 16), // "DeleteAllContact"
QT_MOC_LITERAL(212, 5223, 20), // "DeleteAllConstraints"
QT_MOC_LITERAL(213, 5244, 25), // "DeleteAllRigidConstraints"
QT_MOC_LITERAL(214, 5270, 24), // "DeleteAllRigidConnectors"
QT_MOC_LITERAL(215, 5295, 14), // "DeleteAllSteps"
QT_MOC_LITERAL(216, 5310, 9), // "GetGLView"
QT_MOC_LITERAL(217, 5320, 8), // "CGLView*"
QT_MOC_LITERAL(218, 5329, 14), // "changeViewMode"
QT_MOC_LITERAL(219, 5344, 9), // "View_Mode"
QT_MOC_LITERAL(220, 5354, 2), // "vm"
QT_MOC_LITERAL(221, 5357, 15), // "GetCurrentModel"
QT_MOC_LITERAL(222, 5373, 15), // "Post::CGLModel*"
QT_MOC_LITERAL(223, 5389, 17), // "UpdateFontToolbar"
QT_MOC_LITERAL(224, 5407, 11), // "RunFEBioJob"
QT_MOC_LITERAL(225, 5419, 10), // "CFEBioJob*"
QT_MOC_LITERAL(226, 5430, 3), // "job"
QT_MOC_LITERAL(227, 5434, 15), // "NextSSHFunction"
QT_MOC_LITERAL(228, 5450, 12), // "CSSHHandler*"
QT_MOC_LITERAL(229, 5463, 12), // "ShowProgress"
QT_MOC_LITERAL(230, 5476, 4), // "show"
QT_MOC_LITERAL(231, 5481, 7), // "message"
QT_MOC_LITERAL(232, 5489, 25), // "ShowIndeterminateProgress"
QT_MOC_LITERAL(233, 5515, 14), // "UpdateProgress"
QT_MOC_LITERAL(234, 5530, 12) // "DoModelCheck"

    },
    "CMainWindow\0on_actionNew_triggered\0\0"
    "on_actionOpen_triggered\0on_actionSave_triggered\0"
    "on_actionSaveAs_triggered\0"
    "on_actionSnapShot_triggered\0"
    "on_actionInfo_triggered\0"
    "on_actionImportFEModel_triggered\0"
    "on_actionExportFEModel_triggered\0"
    "on_actionImportGeometry_triggered\0"
    "on_actionExportGeometry_triggered\0"
    "on_actionImportProject_triggered\0"
    "on_actionExportProject_triggered\0"
    "on_actionImportImage_triggered\0"
    "on_actionConvertFeb_triggered\0"
    "on_actionConvertGeo_triggered\0"
    "on_actionExit_triggered\0"
    "on_recentFiles_triggered\0QAction*\0"
    "action\0on_recentFEFiles_triggered\0"
    "on_recentGeomFiles_triggered\0"
    "on_actionUndo_triggered\0on_actionRedo_triggered\0"
    "on_actionInvertSelection_triggered\0"
    "on_actionClearSelection_triggered\0"
    "on_actionDeleteSelection_triggered\0"
    "on_actionHideSelection_triggered\0"
    "on_actionHideUnselected_triggered\0"
    "on_actionUnhideAll_triggered\0"
    "on_actionFind_triggered\0"
    "on_actionSelectRange_triggered\0"
    "on_actionToggleVisible_triggered\0"
    "on_actionNameSelection_triggered\0"
    "on_actionTransform_triggered\0"
    "on_actionCollapseTransform_triggered\0"
    "on_actionClone_triggered\0"
    "on_actionCloneGrid_triggered\0"
    "on_actionCloneRevolve_triggered\0"
    "on_actionMerge_triggered\0"
    "on_actionPurge_triggered\0"
    "on_actionDetach_triggered\0"
    "on_actionExtract_triggered\0"
    "on_actionEditProject_triggered\0"
    "on_actionFaceToElem_triggered\0"
    "on_actionAddBC_triggered\0"
    "on_actionAddNodalLoad_triggered\0"
    "on_actionAddSurfLoad_triggered\0"
    "on_actionAddBodyLoad_triggered\0"
    "on_actionAddIC_triggered\0"
    "on_actionAddContact_triggered\0"
    "on_actionAddConstraint_triggered\0"
    "on_actionAddRigidConstraint_triggered\0"
    "on_actionAddRigidConnector_triggered\0"
    "on_actionAddMaterial_triggered\0"
    "on_actionAddStep_triggered\0"
    "on_actionAddReaction_triggered\0"
    "on_actionSoluteTable_triggered\0"
    "on_actionSBMTable_triggered\0"
    "on_actionCurveEditor_triggered\0"
    "on_actionMeshInspector_triggered\0"
    "on_actionElasticityConvertor_triggered\0"
    "on_actionKinemat_triggered\0"
    "on_actionPlotMix_triggered\0"
    "on_actionFEBioRun_triggered\0"
    "on_actionFEBioStop_triggered\0"
    "on_actionFEBioOptimize_triggered\0"
    "on_actionOptions_triggered\0"
    "on_actionLayerInfo_triggered\0"
    "on_actionPlaneCut_triggered\0"
    "on_actionMirrorPlane_triggered\0"
    "on_actionVectorPlot_triggered\0"
    "on_actionTensorPlot_triggered\0"
    "on_actionIsosurfacePlot_triggered\0"
    "on_actionSlicePlot_triggered\0"
    "on_actionDisplacementMap_triggered\0"
    "on_actionStreamLinePlot_triggered\0"
    "on_actionParticleFlowPlot_triggered\0"
    "on_actionVolumeFlowPlot_triggered\0"
    "on_actionImageSlicer_triggered\0"
    "on_actionVolumeRender_triggered\0"
    "on_actionMarchingCubes_triggered\0"
    "on_actionGraph_triggered\0"
    "on_actionSummary_triggered\0"
    "on_actionStats_triggered\0"
    "on_actionIntegrate_triggered\0"
    "on_actionRecordNew_triggered\0"
    "on_actionRecordStart_triggered\0"
    "on_actionRecordPause_triggered\0"
    "on_actionRecordStop_triggered\0"
    "on_actionUndoViewChange_triggered\0"
    "on_actionRedoViewChange_triggered\0"
    "on_actionZoomSelect_triggered\0"
    "on_actionZoomExtents_triggered\0"
    "on_actionViewCapture_toggled\0bchecked\0"
    "on_actionOrtho_toggled\0b\0"
    "on_actionShowGrid_toggled\0"
    "on_actionShowMeshLines_toggled\0"
    "on_actionShowEdgeLines_toggled\0"
    "on_actionBackfaceCulling_toggled\0"
    "on_actionViewSmooth_toggled\0"
    "on_actionShowNormals_toggled\0"
    "on_actionShowFibers_toggled\0"
    "on_actionShowMatAxes_toggled\0"
    "on_actionShowDiscrete_toggled\0"
    "on_actionToggleLight_triggered\0"
    "on_actionFront_triggered\0"
    "on_actionBack_triggered\0on_actionLeft_triggered\0"
    "on_actionRight_triggered\0"
    "on_actionTop_triggered\0on_actionBottom_triggered\0"
    "on_actionWireframe_toggled\0"
    "on_actionSnap3D_triggered\0"
    "on_actionTrack_toggled\0"
    "on_actionViewVPSave_triggered\0"
    "on_actionViewVPPrev_triggered\0"
    "on_actionViewVPNext_triggered\0"
    "on_actionSyncViews_triggered\0"
    "on_actionOnlineHelp_triggered\0"
    "on_actionFEBioURL_triggered\0"
    "on_actionFEBioForum_triggered\0"
    "on_actionFEBioResources_triggered\0"
    "on_actionFEBioPubs_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionSelect_toggled\0"
    "on_actionTranslate_toggled\0"
    "on_actionRotate_toggled\0on_actionScale_toggled\0"
    "on_selectCoord_currentIndexChanged\0n\0"
    "on_actionSelectObjects_toggled\0"
    "on_actionSelectParts_toggled\0"
    "on_actionSelectSurfaces_toggled\0"
    "on_actionSelectCurves_toggled\0"
    "on_actionSelectNodes_toggled\0"
    "on_actionSelectDiscrete_toggled\0"
    "on_selectRect_toggled\0on_selectCircle_toggled\0"
    "on_selectFree_toggled\0"
    "on_actionMeasureTool_triggered\0"
    "on_selectData_currentValueChanged\0i\0"
    "on_actionPlay_toggled\0on_actionRefresh_triggered\0"
    "on_actionFirst_triggered\0"
    "on_actionPrev_triggered\0on_actionNext_triggered\0"
    "on_actionLast_triggered\0"
    "on_actionTimeSettings_triggered\0"
    "on_actionColorMap_toggled\0"
    "on_selectTime_valueChanged\0"
    "on_fontStyle_currentFontChanged\0font\0"
    "on_fontSize_valueChanged\0on_fontBold_toggled\0"
    "checked\0on_fontItalic_toggled\0"
    "on_actionProperties_triggered\0"
    "on_tab_currentChanged\0on_tab_tabCloseRequested\0"
    "OnPostObjectStateChanged\0"
    "OnPostObjectPropsChanged\0Post::CGLObject*\0"
    "po\0on_modelViewer_currentObjectChanged\0"
    "FSObject*\0OnSelectMeshLayer\0ac\0"
    "OnSelectObjectTransparencyMode\0CloseView\0"
    "CPostDoc*\0postDoc\0SetCurrentState\0"
    "closeEvent\0QCloseEvent*\0ev\0keyPressEvent\0"
    "QKeyEvent*\0finishedReadingFile\0success\0"
    "errorString\0finishedReadingPostFile\0"
    "checkFileProgress\0checkPostFileProgress\0"
    "StopAnimation\0onTimer\0on_glview_pointPicked\0"
    "vec3d\0r\0on_glview_selectionChanged\0"
    "onRunFinished\0exitCode\0QProcess::ExitStatus\0"
    "es\0onReadyRead\0onErrorOccurred\0"
    "QProcess::ProcessError\0err\0onExportMaterials\0"
    "vector<GMaterial*>\0matList\0"
    "onExportAllMaterials\0onImportMaterials\0"
    "DeleteAllMaterials\0DeleteAllBC\0"
    "DeleteAllLoads\0DeleteAllIC\0DeleteAllContact\0"
    "DeleteAllConstraints\0DeleteAllRigidConstraints\0"
    "DeleteAllRigidConnectors\0DeleteAllSteps\0"
    "GetGLView\0CGLView*\0changeViewMode\0"
    "View_Mode\0vm\0GetCurrentModel\0"
    "Post::CGLModel*\0UpdateFontToolbar\0"
    "RunFEBioJob\0CFEBioJob*\0job\0NextSSHFunction\0"
    "CSSHHandler*\0ShowProgress\0show\0message\0"
    "ShowIndeterminateProgress\0UpdateProgress\0"
    "DoModelCheck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     199,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0, 1009,    2, 0x0a /* Public */,
       3,    0, 1010,    2, 0x0a /* Public */,
       4,    0, 1011,    2, 0x0a /* Public */,
       5,    0, 1012,    2, 0x0a /* Public */,
       6,    0, 1013,    2, 0x0a /* Public */,
       7,    0, 1014,    2, 0x0a /* Public */,
       8,    0, 1015,    2, 0x0a /* Public */,
       9,    0, 1016,    2, 0x0a /* Public */,
      10,    0, 1017,    2, 0x0a /* Public */,
      11,    0, 1018,    2, 0x0a /* Public */,
      12,    0, 1019,    2, 0x0a /* Public */,
      13,    0, 1020,    2, 0x0a /* Public */,
      14,    0, 1021,    2, 0x0a /* Public */,
      15,    0, 1022,    2, 0x0a /* Public */,
      16,    0, 1023,    2, 0x0a /* Public */,
      17,    0, 1024,    2, 0x0a /* Public */,
      18,    1, 1025,    2, 0x0a /* Public */,
      21,    1, 1028,    2, 0x0a /* Public */,
      22,    1, 1031,    2, 0x0a /* Public */,
      23,    0, 1034,    2, 0x0a /* Public */,
      24,    0, 1035,    2, 0x0a /* Public */,
      25,    0, 1036,    2, 0x0a /* Public */,
      26,    0, 1037,    2, 0x0a /* Public */,
      27,    0, 1038,    2, 0x0a /* Public */,
      28,    0, 1039,    2, 0x0a /* Public */,
      29,    0, 1040,    2, 0x0a /* Public */,
      30,    0, 1041,    2, 0x0a /* Public */,
      31,    0, 1042,    2, 0x0a /* Public */,
      32,    0, 1043,    2, 0x0a /* Public */,
      33,    0, 1044,    2, 0x0a /* Public */,
      34,    0, 1045,    2, 0x0a /* Public */,
      35,    0, 1046,    2, 0x0a /* Public */,
      36,    0, 1047,    2, 0x0a /* Public */,
      37,    0, 1048,    2, 0x0a /* Public */,
      38,    0, 1049,    2, 0x0a /* Public */,
      39,    0, 1050,    2, 0x0a /* Public */,
      40,    0, 1051,    2, 0x0a /* Public */,
      41,    0, 1052,    2, 0x0a /* Public */,
      42,    0, 1053,    2, 0x0a /* Public */,
      43,    0, 1054,    2, 0x0a /* Public */,
      44,    0, 1055,    2, 0x0a /* Public */,
      45,    0, 1056,    2, 0x0a /* Public */,
      46,    0, 1057,    2, 0x0a /* Public */,
      47,    0, 1058,    2, 0x0a /* Public */,
      48,    0, 1059,    2, 0x0a /* Public */,
      49,    0, 1060,    2, 0x0a /* Public */,
      50,    0, 1061,    2, 0x0a /* Public */,
      51,    0, 1062,    2, 0x0a /* Public */,
      52,    0, 1063,    2, 0x0a /* Public */,
      53,    0, 1064,    2, 0x0a /* Public */,
      54,    0, 1065,    2, 0x0a /* Public */,
      55,    0, 1066,    2, 0x0a /* Public */,
      56,    0, 1067,    2, 0x0a /* Public */,
      57,    0, 1068,    2, 0x0a /* Public */,
      58,    0, 1069,    2, 0x0a /* Public */,
      59,    0, 1070,    2, 0x0a /* Public */,
      60,    0, 1071,    2, 0x0a /* Public */,
      61,    0, 1072,    2, 0x0a /* Public */,
      62,    0, 1073,    2, 0x0a /* Public */,
      63,    0, 1074,    2, 0x0a /* Public */,
      64,    0, 1075,    2, 0x0a /* Public */,
      65,    0, 1076,    2, 0x0a /* Public */,
      66,    0, 1077,    2, 0x0a /* Public */,
      67,    0, 1078,    2, 0x0a /* Public */,
      68,    0, 1079,    2, 0x0a /* Public */,
      69,    0, 1080,    2, 0x0a /* Public */,
      70,    0, 1081,    2, 0x0a /* Public */,
      71,    0, 1082,    2, 0x0a /* Public */,
      72,    0, 1083,    2, 0x0a /* Public */,
      73,    0, 1084,    2, 0x0a /* Public */,
      74,    0, 1085,    2, 0x0a /* Public */,
      75,    0, 1086,    2, 0x0a /* Public */,
      76,    0, 1087,    2, 0x0a /* Public */,
      77,    0, 1088,    2, 0x0a /* Public */,
      78,    0, 1089,    2, 0x0a /* Public */,
      79,    0, 1090,    2, 0x0a /* Public */,
      80,    0, 1091,    2, 0x0a /* Public */,
      81,    0, 1092,    2, 0x0a /* Public */,
      82,    0, 1093,    2, 0x0a /* Public */,
      83,    0, 1094,    2, 0x0a /* Public */,
      84,    0, 1095,    2, 0x0a /* Public */,
      85,    0, 1096,    2, 0x0a /* Public */,
      86,    0, 1097,    2, 0x0a /* Public */,
      87,    0, 1098,    2, 0x0a /* Public */,
      88,    0, 1099,    2, 0x0a /* Public */,
      89,    0, 1100,    2, 0x0a /* Public */,
      90,    0, 1101,    2, 0x0a /* Public */,
      91,    0, 1102,    2, 0x0a /* Public */,
      92,    0, 1103,    2, 0x0a /* Public */,
      93,    0, 1104,    2, 0x0a /* Public */,
      94,    0, 1105,    2, 0x0a /* Public */,
      95,    1, 1106,    2, 0x0a /* Public */,
      97,    1, 1109,    2, 0x0a /* Public */,
      99,    1, 1112,    2, 0x0a /* Public */,
     100,    1, 1115,    2, 0x0a /* Public */,
     101,    1, 1118,    2, 0x0a /* Public */,
     102,    1, 1121,    2, 0x0a /* Public */,
     103,    1, 1124,    2, 0x0a /* Public */,
     104,    1, 1127,    2, 0x0a /* Public */,
     105,    1, 1130,    2, 0x0a /* Public */,
     106,    1, 1133,    2, 0x0a /* Public */,
     107,    1, 1136,    2, 0x0a /* Public */,
     108,    0, 1139,    2, 0x0a /* Public */,
     109,    0, 1140,    2, 0x0a /* Public */,
     110,    0, 1141,    2, 0x0a /* Public */,
     111,    0, 1142,    2, 0x0a /* Public */,
     112,    0, 1143,    2, 0x0a /* Public */,
     113,    0, 1144,    2, 0x0a /* Public */,
     114,    0, 1145,    2, 0x0a /* Public */,
     115,    1, 1146,    2, 0x0a /* Public */,
     116,    0, 1149,    2, 0x0a /* Public */,
     117,    1, 1150,    2, 0x0a /* Public */,
     118,    0, 1153,    2, 0x0a /* Public */,
     119,    0, 1154,    2, 0x0a /* Public */,
     120,    0, 1155,    2, 0x0a /* Public */,
     121,    0, 1156,    2, 0x0a /* Public */,
     122,    0, 1157,    2, 0x0a /* Public */,
     123,    0, 1158,    2, 0x0a /* Public */,
     124,    0, 1159,    2, 0x0a /* Public */,
     125,    0, 1160,    2, 0x0a /* Public */,
     126,    0, 1161,    2, 0x0a /* Public */,
     127,    0, 1162,    2, 0x0a /* Public */,
     128,    1, 1163,    2, 0x0a /* Public */,
     129,    1, 1166,    2, 0x0a /* Public */,
     130,    1, 1169,    2, 0x0a /* Public */,
     131,    1, 1172,    2, 0x0a /* Public */,
     132,    1, 1175,    2, 0x0a /* Public */,
     134,    1, 1178,    2, 0x0a /* Public */,
     135,    1, 1181,    2, 0x0a /* Public */,
     136,    1, 1184,    2, 0x0a /* Public */,
     137,    1, 1187,    2, 0x0a /* Public */,
     138,    1, 1190,    2, 0x0a /* Public */,
     139,    1, 1193,    2, 0x0a /* Public */,
     140,    1, 1196,    2, 0x0a /* Public */,
     141,    1, 1199,    2, 0x0a /* Public */,
     142,    1, 1202,    2, 0x0a /* Public */,
     143,    0, 1205,    2, 0x0a /* Public */,
     144,    1, 1206,    2, 0x0a /* Public */,
     146,    1, 1209,    2, 0x0a /* Public */,
     147,    0, 1212,    2, 0x0a /* Public */,
     148,    0, 1213,    2, 0x0a /* Public */,
     149,    0, 1214,    2, 0x0a /* Public */,
     150,    0, 1215,    2, 0x0a /* Public */,
     151,    0, 1216,    2, 0x0a /* Public */,
     152,    0, 1217,    2, 0x0a /* Public */,
     153,    1, 1218,    2, 0x0a /* Public */,
     154,    1, 1221,    2, 0x0a /* Public */,
     155,    1, 1224,    2, 0x0a /* Public */,
     157,    1, 1227,    2, 0x0a /* Public */,
     158,    1, 1230,    2, 0x0a /* Public */,
     160,    1, 1233,    2, 0x0a /* Public */,
     161,    0, 1236,    2, 0x0a /* Public */,
     162,    1, 1237,    2, 0x0a /* Public */,
     163,    1, 1240,    2, 0x0a /* Public */,
     164,    0, 1243,    2, 0x0a /* Public */,
     165,    1, 1244,    2, 0x0a /* Public */,
     168,    1, 1247,    2, 0x0a /* Public */,
     170,    1, 1250,    2, 0x0a /* Public */,
     172,    1, 1253,    2, 0x0a /* Public */,
     173,    1, 1256,    2, 0x0a /* Public */,
     173,    1, 1259,    2, 0x0a /* Public */,
     176,    1, 1262,    2, 0x0a /* Public */,
     177,    1, 1265,    2, 0x0a /* Public */,
     180,    1, 1268,    2, 0x0a /* Public */,
     182,    2, 1271,    2, 0x0a /* Public */,
     185,    2, 1276,    2, 0x0a /* Public */,
     186,    0, 1281,    2, 0x0a /* Public */,
     187,    0, 1282,    2, 0x0a /* Public */,
     188,    0, 1283,    2, 0x0a /* Public */,
     189,    0, 1284,    2, 0x0a /* Public */,
     190,    1, 1285,    2, 0x0a /* Public */,
     193,    0, 1288,    2, 0x0a /* Public */,
     194,    2, 1289,    2, 0x0a /* Public */,
     198,    0, 1294,    2, 0x0a /* Public */,
     199,    1, 1295,    2, 0x0a /* Public */,
     202,    1, 1298,    2, 0x0a /* Public */,
     205,    0, 1301,    2, 0x0a /* Public */,
     206,    0, 1302,    2, 0x0a /* Public */,
     207,    0, 1303,    2, 0x0a /* Public */,
     208,    0, 1304,    2, 0x0a /* Public */,
     209,    0, 1305,    2, 0x0a /* Public */,
     210,    0, 1306,    2, 0x0a /* Public */,
     211,    0, 1307,    2, 0x0a /* Public */,
     212,    0, 1308,    2, 0x0a /* Public */,
     213,    0, 1309,    2, 0x0a /* Public */,
     214,    0, 1310,    2, 0x0a /* Public */,
     215,    0, 1311,    2, 0x0a /* Public */,
     216,    0, 1312,    2, 0x0a /* Public */,
     218,    1, 1313,    2, 0x0a /* Public */,
     221,    0, 1316,    2, 0x0a /* Public */,
     223,    0, 1317,    2, 0x0a /* Public */,
     224,    1, 1318,    2, 0x0a /* Public */,
     227,    1, 1321,    2, 0x0a /* Public */,
     229,    2, 1324,    2, 0x0a /* Public */,
     229,    1, 1329,    2, 0x2a /* Public | MethodCloned */,
     232,    2, 1332,    2, 0x0a /* Public */,
     232,    1, 1337,    2, 0x2a /* Public | MethodCloned */,
     233,    1, 1340,    2, 0x0a /* Public */,
     234,    0, 1343,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   96,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   96,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Int,  133,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  145,
    QMetaType::Void, QMetaType::Bool,   96,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   96,
    QMetaType::Void, QMetaType::Int,  133,
    QMetaType::Void, QMetaType::QFont,  156,
    QMetaType::Void, QMetaType::Int,  145,
    QMetaType::Void, QMetaType::Bool,  159,
    QMetaType::Void, QMetaType::Bool,   96,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  133,
    QMetaType::Void, QMetaType::Int,  133,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 166,  167,
    QMetaType::Void, 0x80000000 | 169,  167,
    QMetaType::Void, 0x80000000 | 19,  171,
    QMetaType::Void, 0x80000000 | 19,  171,
    QMetaType::Void, QMetaType::Int,  133,
    QMetaType::Void, 0x80000000 | 174,  175,
    QMetaType::Void, QMetaType::Int,  133,
    QMetaType::Void, 0x80000000 | 178,  179,
    QMetaType::Void, 0x80000000 | 181,  179,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,  183,  184,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,  183,  184,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 191,  192,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 196,  195,  197,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 200,  201,
    QMetaType::Void, 0x80000000 | 203,  204,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 217,
    QMetaType::Void, 0x80000000 | 219,  220,
    0x80000000 | 222,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 225,  226,
    QMetaType::Void, 0x80000000 | 228,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,  230,  231,
    QMetaType::Void, QMetaType::Bool,  230,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,  230,  231,
    QMetaType::Void, QMetaType::Bool,  230,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Bool,

       0        // eod
};

void CMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionNew_triggered(); break;
        case 1: _t->on_actionOpen_triggered(); break;
        case 2: _t->on_actionSave_triggered(); break;
        case 3: _t->on_actionSaveAs_triggered(); break;
        case 4: _t->on_actionSnapShot_triggered(); break;
        case 5: _t->on_actionInfo_triggered(); break;
        case 6: _t->on_actionImportFEModel_triggered(); break;
        case 7: _t->on_actionExportFEModel_triggered(); break;
        case 8: _t->on_actionImportGeometry_triggered(); break;
        case 9: _t->on_actionExportGeometry_triggered(); break;
        case 10: _t->on_actionImportProject_triggered(); break;
        case 11: _t->on_actionExportProject_triggered(); break;
        case 12: _t->on_actionImportImage_triggered(); break;
        case 13: _t->on_actionConvertFeb_triggered(); break;
        case 14: _t->on_actionConvertGeo_triggered(); break;
        case 15: _t->on_actionExit_triggered(); break;
        case 16: _t->on_recentFiles_triggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 17: _t->on_recentFEFiles_triggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 18: _t->on_recentGeomFiles_triggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 19: _t->on_actionUndo_triggered(); break;
        case 20: _t->on_actionRedo_triggered(); break;
        case 21: _t->on_actionInvertSelection_triggered(); break;
        case 22: _t->on_actionClearSelection_triggered(); break;
        case 23: _t->on_actionDeleteSelection_triggered(); break;
        case 24: _t->on_actionHideSelection_triggered(); break;
        case 25: _t->on_actionHideUnselected_triggered(); break;
        case 26: _t->on_actionUnhideAll_triggered(); break;
        case 27: _t->on_actionFind_triggered(); break;
        case 28: _t->on_actionSelectRange_triggered(); break;
        case 29: _t->on_actionToggleVisible_triggered(); break;
        case 30: _t->on_actionNameSelection_triggered(); break;
        case 31: _t->on_actionTransform_triggered(); break;
        case 32: _t->on_actionCollapseTransform_triggered(); break;
        case 33: _t->on_actionClone_triggered(); break;
        case 34: _t->on_actionCloneGrid_triggered(); break;
        case 35: _t->on_actionCloneRevolve_triggered(); break;
        case 36: _t->on_actionMerge_triggered(); break;
        case 37: _t->on_actionPurge_triggered(); break;
        case 38: _t->on_actionDetach_triggered(); break;
        case 39: _t->on_actionExtract_triggered(); break;
        case 40: _t->on_actionEditProject_triggered(); break;
        case 41: _t->on_actionFaceToElem_triggered(); break;
        case 42: _t->on_actionAddBC_triggered(); break;
        case 43: _t->on_actionAddNodalLoad_triggered(); break;
        case 44: _t->on_actionAddSurfLoad_triggered(); break;
        case 45: _t->on_actionAddBodyLoad_triggered(); break;
        case 46: _t->on_actionAddIC_triggered(); break;
        case 47: _t->on_actionAddContact_triggered(); break;
        case 48: _t->on_actionAddConstraint_triggered(); break;
        case 49: _t->on_actionAddRigidConstraint_triggered(); break;
        case 50: _t->on_actionAddRigidConnector_triggered(); break;
        case 51: _t->on_actionAddMaterial_triggered(); break;
        case 52: _t->on_actionAddStep_triggered(); break;
        case 53: _t->on_actionAddReaction_triggered(); break;
        case 54: _t->on_actionSoluteTable_triggered(); break;
        case 55: _t->on_actionSBMTable_triggered(); break;
        case 56: _t->on_actionCurveEditor_triggered(); break;
        case 57: _t->on_actionMeshInspector_triggered(); break;
        case 58: _t->on_actionElasticityConvertor_triggered(); break;
        case 59: _t->on_actionKinemat_triggered(); break;
        case 60: _t->on_actionPlotMix_triggered(); break;
        case 61: _t->on_actionFEBioRun_triggered(); break;
        case 62: _t->on_actionFEBioStop_triggered(); break;
        case 63: _t->on_actionFEBioOptimize_triggered(); break;
        case 64: _t->on_actionOptions_triggered(); break;
        case 65: _t->on_actionLayerInfo_triggered(); break;
        case 66: _t->on_actionPlaneCut_triggered(); break;
        case 67: _t->on_actionMirrorPlane_triggered(); break;
        case 68: _t->on_actionVectorPlot_triggered(); break;
        case 69: _t->on_actionTensorPlot_triggered(); break;
        case 70: _t->on_actionIsosurfacePlot_triggered(); break;
        case 71: _t->on_actionSlicePlot_triggered(); break;
        case 72: _t->on_actionDisplacementMap_triggered(); break;
        case 73: _t->on_actionStreamLinePlot_triggered(); break;
        case 74: _t->on_actionParticleFlowPlot_triggered(); break;
        case 75: _t->on_actionVolumeFlowPlot_triggered(); break;
        case 76: _t->on_actionImageSlicer_triggered(); break;
        case 77: _t->on_actionVolumeRender_triggered(); break;
        case 78: _t->on_actionMarchingCubes_triggered(); break;
        case 79: _t->on_actionGraph_triggered(); break;
        case 80: _t->on_actionSummary_triggered(); break;
        case 81: _t->on_actionStats_triggered(); break;
        case 82: _t->on_actionIntegrate_triggered(); break;
        case 83: _t->on_actionRecordNew_triggered(); break;
        case 84: _t->on_actionRecordStart_triggered(); break;
        case 85: _t->on_actionRecordPause_triggered(); break;
        case 86: _t->on_actionRecordStop_triggered(); break;
        case 87: _t->on_actionUndoViewChange_triggered(); break;
        case 88: _t->on_actionRedoViewChange_triggered(); break;
        case 89: _t->on_actionZoomSelect_triggered(); break;
        case 90: _t->on_actionZoomExtents_triggered(); break;
        case 91: _t->on_actionViewCapture_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 92: _t->on_actionOrtho_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 93: _t->on_actionShowGrid_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 94: _t->on_actionShowMeshLines_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 95: _t->on_actionShowEdgeLines_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 96: _t->on_actionBackfaceCulling_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 97: _t->on_actionViewSmooth_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 98: _t->on_actionShowNormals_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 99: _t->on_actionShowFibers_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 100: _t->on_actionShowMatAxes_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 101: _t->on_actionShowDiscrete_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 102: _t->on_actionToggleLight_triggered(); break;
        case 103: _t->on_actionFront_triggered(); break;
        case 104: _t->on_actionBack_triggered(); break;
        case 105: _t->on_actionLeft_triggered(); break;
        case 106: _t->on_actionRight_triggered(); break;
        case 107: _t->on_actionTop_triggered(); break;
        case 108: _t->on_actionBottom_triggered(); break;
        case 109: _t->on_actionWireframe_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 110: _t->on_actionSnap3D_triggered(); break;
        case 111: _t->on_actionTrack_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 112: _t->on_actionViewVPSave_triggered(); break;
        case 113: _t->on_actionViewVPPrev_triggered(); break;
        case 114: _t->on_actionViewVPNext_triggered(); break;
        case 115: _t->on_actionSyncViews_triggered(); break;
        case 116: _t->on_actionOnlineHelp_triggered(); break;
        case 117: _t->on_actionFEBioURL_triggered(); break;
        case 118: _t->on_actionFEBioForum_triggered(); break;
        case 119: _t->on_actionFEBioResources_triggered(); break;
        case 120: _t->on_actionFEBioPubs_triggered(); break;
        case 121: _t->on_actionAbout_triggered(); break;
        case 122: _t->on_actionSelect_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 123: _t->on_actionTranslate_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 124: _t->on_actionRotate_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 125: _t->on_actionScale_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 126: _t->on_selectCoord_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 127: _t->on_actionSelectObjects_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 128: _t->on_actionSelectParts_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 129: _t->on_actionSelectSurfaces_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 130: _t->on_actionSelectCurves_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 131: _t->on_actionSelectNodes_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 132: _t->on_actionSelectDiscrete_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 133: _t->on_selectRect_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 134: _t->on_selectCircle_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 135: _t->on_selectFree_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 136: _t->on_actionMeasureTool_triggered(); break;
        case 137: _t->on_selectData_currentValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 138: _t->on_actionPlay_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 139: _t->on_actionRefresh_triggered(); break;
        case 140: _t->on_actionFirst_triggered(); break;
        case 141: _t->on_actionPrev_triggered(); break;
        case 142: _t->on_actionNext_triggered(); break;
        case 143: _t->on_actionLast_triggered(); break;
        case 144: _t->on_actionTimeSettings_triggered(); break;
        case 145: _t->on_actionColorMap_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 146: _t->on_selectTime_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 147: _t->on_fontStyle_currentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 148: _t->on_fontSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 149: _t->on_fontBold_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 150: _t->on_fontItalic_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 151: _t->on_actionProperties_triggered(); break;
        case 152: _t->on_tab_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 153: _t->on_tab_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 154: _t->OnPostObjectStateChanged(); break;
        case 155: _t->OnPostObjectPropsChanged((*reinterpret_cast< Post::CGLObject*(*)>(_a[1]))); break;
        case 156: _t->on_modelViewer_currentObjectChanged((*reinterpret_cast< FSObject*(*)>(_a[1]))); break;
        case 157: _t->OnSelectMeshLayer((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 158: _t->OnSelectObjectTransparencyMode((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 159: _t->CloseView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 160: _t->CloseView((*reinterpret_cast< CPostDoc*(*)>(_a[1]))); break;
        case 161: _t->SetCurrentState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 162: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 163: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 164: _t->finishedReadingFile((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 165: _t->finishedReadingPostFile((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 166: _t->checkFileProgress(); break;
        case 167: _t->checkPostFileProgress(); break;
        case 168: _t->StopAnimation(); break;
        case 169: _t->onTimer(); break;
        case 170: _t->on_glview_pointPicked((*reinterpret_cast< const vec3d(*)>(_a[1]))); break;
        case 171: _t->on_glview_selectionChanged(); break;
        case 172: _t->onRunFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 173: _t->onReadyRead(); break;
        case 174: _t->onErrorOccurred((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 175: _t->onExportMaterials((*reinterpret_cast< const vector<GMaterial*>(*)>(_a[1]))); break;
        case 176: _t->onExportAllMaterials(); break;
        case 177: _t->onImportMaterials(); break;
        case 178: _t->DeleteAllMaterials(); break;
        case 179: _t->DeleteAllBC(); break;
        case 180: _t->DeleteAllLoads(); break;
        case 181: _t->DeleteAllIC(); break;
        case 182: _t->DeleteAllContact(); break;
        case 183: _t->DeleteAllConstraints(); break;
        case 184: _t->DeleteAllRigidConstraints(); break;
        case 185: _t->DeleteAllRigidConnectors(); break;
        case 186: _t->DeleteAllSteps(); break;
        case 187: { CGLView* _r = _t->GetGLView();
            if (_a[0]) *reinterpret_cast< CGLView**>(_a[0]) = std::move(_r); }  break;
        case 188: _t->changeViewMode((*reinterpret_cast< View_Mode(*)>(_a[1]))); break;
        case 189: { Post::CGLModel* _r = _t->GetCurrentModel();
            if (_a[0]) *reinterpret_cast< Post::CGLModel**>(_a[0]) = std::move(_r); }  break;
        case 190: _t->UpdateFontToolbar(); break;
        case 191: _t->RunFEBioJob((*reinterpret_cast< CFEBioJob*(*)>(_a[1]))); break;
        case 192: _t->NextSSHFunction((*reinterpret_cast< CSSHHandler*(*)>(_a[1]))); break;
        case 193: _t->ShowProgress((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 194: _t->ShowProgress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 195: _t->ShowIndeterminateProgress((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 196: _t->ShowIndeterminateProgress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 197: _t->UpdateProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 198: { bool _r = _t->DoModelCheck();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CMainWindow.data,
    qt_meta_data_CMainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 199)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 199;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 199)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 199;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
