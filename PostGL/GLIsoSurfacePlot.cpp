#include "stdafx.h"
#include "GLIsoSurfacePlot.h"
#include "GLWLib/GLWidgetManager.h"
#include "PostLib/constants.h"
#include "PostLib/PropertyList.h"
#include "GLModel.h"
using namespace Post;

extern int LUT[256][15];
extern int ET_HEX[12][2];


class CIsoSurfaceProps : public CPropertyList
{
public:
	CIsoSurfaceProps(CGLIsoSurfacePlot* p) : m_iso(p)
	{
		QStringList cols;

		for (int i = 0; i<ColorMapManager::ColorMaps(); ++i)
		{
			string name = ColorMapManager::GetColorMapName(i);
			cols << name.c_str();
		}

		addProperty("Data field", CProperty::DataScalar);
		addProperty("Color map", CProperty::Enum)->setEnumValues(cols);
		addProperty("Allow clipping", CProperty::Bool);
		addProperty("Slice hidden"  , CProperty::Bool);
		addProperty("Slices"        , CProperty::Int );
		addProperty("Show Legend"   , CProperty::Bool);
		addProperty("Smooth"        , CProperty::Bool);
		addProperty("Range Type"    , CProperty::Enum)->setEnumValues(QStringList() << "Dynamic" << "Static" << "User");
		addProperty("User Range Min", CProperty::Float);
		addProperty("User Range Max", CProperty::Float);
	}

	QVariant GetPropertyValue(int i)
	{
		switch (i)
		{
		case 0: return m_iso->GetEvalField(); break;
		case 1: return m_iso->GetColorMap()->GetColorMap();
		case 2: return m_iso->AllowClipping(); break;
		case 3: return m_iso->CutHidden(); break;
		case 4: return m_iso->GetSlices(); break;
		case 5: return m_iso->ShowLegend(); break;
		case 6: return m_iso->RenderSmooth(); break;
		case 7: return m_iso->GetRangeType(); break;
		case 8: return m_iso->GetUserRangeMin(); break;
		case 9: return m_iso->GetUserRangeMax(); break;
		}
		return QVariant();
	}

	void SetPropertyValue(int i, const QVariant& v)
	{
		switch (i)
		{
		case 0: m_iso->SetEvalField(v.toInt()); break;
		case 1: m_iso->GetColorMap()->SetColorMap(v.toInt()); break;
		case 2: m_iso->AllowClipping(v.toBool()); break;
		case 3: m_iso->CutHidden(v.toBool()); break;
		case 4: m_iso->SetSlices(v.toInt()); break;
		case 5: m_iso->ShowLegend(v.toBool()); break;
		case 6: m_iso->RenderSmooth(v.toBool()); break;
		case 7: m_iso->SetRangeType(v.toInt()); break;
		case 8: m_iso->SetUserRangeMin(v.toFloat()); break;
		case 9: m_iso->SetUserRangeMax(v.toFloat()); break;
		}

		m_iso->Update();
	}

private:
	CGLIsoSurfacePlot*	m_iso;
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGLIsoSurfacePlot::CGLIsoSurfacePlot(CGLModel* po) : CGLPlot(po)
{
	static int n = 1;
	char szname[128] = { 0 };
	sprintf(szname, "Isosurface.%02d", n++);
	SetName(szname);

	m_nslices = 5;
	m_bsmooth = true;
	m_bcut_hidden = false;
	m_nfield = 0;

	m_rangeType = RNG_DYNAMIC;
	m_rngMin = 0.;
	m_rngMax = 1.;
	m_userMin = 0.;
	m_userMax = 1.;

	m_Col.SetDivisions(m_nslices);
	m_Col.SetSmooth(false);

	m_pbar = new GLLegendBar(&m_Col, 0, 0, 600, 100, GLLegendBar::HORIZONTAL);
	m_pbar->align(GLW_ALIGN_BOTTOM | GLW_ALIGN_HCENTER);
	m_pbar->SetType(GLLegendBar::DISCRETE);
	m_pbar->copy_label(szname);
	m_pbar->ShowTitle(true);
	CGLWidgetManager::GetInstance()->AddWidget(m_pbar);
}

CGLIsoSurfacePlot::~CGLIsoSurfacePlot()
{
	CGLWidgetManager::GetInstance()->RemoveWidget(m_pbar);
	delete m_pbar;	
}

CPropertyList* CGLIsoSurfacePlot::propertyList()
{
	return new CIsoSurfaceProps(this);
}

int CGLIsoSurfacePlot::GetSlices() 
{ 
	return m_nslices; 
}

void CGLIsoSurfacePlot::SetSlices(int nslices)
{ 
	m_nslices = nslices; 
	m_Col.SetDivisions(nslices); 
}

///////////////////////////////////////////////////////////////////////////////

void CGLIsoSurfacePlot::Render(CGLContext& rc)
{
	if (m_nfield == 0) return;

	glPushAttrib(GL_ENABLE_BIT | GL_LIGHTING_BIT);
	{
		glColor4ub(255,255,255,255);
		vec2f r = m_crng;
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glDisable(GL_TEXTURE_1D);
		GLfloat zero[4] = {0.f};
		GLfloat one[4] = {1.f, 1.f, 1.f, 1.f};
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, zero);
		glLightfv(GL_LIGHT0, GL_SPECULAR, zero);
	//	glLightfv(GL_LIGHT0, GL_AMBIENT, one);
	//	glLightfv(GL_LIGHT0, GL_DIFFUSE, one);

		float crng = (r.y - r.x);
		if (crng == 0.f) crng = 1.f;

		// scale a little to make sure the range extrema will be shown
		r.x *= .99f;
		r.y *= .99f;

		float denom = (m_nslices <= 1 ? 1.f : m_nslices - 1.f);
		for (int i=0; i<m_nslices; ++i)
		{
			float ref = r.x + (float) i / denom * (r.y - r.x);

			float w = (ref - m_crng.x)/crng;

			CColorMap& map = m_Col.ColorMap();
			GLColor col = map.map(w);

			RenderSlice(ref, col);
		}
	}
	glPopAttrib();
}

