#pragma once
#include "MathFun2d.h"
#include <map>
#include <fstream>
#include <sstream>
using namespace std;
using namespace Karl07::Setting;

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
		Range W, F;
		double A;
		int weight;
		KernelData(Range &f = Range(5, 5), Range &w = Range(0, 0),double A = 1,int weight = 1) :
			F(f), W(w), weight(weight),A(A) {
			F = F.Fix(Setting::FMIN, Setting::FMAX);
			W = W.Fix(Setting::WMIN, Setting::WMAX);
		}
		string ToStr() {}
	};


	class KernelMaker {
		uniform_real_distribution<double> F, W;
		double A;
	public:
		KernelMaker() {}
		KernelMaker(KernelData &Data):
			W(Data.W.l, Data.W.r), F(Data.F.l, Data.F.r),A(Data.A){
		};

		auto Make(int seed = 0) {
			minstd_rand e(seed);
			double w = W(e), f = F(e);
			return Gaussian(1.0/DR*A) * Harmonic(F(e)/DR, W(e));
		}
		double operator ()(int seed, double x0, double y0) {
			minstd_rand e(seed);
			static uniform_real_distribution<double> d(-DR, DR);
			double w = W(e), f = F(e), x = -d(e) + x0, y = -d(e) + y0;
			return  std::exp(-Const::pi*(1.0 / (DR*DR )* A * A)*(x*x + y * y)) * std::cos(2 * Const::pi*f / DR * (x*std::cos(w) + y * std::sin(w)));
		}
	};

	class Gabor : public Func {
	public:
		map<double, KernelMaker> maker;
		int N,mx,my,cnt,r;
		double con;
	public:
		Gabor() : Func(-1, 1) {}
		Gabor(map<double, KernelMaker> &maker, int N, int cnt,double con,int mx=0,int my=0,int r = 0)
			:Func(-1, 1), maker(maker), N(N), mx(mx),my(my),cnt(cnt),r(r),con(con) {}

		double operator()(double x, double y) {
			double res = 0;
			static uniform_real_distribution<double> d(-DR, DR);
			static uniform_real_distribution<double> d01(0, 1);
			static uniform_real_distribution<double> d11(-1, 1);
			
			int posx = Range(0, N).Reflect(Range(-DR, DR).Normalize(x));
			int posy = Range(0, N).Reflect(Range(-DR, DR).Normalize(y));

			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					minstd_rand e((posx+i+N)%N+ ((posy + j+N)%N)*N + r);
					for (int k = 0; k < cnt; k++) {
						res += con * d11(e) * (--maker.upper_bound(d01(e)))->second(e(), 
							-(x*N - (posx - N / 2)*DR * 2) + i * DR * 2,
							-(y*N - (posy - N / 2)*DR * 2) + j * DR * 2);
					}
				}
			}
			return res;
		}
	};

	class GaborCube : public Func {
	public:
		map<double, KernelMaker> maker;
		int N, mx, my, cnt, r;
		double con;
	public:
		GaborCube() : Func(-1, 1) {}
		GaborCube(map<double, KernelMaker> &maker, int N, int cnt, double con, int mx = 0, int my = 0, int r = 0)
			:Func(-1, 1), maker(maker), N(N), mx(mx), my(my), cnt(cnt), r(r), con(con) {}

		double operator()(double x, double y) {
			double res = 0;
			static uniform_real_distribution<double> d(-DR, DR);
			static uniform_real_distribution<double> d01(0, 1);
			static uniform_real_distribution<double> d11(-1, 1);

			int posx = Range(0, 1).Reflect(Range(-DR, DR).Normalize(x));
			int posy = Range(0, 1).Reflect(Range(-DR, DR).Normalize(y));

			static int table[][4] = {
				2,3,4,5,
				6,1,4,5,
				1,6,4,5,
				2,3,6,1,
				2,3,1,6,
				3,2,4,5,
			};

			{
				minstd_rand e(N + r);
				for (int k = 0; k < cnt; k++) {
					res += con * d11(e) * (--maker.upper_bound(d01(e)))->second(e(),
						-(x * 1 - (posx - 1 / 2)*DR * 2) + 0 * DR * 2,
						-(y * 1 - (posy - 1 / 2)*DR * 2) + 0 * DR * 2);
				}
			}
			{
				minstd_rand e(table[N - 1][0] + r);
				for (int k = 0; k < cnt; k++) {
					res += con * d11(e) * (--maker.upper_bound(d01(e)))->second(e(),
						-(x * 1 - (posx - 1 / 2)*DR * 2) + 1 * DR * 2,
						-(y * 1 - (posy - 1 / 2)*DR * 2) + 0 * DR * 2);
				}
			}
			{
				minstd_rand e(table[N - 1][1] + r);
				for (int k = 0; k < cnt; k++) {
					res += con * d11(e) * (--maker.upper_bound(d01(e)))->second(e(),
						-(x * 1 - (posx - 1 / 2)*DR * 2) + -1 * DR * 2,
						-(y * 1 - (posy - 1 / 2)*DR * 2) + 0 * DR * 2);
				}
			}
			{
				minstd_rand e(table[N - 1][2] + r);
				for (int k = 0; k < cnt; k++) {
					res += con * d11(e) * (--maker.upper_bound(d01(e)))->second(e(),
						-(x * 1 - (posx - 1 / 2)*DR * 2) + 0 * DR * 2,
						-(y * 1 - (posy - 1 / 2)*DR * 2) + 1 * DR * 2);
				}
			}
			{
				minstd_rand e(table[N - 1][3] + r);
				for (int k = 0; k < cnt; k++) {
					res += con * d11(e) * (--maker.upper_bound(d01(e)))->second(e(),
						-(x * 1 - (+posx - 1 / 2)*DR * 2) + 0 * DR * 2,
						-(y * 1 - (posy - 1 / 2)*DR * 2) + -1 * DR * 2);
				}
			}
			return res;
		}
	};

	class GaborMaker {
	public:
		map<double, KernelMaker> maker;
		int N, cnt,r;
		GaborMaker() {}
		GaborMaker(vector<KernelData> &data,int N = 10,int cnt = 20,int r = 0):N(N),cnt(cnt),r(r) {
			double sum = 0, t = 0;
			for (auto &i : data) sum += i.weight;
			for (auto &i : data) maker[t] = KernelMaker(i), t += i.weight / sum;
		}
		GaborCube Cube(double N, double con = 1, int r = 0) {
			return GaborCube(maker, N, cnt, con, r);
		}
		Gabor operator()(double con = 1,int x=0,int y = 0,int r = 0) {
			return Gabor(maker,N,cnt,con,x,y ,r);
		}
	};
}

