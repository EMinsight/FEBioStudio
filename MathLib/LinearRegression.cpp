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
#include "LinearRegression.h"
#include "math3d.h"
#include <assert.h>

bool LinearRegression(const vector<pair<double, double> >& data, pair<double, double>& res)
{
	res.first = 0.0;
	res.second = 0.0;

	int n = (int)data.size();
	if (n == 0) return false;

	double mx = 0.0, my = 0.0;
	double sxx = 0.0, sxy = 0.0;
	for (int i=0; i<n; ++i) 
	{
		double xi = data[i].first;
		double yi = data[i].second;
		mx += xi;
		my += yi;

		sxx += xi*xi;
		sxy += xi*yi;
	}
	mx /= (double) n;
	my /= (double) n;
	sxx /= (double)n;
	sxy /= (double)n;

	double D = sxx - mx*mx;
	if (D == 0.0) return false;

	double a = (sxy - mx*my)/D;
	double b = my - a*mx;

	res.first = a;
	res.second = b;

	return true;
}

class Func
{
public:
	Func(){}
	virtual ~Func(){}
	virtual void setParams(const vector<double>& v) = 0;
	virtual double value(double x) = 0;
	virtual double derive1(double x, int n) = 0;
	virtual double derive2(double x, int n1, int n2) = 0;
};

class Quadratic : public Func
{
public:
	Quadratic() : m_a(0.0), m_b(0.0), m_c(0.0){}
	void setParams(const vector<double>& v) override { m_a = v[0]; m_b = v[1]; m_c = v[2]; }
	double value(double x) override { return m_a*x*x + m_b*x + m_c; }
	double derive1(double x, int n) override
	{
		switch (n)
		{
		case 0: return x*x; break;
		case 1: return x; break;
		case 2: return 1; break;
		default:
			assert(false);
			return 0.0;
		}
	}

	double derive2(double x, int n1, int n2) override
	{
		return 0.0;
	}

private:
	double	m_a, m_b, m_c;
};

class Exponential : public Func
{
public:
	Exponential() : m_a(0.0), m_b(0.0) {}
	void setParams(const vector<double>& v) override { m_a = v[0]; m_b = v[1]; }
	double value(double x) override { return m_a*exp(x*m_b); }
	double derive1(double x, int n) override
	{
		switch (n)
		{
		case 0: return exp(x*m_b); break;
		case 1: return m_a*x*exp(x*m_b); break;
		default:
			assert(false);
			return 0.0;
		}
	}

	double derive2(double x, int n1, int n2) override
	{
		if      ((n1 == 0) && (n2 == 0)) return 0;
		else if ((n1 == 0) && (n2 == 1)) return x*exp(x*m_b);
		else if ((n1 == 1) && (n2 == 0)) return x*exp(x*m_b);
		else if ((n1 == 1) && (n2 == 1)) return m_a*x*x*exp(x*m_b);
		else return 0.0;
	}

private:
	double	m_a, m_b;
};

bool NonlinearRegression(const vector<pair<double, double> >& data, vector<double>& res, int func)
{
	int MAX_ITER = 10;
	int niter = 0;

	int n = (int) data.size();
	int m = (int) res.size();

	Func* f = 0;
	switch (func)
	{
	case 1: f = new Quadratic; break;
	case 2: f = new Exponential; break;
	}
	if (f == 0) return false;

	vector<double> R(m, 0.0), da(m, 0.0);
	Matrix K(m, m); K.zero();

	const double absTol = 1e-15;
	const double relTol = 1e-3;
	double norm0 = 0.0;
	do
	{
		f->setParams(res);

		// evaluate residual (and norm)
		double norm = 0.0;
		for (int i=0; i<m; ++i)
		{
			R[i] = 0.0;
			for (int j=0; j<n; ++j)
			{
				double xj = data[j].first;
				double yj = data[j].second;
				double fj = f->value(xj);
				double Dfi = f->derive1(xj, i);
				R[i] -= (fj - yj)*Dfi;
			}

			norm += R[i]*R[i];
		}
		norm = sqrt(norm/n);

		if (norm < absTol) break;

		if (niter == 0) norm0 = norm;
		else
		{
			double rel = norm/norm0;
			if (rel < relTol) break;
		}

		// evaluate Jacobian
		for (int i=0; i<m; ++i)
		{
			for (int j=0; j<m; ++j)
			{
				double Kij = 0.0;
				for (int k=0; k<n; ++k)
				{
					double xk = data[k].first;
					double yk = data[k].second;
					double fk = f->value(xk);

					double Dfi = f->derive1(xk, i);
					double Dfj = f->derive1(xk, j);

					double Dfij = f->derive2(xk, i, j);

					Kij += Dfi*Dfj + (fk - yk)*Dfij;
				}

				K[i][j] = Kij;
			}
		}

		// solve linear system
		K.solve(da, R);

		for (int i=0; i<m; ++i) res[i] += da[i];

		niter++;
	}
	while (niter < MAX_ITER);

	delete f;

	return (niter < MAX_ITER);
}
