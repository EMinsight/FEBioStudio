/*This file is part of the FEBio Studio source code and is licensed under the MIT license
listed below.

See Copyright-FEBio-Studio.txt for details.

Copyright (c) 2021 University of Utah, The Trustees of Columbia University in
the City of New York, and others.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#pragma once
#include "GObject.h"

class FECurveMesh;

// An object build from a FECurveMesh
class GCurveMeshObject : public GObject
{
public:
	// constructor
	GCurveMeshObject(FECurveMesh* pm = 0);

	// updates the GObject data structures based on the curve mesh
	void Update();

	// return the curve mesh
	FECurveMesh* GetCurveMesh();

	// get the mesh of an edge
	// (overridden from base class)
	FECurveMesh* GetFECurveMesh(int edgeId) override;

	// Serialization
	void Save(OArchive& ar) override;
	void Load(IArchive& ar) override;

	FELineMesh* GetEditableLineMesh() override;

	void ClearMesh();

private:
	FECurveMesh*	m_curve;
};
