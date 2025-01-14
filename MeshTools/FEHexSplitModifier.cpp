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

#include "stdafx.h"
#include "FESplitModifier.h"
#include <MeshLib/FEFaceEdgeList.h>

FEHexSplitModifier::FEHexSplitModifier() : FEModifier("Split")
{
	m_smoothSurface = false;
}

void FEHexSplitModifier::DoSurfaceSmoothing(bool b)
{
	m_smoothSurface = b;
}

FEMesh* FEHexSplitModifier::Apply(FEMesh* pm)
{
	// make sure we are dealing with a hex mesh
	if (pm->IsType(FE_HEX8) == false) return 0;

	// build the edge table of the mesh (each edge will add a node)
	FEEdgeList ET(*pm);
	FEElementEdgeList EET(*pm, ET);

	// build the face table (each face will add a node)
	FEFaceTable FT(*pm);
	FEElementFaceList EFL(*pm, FT);

	// get the mesh item counts
	int NN0 = pm->Nodes();
	int NC0 = ET.size();
	int NF0 = FT.size();
	int NE0 = pm->Elements();

	// each node, edge, face, and element will create a new node
	int NN1 = NN0 + NC0 + NF0 + NE0;

	// each element will be split in eight
	int NE1 = 8*NE0;

	// create new mesh
	FEMesh* pmnew = new FEMesh;
	pmnew->Create(NN1, NE1);

	// build face-edge table
	FEFaceEdgeList FET(*pm, ET);

	// assign nodes
	int n = 0;
	for (int i=0; i<NN0; ++i, ++n)
	{
		FENode& n1 = pmnew->Node(n);
		FENode& n0 = pm->Node(i);
		n1 = n0;
	}

	for (int i=0; i<NC0; ++i, ++n)
	{
		FENode& n1 = pmnew->Node(n);

		pair<int,int>& edge = ET[i];
		FENode& na = pm->Node(edge.first);
		FENode& nb = pm->Node(edge.second);

		n1.r = (na.r + nb.r)*0.5;
	}

	for (int i=0; i<NF0; ++i, ++n)
	{
		FENode& n1 = pmnew->Node(n);

		FEFace& face = FT[i];

		vec3d r0 = pm->Node(face.n[0]).r;
		vec3d r1 = pm->Node(face.n[1]).r;
		vec3d r2 = pm->Node(face.n[2]).r;
		vec3d r3 = pm->Node(face.n[3]).r;

		n1.r = (r0 + r1 + r2 + r3)*0.25;
	}

	for (int i=0; i<NE0; ++i, ++n)
	{
		FENode& n1 = pmnew->Node(n);

		FEElement& el = pm->Element(i);
		vec3d r(0,0,0);
		for (int j=0; j<8; ++j) r += pm->Node(el.m_node[j]).r;
		r *= 0.125;

		n1.r = r;
	}

	const int LUT[8][8] = {
	{  0,  8, 24, 11, 16, 20, 26, 23},
	{  8,  1,  9, 24, 20, 17, 21, 26 },
	{ 11, 24, 10,  3, 23, 26, 22, 19 },
	{ 24,  9,  2, 10, 26, 21, 18, 22 },
	{ 16, 20, 26, 23,  4, 12, 25, 15 },
	{ 20, 17, 21, 26, 12,  5, 13, 25 },
	{ 23, 26, 22, 19, 15, 25, 14,  7 },
	{ 26, 21, 18, 22, 25, 13,  6, 14 }};

	// create new elements
	int m[27];
	for (int i=0; i<NE0; ++i)
	{
		FEElement& el0 = pm->Element(i);
		vector<int>& eel = EET[i];
		vector<int>& fel = EFL[i];

		for (int j=0; j< 8; ++j) m[     j] = el0.m_node[j];
		for (int j=0; j<12; ++j) m[ 8 + j] = NN0 + eel[j];
		for (int j=0; j< 6; ++j) m[20 + j] = NN0 + NC0 + fel[j];
		m[26] = NN0 + NC0 + NF0 + i;

		for (int j=0; j<8; ++j)
		{
			FEElement& el = pmnew->Element(i*8 + j);
			el.m_gid = el0.m_gid;
			el.SetType(FE_HEX8);

			for (int k=0; k<8; ++k) el.m_node[k] = m[LUT[j][k]];
		}
	}

	pmnew->RebuildMesh();

	if (m_smoothSurface)
	{
		// The face table lists all faces (including all internal ones). We only need
		// to loop over exterior faces, so we need to figure out which exterior face
		// corresponds to the face in the face table
		int NF = pm->Faces();
		for (int i=0; i<NF; ++i) 
		{
			FEFace& face = pm->Face(i);
			face.m_ntag = -1;

			for (int j=0; j<NF0; ++j)
			{
				FEFace& fj = FT[j];
				if (fj == face)
				{
					face.m_ntag = j;
					break;
				}
			}

			assert(face.m_ntag != -1);
		}

		for (int i=0; i<pmnew->Nodes(); ++i) pmnew->Node(i).m_ntag = 0;
		vector<vec3d> p(NN0, vec3d(0,0,0));
		for (int i=0; i<NF; ++i)
		{
			FEFace& face = pm->Face(i);
			int ne = face.Edges();
			for (int j=0; j<ne; ++j)
			{
				pmnew->Node(face.n[j]).m_ntag++;
				
				int ej = FET[i][j];
				pair<int, int>& e = ET[ej];
				pmnew->Node(NN0 + ej).m_ntag++;

				p[e.first ] += pmnew->Node(NN0 + ej).r;
				p[e.second] += pmnew->Node(NN0 + ej).r;

				p[face.n[j]] += pmnew->Node(NN0 + NC0 + face.m_ntag).r;
			}
		}

		for (int i=0; i<NN0; ++i)
		{
			FENode& ni = pmnew->Node(i);
			double m = (double) ni.m_ntag;
			if (m != 0.0)
			{
				ni.r = (p[i]/m + ni.r*(m - 3))/m;
			}
		}

		for (int i = 0; i<NF; ++i)
		{
			FEFace& face = pm->Face(i);
			int ne = face.Edges();
			for (int j = 0; j<ne; ++j)
			{
				int ej = FET[i][j];
				pmnew->Node(NN0 + ej).r += pmnew->Node(NN0 + NC0 + face.m_ntag).r*0.5;
			}
		}

		for (int i=0; i<NC0; ++i) 
		{
			FENode& node = pmnew->Node(NN0 + i);
			if (node.m_ntag != 0)
			{
				pmnew->Node(NN0 + i).r *= 0.5;
			}
		}

		pmnew->UpdateNormals();
	}

	return pmnew;
}

