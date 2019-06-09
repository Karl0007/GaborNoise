#pragma once
#include <functional>
#include <iostream>
#include <random>
#include "MathFun2d.h"
namespace Karl07 {
	using Byte = unsigned char;
	using namespace Setting;
	class Image
	{
	private:
		inline static const int deep = 4;
		int m_w, m_h;
		Range m_r;
		uniform_real_distribution<double> d;
		inline static Range m_sz = Range(0, 255);
	public:
		Byte * m_data;
		double * m_double;
	public:

		double noise() {
			return d(RandEngine);
		}
		double normalw(int x) { return Normalize(x, m_w,0)*DR*2-DR + noise(); }
		double normalh(int x) {return Normalize(x, m_h,0)*DR*2-DR + noise(); }

		double W() { return m_w; }
		double H() { return m_h; }

		Image(Image && other) : m_w(other.m_w), m_h(other.m_h),m_data(other.m_data),m_double(other.m_double), d(-(1.0 / m_w) / 4, (1.0 / m_w) / 4) {
			other.m_data = nullptr;
			other.m_double = nullptr;
		}

		Image(Image const & other) : m_w(other.m_w), m_h(other.m_h), d(-(1.0 / m_w) / 4, (1.0 / m_w) / 4) {
			for (int i = 0; i < m_h*m_w; i++)
				m_double[i] = other.m_double[i];
			Update();
		}


		Image(int w, int h, Func &f1) : Image(w,h) {
			m_data = new Byte[w*h * deep];
			m_double = new double[w*h];
			Reset(f1);
		}

		Image(int w, int h) : m_w(w), m_h(h), d(-(1.0 / m_w) / 4, (1.0 / m_w) / 4) {
			m_data = new Byte[w*h * deep];
			m_double = new double[w*h];
			for (int i = 0; i < m_h*m_w * deep; i++) m_data[i] = 0;
			for (int i = 0; i < m_h*m_w; i++) m_double[i] = 0;
		}


		void Update() {
#pragma omp parallel for
			for (int i = 0; i < m_h*m_w; i++) {
				m_data[i * deep + 0] = m_sz.Reflect(m_r.Normalize(m_double[i]));
				m_data[i * deep + 1] = m_sz.Reflect(m_r.Normalize(m_double[i]));
				m_data[i * deep + 2] = m_sz.Reflect(m_r.Normalize(m_double[i]));
				m_data[i * deep + 3] = 255;
				
			}
		}


		void Reset(Func &f1) {
#pragma omp parallel for
			for (int i = 0; i < m_h; i++) {
				for (int j = 0; j < m_w; j++) {
					auto h = normalh(i);
					auto w = normalw(j);
					m_double[i*m_w + j] = f1(w, h);
				}
			}
			m_r = f1.range;
			Update();
		}

		double& At(int i,int j) {
			return m_double[(i*m_w + j)];
		}

		double& RAt(int i, int j) {
			return m_double[((m_h-i)*m_w + j)];
		}

		bool inRange(int i,int j) {
			return (0 <= i && i < m_h && 0 <= j && j < m_w);
		}


		Image Mul(Image & other) {
			Image tmp(m_w, m_h);
#pragma omp parallel for
			for (int i = 0; i < m_h; i++) {
				for (int j = 0; j < m_w; j++) {
					double sum[deep]{ 0,0,0 };
					for (int a = -other.m_h/2,p = 0; p < other.m_h; p++,a++) {
						for (int b = -other.m_h/2,q = 0; q < other.m_w; q++,b++) {
							for (int k = 0; k < deep; k++) {
								if (inRange(i + a, j + b) && other.inRange(other.m_h - p, q)) {
									tmp.At(i, j) += At(i + a, j + b) * other.RAt(p, q);
									sum[k] += other.RAt(p, q);
								}
							}
						}
					}
					for (int k = 0; k < deep; k++)
						if (sum[k] != 0)tmp.At(i, j) /= sum[k];
				}
			}
			for (int k = 0; k < deep; k++)
				tmp.m_r = m_r * other.m_r;
			tmp.Update();
			return tmp;
		}

		~Image() {
			delete[] m_data;
			delete[] m_double;
		}
	};
}
