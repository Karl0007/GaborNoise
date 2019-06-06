#pragma once
#include "MathFunction.h"
#include <random>
#include <functional> 
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <set>

namespace Karl07 {
	//using MF2D = MathFunction<double, 2>;
	//inline static auto &Math2 = MF2D::getInstance();
	//static auto &X = Math2.V[0];
	//static auto &Y = Math2.V[1];
	//static int MF2DNowSize() { return Math2.size(); }
	//static auto& C(double x) { return Math2.New(x); }
	//static auto& V(double &x) { return Math2.New(&x); }
	//static auto& sin(MF2D::Expression &e,double A = 1,double w = 1,double phi = 0) { return e.Sin(A,w,phi); }
	//static auto& cos(MF2D::Expression &e, double A = 1, double w = 1, double phi = 0) { return e.Cos(A,w,phi); }
	//static auto& asin(MF2D::Expression &e) { return e.ArcSin(); }
	//static auto& acos(MF2D::Expression &e) { return e.ArcCos(); }
	//static auto& exp(MF2D::Expression &e) { return e.Exp(); }
	//static auto& log(MF2D::Expression &e) { return e.Log(); }

	//template<class T>
	static default_random_engine RandEngine;

	static double Normalize(double x, double mx, double mn) {
		if (mx == mn) return x;
		return (x - mn) / (mx - mn);
	}

	//template<class T>
	static int Reflect(double x, double mx, double mn) {
		return mn + (mx - mn)*x;
	}

	class Range {
	public:
		double l, r;
		Range(double a = 0, double b = 1) : l(min(a,b)), r(max(a,b)) {}
		Range(double a, double b, double c, double d) : l(min(min(a, b), min(c, d))), r(max(max(a, b), max(c, d))) {}

		Range(Range const &) = default;
		Range& operator=(Range const &) = default;

		double Normalize(double x) const{
			if (l == r) return x;
			if (x >= r) return 1;
			if (x <= l) return 0;
			return (x - l)*1.0 / (r - l);
		}

		double Reflect(double x) const{
			if (x >= 1) x = 0.99;
			if (x < 0) x = 0;
			return l + (r - l)*x;
		}

		double len() const {
			return r - l;
		}

		double step() const {
			return 1.0/(r - l);
		}

		void Merge(double x) {
			l = min(l, x);
			r = max(r, x);
		}

		Range Fix(double x, double y) {
			return Range(max(x,l),min(r,y));
		}

		bool operator<(Range const &other) const{
			return r < other.l;
		}

		Range operator+(Range const & other) const{
			return Range(l + other.l, r + other.r);
		}

		Range operator-(Range const & other) const {
			return Range(l - other.r, r - other.l);
		}

		Range operator*(Range const & other) const {
			return Range(l * other.r, r * other.l, l * other.l, r * other.r);
		}

		Range operator/(Range const & other) const {
			return Range(l / other.r, r / other.l, l / other.l, r / other.r);
		}
	};

	class Func;
	template<class V0,class V1, class V2>
	class Com2;

	class Func {
	protected:
		double K, C;
	public:
		Range range;
		Func(double l = 0, double r = 1) : range(l, r),K(1),C(0) {}
		Func(Range & r) : range(r),K(1),C(0){}
		double Fix(double x) { return K * x + C; }
		void setRange(Range & other) { K /= range.len(); K *= other.len(); C = other.l - range.l * K; range = other; }
		virtual double operator()(double x, double y) = 0;

		template<class V0,class V1,class V2>
		typename Com2<V0,V1,V2> Merge(V1 const &v1, V2 const &v2) {
			return Com2<V0, V1, V2>(*static_cast<V0*>(this), v1, v2);
		}
	};
	
	class ConstNum : public Func {
		double N;
	public:
		ConstNum(double x) : N(x), Func(x, x) {};
		double operator()(double, double) { return Fix(N); }
	};

	template<class V>
	class Mix : public Func {

	};

	enum class Mix2Type { Add, Sub, Mul, Div };
	template<class V1,class V2>
	class Mix2 : public Func {
	public:
		Mix2Type t;
		V1 v1;
		V2 v2;
		Mix2(Mix2Type t,V1 const & v1,V2 const &v2) : v1(v1),v2(v2),t(t),Func() {
			switch (t)
			{
			case Mix2Type::Add:
				range = v1.range + v2.range;
				break;
			case Mix2Type::Sub:
				range = v1.range - v2.range;
				break;
			case Mix2Type::Mul:
				range = v1.range * v2.range;
				break;
			case Mix2Type::Div:
				range = v1.range / v2.range;
				break;
			}
		}
		double operator()(double x, double y) {
			switch (t)
			{
			case Mix2Type::Add:
				return v1(x, y) + v2(x, y);
			case Mix2Type::Sub:
				return v1(x, y) - v2(x, y);
			case Mix2Type::Mul:
				return v1(x, y) * v2(x, y);
			case Mix2Type::Div:
				return v1(x, y) / v2(x, y);
			}
		}
	};

