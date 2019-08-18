#include "stdafx.h"
#include "ParamBlock.h"
#include <assert.h>

//-----------------------------------------------------------------------------
//! parameter constructor. Set all default values.
Param::Param()
{ 
	m_nID = -1; 
	m_ntype = Param_UNDEF; 
	m_pd = 0;
	m_plc = 0; 
	m_szbrev = m_szname = m_szenum = 0; 
	m_nunit = Param_NOUNIT; 
	m_nstate = Param_ALLFLAGS; 
	m_szindx = 0;
	m_nindx = -1;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

//-----------------------------------------------------------------------------
//! parameter destructor.
Param::~Param()
{ 
	clear(); 
	if (m_plc) delete m_plc;
	m_plc = 0;
	if (m_bcopy) delete [] m_szenum;
}

//-----------------------------------------------------------------------------
Param* Param::SetEnumNames(const char* sz)
{ 
	if (m_bcopy) delete [] m_szenum;
	m_szenum = 0;
	m_bcopy = false;
	if (sz) m_szenum = (char*) sz;
	return this; 
}

//-----------------------------------------------------------------------------
Param* Param::CopyEnumNames(const char* sz)
{
	if (m_bcopy) delete [] m_szenum;
	m_szenum = 0;
	m_bcopy = false;
	if (sz)
	{
		int l = (int) strlen(sz);
		m_szenum = new char[l+1];
		strncpy(m_szenum, sz, l);
		m_szenum[l] = 0;
		m_bcopy = true;
	}
	return this;
}

//-----------------------------------------------------------------------------
void Param::clear()
{
	if (m_pd)
	{
		switch (m_ntype)
		{
		case Param_INT   : delete ((int*) m_pd); break;
		case Param_CHOICE: delete ((int*)m_pd); break;
		case Param_FLOAT : delete ((double*)m_pd); break;
		case Param_BOOL  : delete ((bool*) m_pd); break;
		case Param_VEC3D : delete ((vec3d*) m_pd); break;
		case Param_STRING: delete ((std::string*) m_pd); break;
		case Param_MATH  : delete ((std::string*) m_pd); break;
		default:
			assert(false);
		}
	}
}

void Param::SetParamType(Param_Type t)
{
	clear();
	m_ntype = t;
	switch (t)
	{
	case Param_INT   : m_pd = new int; break;
	case Param_CHOICE: m_pd = new int; break;
	case Param_FLOAT : m_pd = new double; break;
	case Param_BOOL  : m_pd = new bool; break;
	case Param_VEC3D : m_pd = new vec3d; break;
	case Param_STRING: m_pd = new std::string; break;
	case Param_MATH  : m_pd = new std::string; break;
	default:
		assert(false);
	}
}

//-----------------------------------------------------------------------------
void Param::SetLoadCurve()
{
	if (m_plc == 0) m_plc = new FELoadCurve;
}

//-----------------------------------------------------------------------------
void Param::SetLoadCurve(const FELoadCurve& lc)
{
	if (m_plc) delete m_plc;
	m_plc = new FELoadCurve(lc);
}

//-----------------------------------------------------------------------------
Param::Param(const Param& p)
{
	m_nID = p.m_nID;
	m_ntype = p.m_ntype;
	m_szbrev = p.m_szbrev;
	m_szname = p.m_szname;
	m_szenum = p.m_szenum;
	m_nunit = p.m_nunit;
	m_nstate = p.m_nstate;
    m_szindx = p.m_szindx;
    m_nindx = p.m_nindx;
	m_bcopy = false;
	m_offset = p.m_offset;
	m_isVariable = p.m_isVariable;
	switch (m_ntype)
	{
	case Param_INT   : { int*    pi = new int   ; m_pd = pi; *pi = *((int*   )p.m_pd); } break;
	case Param_CHOICE: { int*    pi = new int   ; m_pd = pi; *pi = *((int*   )p.m_pd); } break;
	case Param_FLOAT : { double* pd = new double; m_pd = pd; *pd = *((double*)p.m_pd); } break;
	case Param_BOOL  : { bool*   pb = new bool  ; m_pd = pb; *pb = *((bool*  )p.m_pd); } break;
	case Param_VEC3D : { vec3d*	 pv = new vec3d ; m_pd = pv; *pv = *((vec3d* )p.m_pd); } break;
	case Param_STRING: { std::string* ps = new std::string; m_pd = ps; *ps = *((std::string*)p.m_pd); } break;
	case Param_MATH  : { std::string* ps = new std::string; m_pd = ps; *ps = *((std::string*)p.m_pd); } break;
	default:
		assert(false);
	}
	if (p.m_plc) m_plc = new FELoadCurve(*p.m_plc); else m_plc = 0;
}

//-----------------------------------------------------------------------------
Param& Param::operator = (const Param& p)
{
	clear();
	m_nID = p.m_nID;
	m_ntype = p.m_ntype;
//	m_szbrev = p.m_szbrev;
//	m_szname = p.m_szname;
//	m_szenum = p.m_szenum;
//	m_nunit = p.m_nunit;
//	m_nstate = p.m_nstate;
//  m_szindx = p.m_szindx;
//  m_nindx = p.m_nindx;
	m_offset = p.m_offset;
	m_isVariable = p.m_isVariable;

	switch (m_ntype)
	{
	case Param_INT   : { int*    pi = new int   ; m_pd = pi; *pi = *((int*   )p.m_pd); } break;
	case Param_CHOICE: { int*    pi = new int   ; m_pd = pi; *pi = *((int*   )p.m_pd); } break;
	case Param_FLOAT : { double* pd = new double; m_pd = pd; *pd = *((double*)p.m_pd); } break;
	case Param_BOOL  : { bool*   pb = new bool  ; m_pd = pb; *pb = *((bool*  )p.m_pd); } break;
	case Param_VEC3D : { vec3d*	 pv = new vec3d ; m_pd = pv; *pv = *((vec3d* )p.m_pd); } break;
	case Param_STRING: { std::string* ps = new std::string; m_pd = ps; *ps = *((std::string*)p.m_pd); } break;
	case Param_MATH  : { std::string* ps = new std::string; m_pd = ps; *ps = *((std::string*)p.m_pd); } break;
	default:
		assert(false);
	}
	if (m_plc) delete m_plc;
	m_plc = 0;
	if (p.m_plc) m_plc = new FELoadCurve(*p.m_plc);

	return (*this);
}

//-----------------------------------------------------------------------------
Param::Param(int n, Param_Type ntype, const char* szb, const char* szn)
{
	int* pi = new int;
	*pi = n;
	m_pd = pi;
	assert((ntype == Param_INT) || (ntype == Param_CHOICE));
	m_ntype = ntype;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_nunit = Param_NOUNIT;
	m_nstate = Param_ALLFLAGS;
	m_szindx = 0;
	m_nindx = -1;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

//-----------------------------------------------------------------------------
Param::Param(int n, const char* szb, const char* szn)
{
	int* pi = new int;
	*pi = n;
	m_pd = pi;
	m_ntype = Param_INT;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_nunit = Param_NOUNIT;
	m_nstate = Param_ALLFLAGS;
	m_szindx = 0;
	m_nindx = -1;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

//-----------------------------------------------------------------------------
Param::Param(double d, const char* szb, const char* szn)
{
	double* pd = new double;
	*pd = d;
	m_pd = pd;
	m_ntype = Param_FLOAT;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_nunit = Param_NOUNIT;
	m_nstate = Param_ALLFLAGS;
	m_szindx = 0;
	m_nindx = -1;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

//-----------------------------------------------------------------------------
Param::Param(double d, Param_Unit nunit, const char* szb, const char* szn)
{
	double* pd = new double;
	*pd = d;
	m_pd = pd;
	m_ntype = Param_FLOAT;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_nunit = nunit;
	m_nstate = Param_ALLFLAGS;
	m_szindx = 0;
	m_nindx = -1;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

//-----------------------------------------------------------------------------
Param::Param(bool b, const char* szb, const char* szn)
{
	bool* pb = new bool;
	*pb = b;
	m_pd = pb;
	m_ntype = Param_BOOL;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_nunit = Param_NOUNIT;
	m_nstate = Param_ALLFLAGS;
	m_szindx = 0;
	m_nindx = -1;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

//-----------------------------------------------------------------------------
Param::Param(vec3d v, const char* szb, const char* szn)
{
	vec3d* pv = new vec3d;
	*pv = v;
	m_pd = pv;
	m_ntype = Param_VEC3D;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_nunit = Param_NOUNIT;
	m_nstate = Param_ALLFLAGS;
	m_szindx = 0;
	m_nindx = -1;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

Param::Param(const std::string& val, const char* szb, const char* szn)
{
	std::string* pv = new std::string;
	*pv = val;
	m_pd = pv;
	m_ntype = Param_STRING;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_nunit = Param_NOUNIT;
	m_nstate = Param_ALLFLAGS;
	m_szindx = 0;
	m_nindx = -1;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

//-----------------------------------------------------------------------------
Param::Param(int n, const char* szi, int idx, const char* szb, const char* szn)
{
	int* pi = new int;
	*pi = n;
	m_pd = pi;
	m_ntype = Param_INT;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_szindx = szi;
    m_nindx = idx;
	m_nunit = Param_NOUNIT;
	m_nstate = Param_ALLFLAGS;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}
    
//-----------------------------------------------------------------------------
Param::Param(double d, const char* szi, int idx, const char* szb, const char* szn)
{
	double* pd = new double;
	*pd = d;
	m_pd = pd;
	m_ntype = Param_FLOAT;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_szindx = szi;
    m_nindx = idx;
	m_nunit = Param_NOUNIT;
	m_nstate = Param_ALLFLAGS;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}
    
//-----------------------------------------------------------------------------
Param::Param(double d, const char* szi, int idx, Param_Unit nunit, const char* szb, const char* szn)
{
	double* pd = new double;
	*pd = d;
	m_ntype = Param_FLOAT;
	m_szbrev = szb;
	m_szname = (szn == 0 ? szb : szn);
	m_szenum = 0;
	m_szindx = szi;
    m_nindx = idx;
	m_nunit = nunit;
	m_nstate = Param_ALLFLAGS;
	m_plc = 0;
	m_bcopy = false;
	m_offset = 0;
	m_isVariable = false;
}

//=============================================================================
ParamBlock::ParamBlock(void)
{
}

//-----------------------------------------------------------------------------
ParamBlock::~ParamBlock(void)
{
}

//-----------------------------------------------------------------------------
ParamBlock::ParamBlock(ParamBlock &b)
{
	m_Param = b.m_Param;
}

ParamBlock& ParamBlock::operator =(ParamBlock &b)
{
	m_Param = b.m_Param;

	return *this;
}

//-----------------------------------------------------------------------------

void ParamContainer::Save(OArchive& ar)
{
	// write the parameters
	for (int i=0; i<m_Param.Size(); ++i)
	{
		Param& p = m_Param[i];
		ar.BeginChunk(CID_PARAM);
		{
			SaveParam(p, ar);
		}
		ar.EndChunk();
	}
}

//-----------------------------------------------------------------------------
void ParamContainer::SaveParam(Param &p, OArchive& ar)
{
	int nid = p.GetParamID();
	int ntype = (int) p.GetParamType();

	ar.WriteChunk(CID_PARAM_ID, nid);
	ar.WriteChunk(CID_PARAM_TYPE, ntype);

	switch (ntype)
	{
	case Param_FLOAT : { double g = p.GetFloatValue(); ar.WriteChunk(CID_PARAM_VALUE, g); } break;
	case Param_INT   : { int    n = p.GetIntValue  (); ar.WriteChunk(CID_PARAM_VALUE, n); } break;
	case Param_CHOICE: { int    n = p.GetIntValue  (); ar.WriteChunk(CID_PARAM_VALUE, n); } break;
	case Param_BOOL  : { bool   b = p.GetBoolValue (); ar.WriteChunk(CID_PARAM_VALUE, b); } break;
	case Param_VEC3D : { vec3d  v = p.GetVecValue  (); ar.WriteChunk(CID_PARAM_VALUE, v); } break;
	case Param_STRING: { std::string s = p.GetStringValue(); ar.WriteChunk(CID_PARAM_VALUE, s); } break;
	case Param_MATH  : { std::string s = p.GetMathString(); ar.WriteChunk(CID_PARAM_VALUE, s); } break;
	default:
		assert(false);
	}

	// store the load curve if there is one
	FELoadCurve* plc = p.GetLoadCurve();
	if (plc)
	{
		ar.BeginChunk(CID_LOAD_CURVE);
		{
			plc->Save(ar);
		}
		ar.EndChunk();
	}
}


//-----------------------------------------------------------------------------
void ParamContainer::Load(IArchive &ar)
{
	TRACE("ParamContainer::Load");

	while (IO_OK == ar.OpenChunk())
	{
		int nid = ar.GetChunkID();
		if (nid == CID_PARAM)
		{
			LoadParam(ar);
		}
		ar.CloseChunk();
	}
}

//-----------------------------------------------------------------------------
void ParamContainer::LoadParam(IArchive& ar)
{
	int npid;
	Param p;
	int ntype = -1;
	while (IO_OK == ar.OpenChunk())
	{
		int nid = ar.GetChunkID();
		switch (nid)
		{
		case CID_PARAM_ID: ar.read(npid); p.SetParamID(npid); break;
		case CID_PARAM_TYPE: 
			ar.read(ntype); 
			switch (ntype)
			{
			case Param_INT   : p.SetParamType(Param_INT  ); break;
			case Param_FLOAT : p.SetParamType(Param_FLOAT); break;
			case Param_BOOL  : p.SetParamType(Param_BOOL ); break;
			case Param_VEC3D : p.SetParamType(Param_VEC3D); break;
			case Param_CHOICE: p.SetParamType(Param_CHOICE); break;
			case Param_STRING: p.SetParamType(Param_STRING); break;
			case Param_MATH  : p.SetParamType(Param_MATH); break;
			case Param_CURVE_OBSOLETE: p.SetParamType(Param_FLOAT); break;
			}
			break;
		case CID_PARAM_VALUE:
			switch (ntype)
			{
			case Param_CHOICE: { int    n; ar.read(n); p.SetIntValue(n); } break;
			case Param_INT   : { int    n; ar.read(n); p.SetIntValue(n); } break;
			case Param_FLOAT : { double g; ar.read(g); p.SetFloatValue (g); } break;
			case Param_BOOL  : { bool   b; ar.read(b); p.SetBoolValue  (b); } break;
			case Param_VEC3D : { vec3d  v; ar.read(v); p.SetVecValue   (v); } break;
			case Param_STRING: { std::string s; ar.read(s); p.SetStringValue(s); } break;
			case Param_MATH  : { std::string s; ar.read(s); p.SetMathString(s); } break;
			case Param_CURVE_OBSOLETE:
				{
					// This is obsolete but remains for backward compatibility.
					FELoadCurve lc;
					lc.Load(ar);
					if (lc.Size() > 0) p.SetLoadCurve(lc);
				}
				break;
			default:
				assert(false);
			}
			break;
		case CID_LOAD_CURVE:
			{
				FELoadCurve lc;
				lc.Load(ar);

				// Old versions (<2.0) defined load curves for all float parameters,
				// although initially these load curves did not have points assigned yet.
				// Since 2.0 load curves are only assigned to parameters that are time dependant
				// so we have to add this check to prevent all these load curves from being read in.
				if (lc.Size() > 0) p.SetLoadCurve(lc);
			}
			break;
		}
		ar.CloseChunk();
	}

	// For old versions, call LoadParam which could be overriden by classes if the order of parameters has changed
	if (ar.Version() < 0x00020000)
	{
		LoadParam(p);
	}
	else
	{
		Param& param = GetParam(p.GetParamID());
		bool var = param.IsVariable();
		if (param.GetParamType() == p.GetParamType())
		{
			param = p;
		}
		else
		{
			assert(param.IsVariable());
			param.SetParamType(p.GetParamType());
			param = p;
		}
		if (var) param.MakeVariable(true);
	}
}

void ParamContainer::LoadParam(const Param& p)
{
	Param* param = GetParamPtr(p.GetParamID());
	if (param) *param = p;
}