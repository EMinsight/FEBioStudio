#include "stdafx.h"
#include "FEMeshData.h"

FEMeshData::FEMeshData(FEMeshData::DATA_CLASS dataClass)
	: m_dataClass(dataClass), m_pMesh(0), m_dataType(FEMeshData::DATA_TYPE::DATA_SCALAR)
{
}

FEMeshData::~FEMeshData()
{
}

void FEMeshData::SetName(const string& name)
{
	m_name = name;
}

const string& FEMeshData::GetName() const
{ 
	return m_name; 
}

FEMeshData::DATA_CLASS FEMeshData::GetDataClass() const
{
	return m_dataClass;
}

FEMeshData::DATA_TYPE FEMeshData::GetDataType() const
{
	return m_dataType;
}

FEMesh* FEMeshData::GetMesh() const
{
	return m_pMesh;
}

void FEMeshData::SetMesh(FEMesh* mesh)
{
	m_pMesh = const_cast<FEMesh*>(mesh);
}