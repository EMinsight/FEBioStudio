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
#include <FSCore/FSObject.h>
#include <MathLib/math3d.h>
#include <MathLib/MathParser.h>
#include <string>
//using namespace std;

//-----------------------------------------------------------------------------
// This class defines a data variable over the volume of a domain.
class FEDataVariable : public FSObject
{
public:
	FEDataVariable(void);
	virtual ~FEDataVariable(void) {}

	void SetString(int n, const char* sz);
	const char* GetString(int n) { return m_v[n].c_str(); }

	//! return the value at point r
	virtual vec3d Value(vec3d& r);

	int GetID() { return m_nID; }
 
private:
	FEDataVariable(const FEDataVariable& v) {}

protected:
	string		m_v[3];
	int			m_nID;
	CMathParser	m_mth;
};