//=======================================================================================

FEHex2DSplitModifier::FEHex2DSplitModifier() : FEModifier("Split2D")
{
	m_smoothSurface = false;
}

void FEHex2DSplitModifier::DoSurfaceSmoothing(bool b)
{
	m_smoothSurface = b;
}

FEMesh* FEHex2DSplitModifier::Apply(FEMesh* pm)
{
	// make sure we are dealing with a hex mesh
	if (pm->IsType(FE_HEX8) == false) return 0;

	// we must also check if this is a valid 2D (i.e. single layer) hex mesh.
	// We do this by checking that each element has no neighbor for their top
	// and bottom face (which is assumed to be face 4 and 5).
	for (int i = 0; i < pm->Elements(); ++i)
	{
		FEElement& el = pm->Element(i);
		if ((el.m_nbr[4] != -1) || (el.m_nbr[5] != -1)) return nullptr;
	}

	// tag all faces that will be split
	pm->TagAllFaces(-1);
	int taggedFaces = 0;
	for (int i = 0; i < pm->Elements(); ++i)
	{
		FEElement& el = pm->Element(i);
		el.m_ntag = i;
		assert((el.m_face[4] != -1) && (el.m_face[5] != -1));
		if (el.m_face[4] == -1) return nullptr; else { pm->Face(el.m_face[4]).m_ntag = taggedFaces++;}
		if (el.m_face[5] == -1) return nullptr; else { pm->Face(el.m_face[5]).m_ntag = taggedFaces++;}
	}
	assert(taggedFaces == 2 * pm->Elements());

	// count all edges that will be split
	int edgeCount = 0;
	vector< pair<int, int> > edges;
	vector< vector<int> > EEL(pm->Elements(), vector<int>(8, -1));
	for (int i = 0; i < pm->Elements(); ++i)
	{
		FEElement& el = pm->Element(i);
		for (int k=0; k<=1; ++k)
		{
			for (int j = 0; j < 4; ++j)
			{
				int n0 = el.m_node[k*4 + j];
				int n1 = el.m_node[k*4 + (j+1)%4];
				if (el.m_nbr[j] == -1)
				{
					pair<int, int> edge;
					edge.first = n0;
					edge.second = n1;
					edges.push_back(edge);
					EEL[i][k * 4 + j] = edgeCount++;
				}
				else
				{
					int nej = el.m_nbr[j];
					FEElement& ej = pm->Element(nej);
					if (el.m_ntag < ej.m_ntag)
					{
						pair<int, int> edge;
						edge.first = n0;
						edge.second = n1;
						edges.push_back(edge);
						EEL[i][k * 4 + j] = edgeCount++;
					}
					else
					{
						int eid = -1;
						for (int l = 0; l < 4; ++l)
						{
							int m0 = ej.m_node[4 * k + l];
							int m1 = ej.m_node[4 * k + (l+1)%4];

							if (((n0 == m0) && (n1 == m1)) || ((n0 == m1) && (n1 == m0)))
							{
								eid = l + k*4;
								break;
							}
						}
						assert(eid >= 0);

						int edgeId = EEL[nej][eid];
						EEL[i][k * 4 + j] = edgeId;
					}
				}
			}
		}
	}
	assert(edgeCount == (int)edges.size());

	// get the mesh item counts
	int NN0 = pm->Nodes();
	int NE0 = pm->Elements();

	// each node, edge, face, and element will create a new node
	int NN1 = NN0 + edgeCount + taggedFaces;

	// each element will be split in four
	int NE1 = 4 * NE0;

	// create new mesh
	FEMesh* pmnew = new FEMesh;
	pmnew->Create(NN1, NE1);

	// assign nodes
	int n = 0;
	for (int i = 0; i < NN0; ++i, ++n)
	{
		FENode& n1 = pmnew->Node(n);
		FENode& n0 = pm->Node(i);
		n1 = n0;
	}

	for (int i = 0; i < edgeCount; ++i, ++n)
	{
		FENode& n1 = pmnew->Node(n);

		pair<int, int>& edge = edges[i];
		FENode& na = pm->Node(edge.first);
		FENode& nb = pm->Node(edge.second);

		n1.r = (na.r + nb.r)*0.5;
	}

	for (int i = 0; i < pm->Faces(); ++i)
	{
		FEFace& face = pm->Face(i);
		if (face.m_ntag != -1)
		{
			FENode& n1 = pmnew->Node(n++);

			vec3d r0 = pm->Node(face.n[0]).r;
			vec3d r1 = pm->Node(face.n[1]).r;
			vec3d r2 = pm->Node(face.n[2]).r;
			vec3d r3 = pm->Node(face.n[3]).r;

			n1.r = (r0 + r1 + r2 + r3)*0.25;
		}
	}

	const int LUT[4][8] = {
	{  0,  8, 16, 11,  4, 12, 17, 15 },
	{  8,  1,  9, 16, 12,  5, 13, 17 },
	{ 11, 16, 10,  3, 15, 17, 14,  7 },
	{ 16,  9,  2, 10, 17, 13,  6, 14 }};

	// create new elements
	int m[18];
	for (int i = 0; i < NE0; ++i)
	{
		FEElement& el0 = pm->Element(i);
		vector<int>& eel = EEL[i];

		for (int j = 0; j < 8; ++j) m[j] = el0.m_node[j];
		for (int j = 0; j < 8; ++j) m[8 + j] = NN0 + eel[j];
		for (int j = 0; j < 2; ++j) m[16 + j] = NN0 + edgeCount + 2*i + j;

		for (int j = 0; j < 4; ++j)
		{
			FEElement& el = pmnew->Element(i * 4 + j);
			el.m_gid = el0.m_gid;
			el.SetType(FE_HEX8);

			for (int k = 0; k < 8; ++k) el.m_node[k] = m[LUT[j][k]];
		}
	}

	pmnew->RebuildMesh();
/*
	if (m_smoothSurface)
	{
		// The face table lists all faces (including all internal ones). We only need
		// to loop over exterior faces, so we need to figure out which exterior face
		// corresponds to the face in the face table
		int NF = pm->Faces();
		for (int i = 0; i < NF; ++i)
		{
			FEFace& face = pm->Face(i);
			face.m_ntag = -1;

			for (int j = 0; j < NF0; ++j)
			{
				FEFace& fj = FT[j];
				if (fj == face)
				{
					face.m_ntag = j;
					break;
				}
			}

			assert(face.m_ntag != -1);
		}

		for (int i = 0; i < pmnew->Nodes(); ++i) pmnew->Node(i).m_ntag = 0;
		vector<vec3d> p(NN0, vec3d(0, 0, 0));
		for (int i = 0; i < NF; ++i)
		{
			FEFace& face = pm->Face(i);
			int ne = face.Edges();
			for (int j = 0; j < ne; ++j)
			{
				pmnew->Node(face.n[j]).m_ntag++;

				int ej = FET[i][j];
				pair<int, int>& e = ET[ej];
				pmnew->Node(NN0 + ej).m_ntag++;

				p[e.first] += pmnew->Node(NN0 + ej).r;
				p[e.second] += pmnew->Node(NN0 + ej).r;

				p[face.n[j]] += pmnew->Node(NN0 + NC0 + face.m_ntag).r;
			}
		}

		for (int i = 0; i < NN0; ++i)
		{
			FENode& ni = pmnew->Node(i);
			double m = (double)ni.m_ntag;
			if (m != 0.0)
			{
				ni.r = (p[i] / m + ni.r*(m - 3)) / m;
			}
		}

		for (int i = 0; i < NF; ++i)
		{
			FEFace& face = pm->Face(i);
			int ne = face.Edges();
			for (int j = 0; j < ne; ++j)
			{
				int ej = FET[i][j];
				pmnew->Node(NN0 + ej).r += pmnew->Node(NN0 + NC0 + face.m_ntag).r*0.5;
			}
		}

		for (int i = 0; i < NC0; ++i)
		{
			FENode& node = pmnew->Node(NN0 + i);
			if (node.m_ntag != 0)
			{
				pmnew->Node(NN0 + i).r *= 0.5;
			}
		}

		pmnew->UpdateNormals();
	}
*/
	return pmnew;
}
