#pragma once
#include <functional> 
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <set>
#include "ConstNum.h"
using namespace std;
namespace Karl07 {


template<class Val = double,int Var = 4>
class MathFunction
{

//---------------------------------------类型定义---------------------------------------
public:
	class Expression;
	friend class Expression;
	using Fun = function<Val()>;

//---------------------------------------变量---------------------------------------
public:
	inline static Expression V[Var];
protected:
	inline static Val m_val[Var];
	inline static MathFunction* Instance = nullptr;
	inline static unordered_set<Expression*> tempExpression;

//---------------------------------------函数---------------------------------------
public:
	static MathFunction& getInstance() {
		if (Instance == nullptr)
			Instance = new MathFunction();
		return *Instance;
	}

	static Expression& New(Fun const & fun) {
		auto x = new Expression(fun);
		tempExpression.insert(x);
		return *x;
		//tempExpression.push_back(new Expression(fun));
		//return *tempExpression.back();
	}

	static Expression& New(Val const & v) {
		auto x = new Expression([=]() { return v; });
		tempExpression.insert(x);
		return *x;
		//tempExpression.push_back(new Expression([=]() { return v; }));
		//return *tempExpression.back();
	}

	static Expression& New(Val* v) {
		auto x = new Expression([=]() { return *v; });
		tempExpression.insert(x);
		return *x;
		//tempExpression.push_back(new Expression([=]() { return v; }));
		//return *tempExpression.back();
	}

	static void Clear() {
		for (auto i : tempExpression) delete i;
		tempExpression.clear();
		for (int i = 0; i < Var; i++) {
			m_val[i] = 0;
			V[i].m_fun = [&, i]() { return m_val[i]; };
		}
	}

	static int size() {
		return tempExpression.size();
	}

protected:


	//初始化变量
	MathFunction() {
		Clear();
	};

	~MathFunction() {
		Clear();
	};
	MathFunction(MathFunction const &) = delete;
	MathFunction(MathFunction &&) = delete;
	MathFunction& operator=(MathFunction const &) = delete;
	MathFunction& operator=(MathFunction &&) = delete;


//---------------------------------------Expression类---------------------------------------
public:
	class Expression {
		friend class MathFunction;
	protected:
		Fun m_fun;
	public:

		Val operator()() const {
			return m_fun();
		}

		Val Cal(Val const l[]) const{
			Val t[Var];
			for (int i = 0; i < Var; i++) {
				t[i] = m_val[i];
				m_val[i] = l[i];
			}
			Val res = m_fun();
			for (int i = 0; i < Var; i++) {
				m_val[i] = t[i];
			}
			return res;
		}

		Val operator()(Val x, ...) {
			Val t[Var];
			Val *tmp = &x;
			for (int i = 0; i < Var; i++,tmp++) {
				t[i] = m_val[i];
				m_val[i] = *tmp;
			}
			Val res = m_fun();
			for (int i = 0; i < Var; i++) {
				m_val[i] = t[i];
			}
			return res;
		}

		Expression& operator()(Expression* other,...) const {
			Fun fun[Var];
			Expression **tmp = &other;
			for (int i = 0; i < Var; i++, tmp++) {
				fun[i] = (*tmp)->m_fun;
			}
			return New([&,fun]() {
				Val t[Var];
				for (int i = 0; i < Var; i++) {
					t[i] = fun[i]();
					//cout << (t[i] = fun[i]()) << endl;
				}
				return Cal(t);
			});
		}

		Expression& operator+(Expression const &other) {
			return New([&]() {return other() + this->operator()();});
		}

		Expression& operator-(Expression const &other) {
			return New([&]() {return other() - this->operator()(); });
		}

		Expression& operator*(Expression const &other) {
			return New([&]() {return other() * this->operator()(); });
		}

		Expression& operator/(Expression const &other) {
			return New([&]() {return other() / this->operator()(); });
		}

		Expression& Pow(Expression const &other) {
			return New([&]() {return std::pow(other(), this->operator()()); });
		}

		//ln(x)
		Expression& Log() {
			return New([&]() {return std::log(this->operator()()); });
		}

		//e^x
		Expression& Exp() {
			return New([&]() {return std::exp(this->operator()()); });
		}

		//Asin(wx + phi)
		Expression& Sin(double A = 1,double w = 1,double phi = 0) {
			return New([&,A,w,phi]() {return A * std::sin(w*this->operator()() + phi); });
		}

		//Acos(wx + phi)
		Expression& Cos(double A = 1, double w = 1, double phi = 0) {
			return New([&,A, w, phi]() {return A * std::cos(w*this->operator()() + phi); });
		}

		Expression& ArcSin() {
			return New([&]() {return std::asin(this->operator()()); });
		}

		Expression& ArcCos() {
			return New([&]() {return std::acos(this->operator()()); });
		}

		Expression(Expression const &) = delete;
		Expression(Expression &&) = default;
		Expression& operator=(Expression const &) = delete;
		Expression& operator=(Expression && other) = default;
		~Expression(){}

	protected:
		Expression(Fun f = []() {return 0; }) {
			m_fun = f;
		}
	};

};
}