///////////////////////////////////////////////////////////////////////////////

void CGLIsoSurfacePlot::RenderSlice(float ref, GLColor col)
{
	int i, k, l;
	int ncase, *pf;
	float w;

	float ev[8];	// element nodal values
	vec3f ex[8];	// element nodal positions
	vec3f en[8];	// element nodal gradients

	const int HEX_NT[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	const int PEN_NT[8] = {0, 1, 2, 2, 3, 4, 5, 5};
	const int TET_NT[8] = {0, 1, 2, 2, 3, 3, 3, 3};

	CGLModel* mdl = GetModel();
	FEModel* ps = mdl->GetFEModel();

	// get the mesh
	FEMeshBase* pm = mdl->GetActiveMesh();

	const int* nt;

	glColor3ub(col.r, col.g, col.b);

	// loop over all elements
	for (i=0; i<pm->Elements(); ++i)
	{
		// render only if the element is visible and
		// its material is enabled
		FEElement& el = pm->Element(i);
		FEMaterial* pmat = ps->GetMaterial(el.m_MatID);
		if (pmat->benable && (el.IsVisible() || m_bcut_hidden) && el.IsSolid())
		{
			switch (el.Type())
			{
			case FE_HEX8   : nt = HEX_NT; break;
			case FE_HEX20  : nt = HEX_NT; break;
			case FE_HEX27  : nt = HEX_NT; break;
			case FE_PENTA6 : nt = PEN_NT; break;
            case FE_PENTA15: nt = PEN_NT; break;
            case FE_TET4   : nt = TET_NT; break;
			case FE_TET5   : nt = TET_NT; break;
			}

			// get the nodal values
			for (k=0; k<8; ++k)
			{
				FENode& node = pm->Node(el.m_node[nt[k]]);

				ev[k] = m_val[el.m_node[nt[k]]];
				ex[k] = node.m_rt;
				en[k] = m_grd[el.m_node[nt[k]]];
			}

			// calculate the case of the element
			ncase = 0;
			for (k=0; k<8; ++k) 
				if (ev[k] <= ref) ncase |= (1 << k);

			// loop over faces
			pf = LUT[ncase];
			for (l=0; l<5; l++)
			{
				if (*pf == -1) break;

				// calculate nodal positions
				vec3f r[3], vn[3];
				for (k=0; k<3; k++)
				{
					int n1 = ET_HEX[pf[k]][0];
					int n2 = ET_HEX[pf[k]][1];

					w = (ref - ev[n1]) / (ev[n2] - ev[n1]);

					r[k] = ex[n1]*(1-w) + ex[n2]*w;
				}

				// calculate normals
				if (m_bsmooth)
				{
					for (k=0; k<3; k++)
					{
						int n1 = ET_HEX[pf[k]][0];
						int n2 = ET_HEX[pf[k]][1];

						w = (ref - ev[n1]) / (ev[n2] - ev[n1]);

						vn[k] = en[n1]*(1-w) + en[n2]*w;
						vn[k].Normalize();
					}
				}
				else
				{
					for (k=0; k<3; k++)
					{
						int kp1 = (k+1)%3;
						int km1 = (k+2)%3;
						vn[k] = (r[kp1] - r[k])^(r[km1] - r[k]);
						vn[k].Normalize();
					}
				}

				// render the face
				glBegin(GL_TRIANGLES);
				{
					glNormal3f(vn[0].x,vn[0].y,vn[0].z); glVertex3f(r[0].x, r[0].y, r[0].z);
					glNormal3f(vn[1].x,vn[1].y,vn[1].z); glVertex3f(r[1].x, r[1].y, r[1].z);
					glNormal3f(vn[2].x,vn[2].y,vn[2].z); glVertex3f(r[2].x, r[2].y, r[2].z);
				}
				glEnd();

				pf+=3;
			}
		}
	}
}

//-----------------------------------------------------------------------------
void CGLIsoSurfacePlot::SetEvalField(int n) 
{ 
	m_nfield = n; 
	Update(GetModel()->currentTimeIndex(), 0.0, false);
}

//-----------------------------------------------------------------------------
void CGLIsoSurfacePlot::Update()
{
	Update(m_lastTime, m_lastdt, true);
}

//-----------------------------------------------------------------------------
void CGLIsoSurfacePlot::Update(int ntime, float dt, bool breset)
{
	m_lastTime = ntime;
	m_lastdt = dt;
	if (m_nfield == 0) return;

	CGLModel* mdl = GetModel();

	FEMeshBase* pm = mdl->GetActiveMesh();
	FEModel* pfem = mdl->GetFEModel();

	int NN = pm->Nodes();
	int NS = pfem->GetStates();

	if (breset) { m_map.Clear(); m_GMap.Clear(); m_rng.clear(); m_val.clear(); m_grd.clear(); }

	if (m_map.States() != pfem->GetStates())
	{
		m_map.Create(NS, NN, 0.f, -1);
		m_GMap.Create(NS, NN, vec3f(0,0,0), -1);
		m_rng.resize(NS);
		m_val.resize(NN);
		m_grd.resize(NN);
	}

	// see if we need to update this state
	if (m_map.GetTag(ntime) != m_nfield)
	{
		m_map.SetTag(ntime, m_nfield);
		vector<float>& val = m_map.State(ntime);

		// evaluate nodal values
		NODEDATA nd;
		for (int i=0; i<NN; ++i) 
		{
			pfem->EvaluateNode(i, ntime, m_nfield, nd);
			val[i] = nd.m_val;
		}

		// evaluate the range
		float fmin, fmax;
		fmin = fmax = val[0];
		for (int i=0;i<NN; ++i)
		{
			if (val[i] < fmin) fmin = val[i];
			if (val[i] > fmax) fmax = val[i];
		}
		if (fmin == fmax) fmax++;

		m_rng[ntime] = vec2f(fmin, fmax);
	}

	// see if we need to update the gradient
	if (m_bsmooth && (m_GMap.GetTag(ntime) != m_nfield))
	{
		vector<float>& val = m_map.State(ntime);
		m_GMap.SetFEMesh(pm);
		m_GMap.Gradient(ntime, val);
		m_GMap.SetTag(ntime, m_nfield);
	}

	// copy nodal values into current value buffer
	m_val = m_map.State(ntime);
	if (m_bsmooth) m_grd = m_GMap.State(ntime);

	// update colormap range
	vec2f r = m_rng[ntime];

	// update static range
	if (breset) { m_rngMin = r.x; m_rngMax = r.y; }
	else
	{
		if (r.x < m_rngMin) m_rngMin = r.x;
		if (r.y > m_rngMax) m_rngMax = r.y;
	}

	// set range for color map
	switch (m_rangeType)
	{
	case RNG_DYNAMIC:
		m_crng = m_rng[ntime];
		break;
	case RNG_STATIC:
		m_crng = vec2f((float) m_rngMin, (float) m_rngMax);
		break;
	case RNG_USER:
		m_crng = vec2f((float)m_userMin, (float)m_userMax);
		break;
	}

	m_pbar->SetRange(m_crng.x, m_crng.y);
}