	template<class V0,class V1, class V2>
	class Com2 : public Func {
		V0 v0;
		V1 v1;
		V2 v2;
	public:
		Com2(V0 const & v0,V1 const & v1, V2 const &v2) : v0(v0), v1(v1), v2(v2), Func(v0.range.l,v0.range.r) {}
		double operator()(double x, double y) {
			return v0(v1(x, y), v2(x, y));
		}
	};
	template<class V0, class V1, class V2> Com2<V0, V1, V2> Merge(V0 const &v0, V1 const &v1, V2 const &v2) { return Com2(v0, v1, v2); }
	template<class V1, class V2>Mix2<V1, V2> operator+(V1 const &v1, V2 const &v2) { return Mix2<V1, V2>(Mix2Type::Add, v1, v2); }
	template<class V1, class V2>Mix2<V1, V2> operator-(V1 const &v1, V2 const &v2) { return Mix2<V1, V2>(Mix2Type::Sub, v1, v2); }
	template<class V1, class V2>Mix2<V1, V2> operator*(V1 const &v1, V2 const &v2) { return Mix2<V1, V2>(Mix2Type::Mul, v1, v2); }
	template<class V1, class V2>Mix2<V1, V2> operator/(V1 const &v1, V2 const &v2) { return Mix2<V1, V2>(Mix2Type::Div, v1, v2); }

	class Gaussian : public Func {
		double A;
	public:
		Gaussian(double a, double l = 0, double r = 1) :A(a), Func(0, 1) { setRange(Range(l, r)); };
		double operator()(double x, double y) {
			return Fix(std::exp(-Const::pi * A*A * ((x)*(x)+(y) * (y))));// *std::cos(2 * Const::pi*F*(x*std::cos(W) + y * std::sin(W)));
		}
		double operator()(double x) {
			return Fix(K * std::exp(-Const::pi *A*A*(x)*(x)));
		}
	};

	class Harmonic : public Func {
		double F, W;
	public:
		Harmonic(double f, double w, double l = -1, double r = 1) : F(f), W(w), Func(-1, 1) { setRange(Range(l, r)); };
		double operator()(double x, double y) {
			return Fix(std::cos(2 * Const::pi*F*(x*std::cos(W) + y * std::sin(W))));
		}
	};

	class Delta : public Func {
		double T,F;
		double stepx, stepy;
		multimap<double, int> px;
		multimap<double, int> py;
		int cnt;
	public:
		Delta(double sx,double sy,double t = 1, double f = 0) : Func(f, t),stepx(sx),stepy(sy),cnt(0),T(t),F(f) {}
		
		void AddPoint(double x,double y) {
			cnt++;
			px.insert({ x,cnt });
			py.insert({ y,cnt });
		}

		double operator()(double x, double y) {
			auto bgx = px.lower_bound(x - stepx / 2);
			auto edx = px.upper_bound(x + stepx / 2);
			auto bgy = py.lower_bound(y - stepy / 2);
			auto edy = py.upper_bound(y + stepy / 2);
			for (; bgx != edx; ++bgx) {
				for (auto y = bgy; y != edy; ++y) {
					if (bgx->second == y->second) {
						return Fix(T);
					}
				}
			}
			return Fix(F);
		}
	};

	class KernelMaker {
		Range deg, feg, size;
		uniform_real_distribution<double> rdeg, rfeg, rsize;
	public:
		KernelMaker(Range &d = Range(0, 0), Range &f = Range(3, 3), Range &s = Range(3,3)) : deg(d.Fix(0,1)), feg(f.Fix(0.5,100)), size(s.Fix(0.5,100)), rdeg(d.l, d.r), rfeg(f.l, f.r), rsize(s.l, s.r) {};
		auto Make() {
			return Gaussian(rsize(RandEngine)) * Harmonic(rfeg(RandEngine),rdeg(RandEngine)*3.14);
		}
	};

	class Gabor : public Func {
	public:
		vector<pair<pair<double, double>, Mix2<Gaussian, Harmonic>>> v;
		//vector<pair<pair<double,double>,Mix2<Gaussian, Harmonic>>> vec[Setting::Split][Setting::Split];
		map<double, KernelMaker> maker;
		static double dist(double x1, double y1, double x2, double y2) { return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); }
		static int getPos(double x) {
			static Range r1(0, Setting::Split);
			static Range r2(-0.5, 0.5);
			return r1.Reflect(r2.Normalize(x));
		}
	
	public:
		Gabor() : Func(-1, 1) {}
		Gabor(map<double, KernelMaker> maker) :Func(-1, 1), maker(maker) {}
		void AddPoint(double x,double y) {
			static uniform_real_distribution<double> d(0, 1);
			v.push_back({ {x,y},(--maker.upper_bound(d(RandEngine)))->second.Make() });
			//vec[getPos(x)][getPos(y)].push_back({ {x,y},(--maker.upper_bound(d(RandEngine)))->second.Make() });
		}
		double operator()(double x,double y) {
			double res = 0;
			int px = getPos(x);
			int py = getPos(y);
			//for (int i = max(0, px - 2); i < min(Setting::Split, px + 2); i++) {
			//	for (int j = max(0, py - 2); j < min(Setting::Split, py + 2); j++) {
			//		for (auto &f : vec[i][j]) {
			//			res += f.second(x-f.first.first,y-f.first.second);
			//		}
			//	}
			//}
			for (auto &f : v) {
				res += f.second(x-f.first.first,y-f.first.second);
			}
			range.Merge(res);
			//res /= v.size();
			return res;
		}

	};

}