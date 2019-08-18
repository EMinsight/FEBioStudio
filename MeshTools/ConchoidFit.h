#pragma once
#include <MathLib/math3d.h>
#include <vector>
using namespace std;

class ConchoidFit  
{
public:
	ConchoidFit();
	virtual ~ConchoidFit();

	void Fit(const vector<vec3d>& y, int maxiter = 100);

	double ObjFunc(double l);

	void Apply(vector<vec3d>& y);

protected:
	void Regression(const vector<vec3d>& y, vec3d& rc, quatd& q, double& a, double& b);
	vec3d Transform(vec3d& rc, quatd& q, const vec3d& p)
	{
		vec3d r = p - rc;
		q.RotateVector(r);
		return r;
	}

	vec3d GetOrientation(const vector<vec3d>& y);

	void FindMinimum();

public:
	vec3d	m_rc;	// center of conchoid
	quatd	m_q;	// orientation of conchoid
	quatd	m_qi;	// inverse of orientation

	double	m_a, m_b;	// conchoid parameters

	vector<vec3d> m_y;
};
