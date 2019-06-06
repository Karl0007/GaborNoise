#pragma once
#include "MathFun2d.h"
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

namespace Karl07 {

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
		double T, F;
		double stepx, stepy;
		multimap<double, int> px;
		multimap<double, int> py;
		int cnt;
	public:
		Delta(double sx, double sy, double t = 1, double f = 0) : Func(f, t), stepx(sx), stepy(sy), cnt(0), T(t), F(f) {}

		void AddPoint(double x, double y) {
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

	class KernelData {
	public:
		Range D, F, S;
		int weight;
		KernelData(Range &d = Range(0, 0), Range &f = Range(3, 3), Range &s = Range(3, 3),int w = 1) : D(d.Fix(0, 1)), F(f.Fix(0.5, 100)), S(s.Fix(0.5, 100)),weight(w) {};
		string ToStr() {}
	};


	class KernelMaker {
		uniform_real_distribution<double> rdeg, rfeg, rsize;
	public:
		KernelMaker() {}
		KernelMaker(KernelData &Data):
			rdeg(Data.D.l, Data.D.r), rfeg(Data.F.l, Data.F.r), rsize(Data.S.l, Data.S.r) {};
		//KernelMaker(Range &d = Range(0, 0), Range &f = Range(3, 3), Range &s = Range(3, 3)) :
		//	rdeg(d.l, d.r), rfeg(f.l, f.r), rsize(s.l, s.r) {};
		auto Make() {
			return Gaussian(rsize(RandEngine)) * Harmonic(rfeg(RandEngine), rdeg(RandEngine)*3.14);
		}
	};

	class Gabor : public Func {
	public:
		vector<pair<pair<double, double>, Mix2<Gaussian, Harmonic>>> v;
		map<double, KernelMaker> maker;
	public:
		Gabor() : Func(-1, 1) {}
		Gabor(map<double, KernelMaker> &maker) :Func(-1, 1), maker(maker) {}
		void AddPoint(double x, double y) {
			static uniform_real_distribution<double> d(0, 1);
			v.push_back({ {x,y},(--maker.upper_bound(d(RandEngine)))->second.Make() });
		}
		double operator()(double x, double y) {
			double res = 0;
#pragma omp parallel for
			for (int i = 0; i < v.size();i++) {
				res += v[i].second(x - v[i].first.first, y - v[i].first.second);
			}
			range.Merge(res);
			return res;
		}
	};

	class GaborMaker {
	public:
		map<double, KernelMaker> maker;
		GaborMaker() {}
		GaborMaker(vector<KernelData> &data) {
			double sum = 0, t = 0;
			for (auto &i : data) sum += i.weight;
			for (auto &i : data) maker[t] = KernelMaker(i), t += i.weight / sum;
		}
		Gabor operator()(int size) {
			Gabor gabor(maker);
			static uniform_real_distribution<double> d(-0.5, 0.5);
			for (int i = 0; i < size; i++) {
				gabor.AddPoint(d(RandEngine), d(RandEngine));
			}
			return gabor;
		}
	};
}



	//class Gaussian : public Func {
	//	double A;
	//public:
	//	Gaussian(double a, double l = 0, double r = 1) :A(a), Func(0, 1) { setRange(Range(l, r)); };
	//	double operator()(double x, double y) {
	//		return Fix(std::exp(-Const::pi * A*A * ((x)*(x)+(y) * (y))));// *std::cos(2 * Const::pi*F*(x*std::cos(W) + y * std::sin(W)));
	//	}
	//	double operator()(double x) {
	//		return Fix(K * std::exp(-Const::pi *A*A*(x)*(x)));
	//	}
	//};

	//class Harmonic : public Func {
	//	double F, W;
	//public:
	//	Harmonic(double f, double w, double l = -1, double r = 1) : F(f), W(w), Func(-1, 1) { setRange(Range(l, r)); };
	//	double operator()(double x, double y) {
	//		return Fix(std::cos(2 * Const::pi*F*(x*std::cos(W) + y * std::sin(W))));
	//	}
	//};

	//class Delta : public Func {
	//	double T, F;
	//	double stepx, stepy;
	//	multimap<double, int> px;
	//	multimap<double, int> py;
	//	int cnt;
	//public:
	//	Delta(double sx, double sy, double t = 1, double f = 0) : Func(f, t), stepx(sx), stepy(sy), cnt(0), T(t), F(f) {}

	//	void AddPoint(double x, double y) {
	//		cnt++;
	//		px.insert({ x,cnt });
	//		py.insert({ y,cnt });
	//	}

	//	double operator()(double x, double y) {
	//		auto bgx = px.lower_bound(x - stepx / 2);
	//		auto edx = px.upper_bound(x + stepx / 2);
	//		auto bgy = py.lower_bound(y - stepy / 2);
	//		auto edy = py.upper_bound(y + stepy / 2);
	//		for (; bgx != edx; ++bgx) {
	//			for (auto y = bgy; y != edy; ++y) {
	//				if (bgx->second == y->second) {
	//					return Fix(T);
	//				}
	//			}
	//		}
	//		return Fix(F);
	//	}
	//};

	//class KernelMaker {
	//	Range deg, feg, size;
	//	uniform_real_distribution<double> rdeg, rfeg, rsize;
	//public:
	//	KernelMaker(Range &d = Range(0, 0), Range &f = Range(3, 3), Range &s = Range(3, 3)) : deg(d.Fix(0, 1)), feg(f.Fix(0.5, 100)), size(s.Fix(0.5, 100)), rdeg(d.l, d.r), rfeg(f.l, f.r), rsize(s.l, s.r) {};
	//	auto Make() {
	//		return Gaussian(rsize(RandEngine)) * Harmonic(rfeg(RandEngine), rdeg(RandEngine)*3.14);
	//	}
	//};

	//class Gabor : public Func {
	//public:
	//	vector<pair<pair<double, double>, Mix2<Gaussian, Harmonic>>> v;
	//	//vector<pair<pair<double,double>,Mix2<Gaussian, Harmonic>>> vec[Setting::Split][Setting::Split];
	//	map<double, KernelMaker> maker;
	//	//static double dist(double x1, double y1, double x2, double y2) { return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); }
	//	//static int getPos(double x) {
	//	//	static Range r1(0, Setting::Split);
	//	//	static Range r2(-0.5, 0.5);
	//	//	return r1.Reflect(r2.Normalize(x));
	//	//}

	//public:
	//	Gabor() : Func(-1, 1) {}
	//	Gabor(map<double, KernelMaker> maker) :Func(-1, 1), maker(maker) {}
	//	void AddPoint(double x, double y) {
	//		static uniform_real_distribution<double> d(0, 1);
	//		v.push_back({ {x,y},(--maker.upper_bound(d(RandEngine)))->second.Make() });
	//		//vec[getPos(x)][getPos(y)].push_back({ {x,y},(--maker.upper_bound(d(RandEngine)))->second.Make() });
	//	}
	//	double operator()(double x, double y) {
	//		double res = 0;
	//		//int px = getPos(x);
	//		//int py = getPos(y);
	//		//for (int i = max(0, px - 2); i < min(Setting::Split, px + 2); i++) {
	//		//	for (int j = max(0, py - 2); j < min(Setting::Split, py + 2); j++) {
	//		//		for (auto &f : vec[i][j]) {
	//		//			res += f.second(x-f.first.first,y-f.first.second);
	//		//		}
	//		//	}
	//		//}
	//		for (auto &f : v) {
	//			res += f.second(x - f.first.first, y - f.first.second);
	//		}
	//		range.Merge(res);
	//		//res /= v.size();
	//		return res;
	//	}