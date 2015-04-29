#ifndef EXP_HHttt
#define EXP_HHttt 
	#include <iostream>
	#include <sstream>
	#include <vector>
	#include <map>

	class Variables;
	class Exp;
	class Bin;
	class Num;
	class IfExp;
	class ForExp;
	class Aco;
	class Var;
	class WhileExp;
	class Assignment;
	class Null;
	class StringExp;
	class ShowVar;
	class LetExp;
	class InExp;
	class EndExp;
	class GroupeScope;
	class Sequence;

	
	template <typename T>
	class Visitor
	{
	public:
		virtual T visitBin(const Bin& exp) = 0;
		virtual T visitNum(const Num& exp) = 0;
		virtual T visitIf(const IfExp& exp) = 0;
		virtual T visitVar(const Var& exp) = 0;
		virtual T visitShowVar(const ShowVar& exp) = 0;
		virtual T visitStringExp(const StringExp& exp) = 0;
		virtual T visitAco(const Aco& exp) = 0;
		virtual T visitFor(const ForExp& exp) = 0;
		virtual T visitWhile(const WhileExp& exp) = 0;
		virtual T visitAss(const Assignment& exp) = 0;
		virtual T visitNull(const Null& exp) = 0;
		virtual T visitLet(const LetExp& exp) = 0;
		virtual T visitIn(const InExp& exp) = 0;
		virtual T visitEnd(const EndExp& exp) = 0;
		virtual T visitSequence(const Sequence& exp) = 0;

	};

	class Exp
	{
	public:
		Exp() {};
		Exp(const Exp& rhs) {};
	public:
		virtual ~Exp() {};
		virtual int accept(Visitor<int>& v) const{return 0;};
		virtual void accept(Visitor<void>& v) const{};
		int operator()();
	};

	class Bin : public Exp
	{
	public:
		Bin(char oper, Exp* lhs, Exp* rhs)
		: Exp(), oper_(oper), lhs_(lhs), rhs_(rhs)
		{};
		~Bin() { delete lhs_; delete rhs_; }
		int accept(Visitor<int>& v) const {
			return v.visitBin(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitBin(*this);
		}
		friend std::ostream& operator<<(std::ostream& o, const Bin& tree);
	public:
		char oper_; 
		Exp* lhs_; 
		Exp* rhs_;
	};

	class Num : public Exp
	{
	public:
		Num(int val)
		: Exp(),val_(val)
		{};
		friend std::ostream& operator<<(std::ostream& o, const Num& tree);
		int accept(Visitor<int>& v) const {
			return v.visitNum(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitNum(*this);
		}

		int val_;
	};



	class Aco : public Exp
	{
	public:
		Aco(char aco)
		: Exp(),aco_(aco)
		{};
		friend std::ostream& operator<<(std::ostream& o, const Aco& tree);
		int accept(Visitor<int>& v) const {
			return v.visitAco(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitAco(*this);
		}
		char aco_;
	};

	class Var : public Exp
	{
	public:
		Var(std::string s,Exp* val)
		: Exp(),val_(val),name_(s)
		{};
		friend std::ostream& operator<<(std::ostream& o, const Var& tree);
		int accept(Visitor<int>& v) const {
			return v.visitVar(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitVar(*this);
		}
		Exp* val_;
		std::string name_;
	};

	class ShowVar : public Exp
	{
	public:
		ShowVar(Exp* val)
		: Exp(),val_(val)
		{};
		friend std::ostream& operator<<(std::ostream& o, const ShowVar& tree);
		int accept(Visitor<int>& v) const {
			return v.visitShowVar(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitShowVar(*this);
		}
		Exp* val_;
	};

	class LetExp : public Exp
	{
	public:
		LetExp():Exp(){
			head_ = new std::vector<Exp*>;
			body_ = new std::vector<Exp*>;
			totalNum++;
			num = totalNum;
		};
		~LetExp(){};
		
		friend std::ostream& operator<<(std::ostream& o, const LetExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitLet(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitLet(*this);
		}
		
		std::vector<Exp*> *head_;
		std::vector<Exp*> *body_;
		static int totalNum;
		int num;
	};



	class InExp : public Exp
	{
	public:
		InExp():Exp(){};
		~InExp(){};
		
		friend std::ostream& operator<<(std::ostream& o, const InExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitIn(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitIn(*this);
		}
	};

	class EndExp : public Exp
	{
	public:
		EndExp():Exp(){};
		~EndExp(){};
		
		friend std::ostream& operator<<(std::ostream& o, const EndExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitEnd(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitEnd(*this);
		}
	};


	class StringExp : public Exp
	{
	public:
		StringExp(std::string val)
		: Exp(),val_(val)
		{};
		friend std::ostream& operator<<(std::ostream& o, const StringExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitStringExp(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitStringExp(*this);
		}

		std::string val_;
	};


	class Assignment : public Exp
	{
	public:
		Assignment(std::string var, Exp* val):Exp(),var_(var),val_(val){};
		~Assignment(){};
		friend std::ostream& operator<<(std::ostream& o, const Assignment& tree);
		int accept(Visitor<int>& v) const {
			return v.visitAss(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitAss(*this);
		}
		std::string var_;
		Exp* val_;
	};

	class IfExp : public Exp
	{
	public:
		IfExp(Exp* cond, Exp* then,Exp* els):Exp(),cond_(cond),then_(then),els_(els),hasElse(1){};
		IfExp(Exp* cond, Exp* then):Exp(),cond_(cond),then_(then),els_(NULL),hasElse(0){};

		int accept(Visitor<int>& v) const {
			return v.visitIf(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitIf(*this);
		}
		friend std::ostream& operator<<(std::ostream& o, const IfExp& tree);

		Exp* cond_;
		Exp* then_;
		Exp* els_;
		int hasElse;
	};

	class ForExp : public Exp
	{
	public:
		ForExp(Exp* var, Exp* from, Exp* to, Exp* doo):Exp(),var_(var),from_(from),to_(to),do_(doo){};
		~ForExp(){};
		friend std::ostream& operator<<(std::ostream& o, const ForExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitFor(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitFor(*this);
		}
		Exp* var_;
		Exp* from_;
		Exp* to_;
		Exp* do_;
	};

	class WhileExp : public Exp
	{
	public:
		WhileExp(Exp* cond, Exp* doo):Exp(),cond_(cond),do_(doo){};
		~WhileExp(){};
		friend std::ostream& operator<<(std::ostream& o, const WhileExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitWhile(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitWhile(*this);
		}
		Exp* cond_;
		Exp* do_;
	};

	class Null : public Exp
	{
	public:
		Null():Exp(){};
		~Null(){};
		friend std::ostream& operator<<(std::ostream& o, const Null& tree);
		int accept(Visitor<int>& v) const {
			return v.visitNull(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitNull(*this);
		}
	};

	class Sequence : public Exp
	{
	public:
		Sequence(Exp* e):Exp(){
			vector.push_back(e);
		};
		~Sequence(){};
		friend std::ostream& operator<<(std::ostream& o, const Sequence& tree);
		int accept(Visitor<int>& v) const {
			return v.visitSequence(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitSequence(*this);
		}
		std::vector<Exp*> vector;
	};


	#include "Pretty_printer.hh"

	


	inline Exp* createNum(int i){
		return new Num(i);
	}

	inline Exp* createBin(char c, Exp* e1, Exp*e2){
		return new Bin(c,e1,e2);
	}

	inline Exp* createIf(Exp* e1, Exp* e2){
		return new IfExp(e1,e2);
	}

	inline Exp* createIf(Exp* e1, Exp* e2, Exp* e3){
		return new IfExp(e1,e2,e3);
	}

	inline Exp* createVar(std::string s,Exp* i){
		return new Var(s,i);
	}

	inline Exp* createAco(char c){
		return new Aco(c);
	}

	inline Exp* createFor(Exp* var, Exp* from, Exp* to, Exp* doo){
		return new ForExp(var,from,to,doo);
	}

	inline Exp* createWhile(Exp* cond, Exp* doo){
		return new WhileExp(cond,doo);
	}

	#include "Scope.hh"
	#include "Visitor.hh"
	//	#include "Fonctions.hh"
#endif