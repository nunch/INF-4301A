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
	class Var;
	class WhileExp;
	class Assignment;
	class Null;
	class StringExp;
	class ShowVar;
	class LetExp;
	class FunctionExp;
	class GroupeScope;
	class Sequence;
	class Function;
	class ExecuteFunction;
	class ClassExp;
	class UseClass;
	class UseAttribute;
	class UseMethod;

	
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
		virtual T visitFor(const ForExp& exp) = 0;
		virtual T visitWhile(const WhileExp& exp) = 0;
		virtual T visitAss(const Assignment& exp) = 0;
		virtual T visitNull(const Null& exp) = 0;
		virtual T visitLet(const LetExp& exp) = 0;
		virtual T visitSequence(const Sequence& exp) = 0;
		virtual T visitFunction(const FunctionExp& exp) = 0;
		virtual T visitExecuteFunction(const ExecuteFunction& exp) = 0;
		virtual T visitClass(const ClassExp& exp) = 0;
		virtual T visitUseClass(const UseClass& exp) = 0;
		virtual T visitUseAttribute(const UseAttribute& exp) = 0;
		virtual T visitUseMethod(const UseMethod& exp) = 0;

	};

	template <typename T>
	class Visitor3
	{
	public:
		virtual T visitBin( Bin& exp) = 0;
		virtual T visitNum( Num& exp) = 0;
		virtual T visitIf( IfExp& exp) = 0;
		virtual T visitVar( Var& exp) = 0;
		virtual T visitShowVar( ShowVar& exp) = 0;
		virtual T visitStringExp( StringExp& exp) = 0;
		virtual T visitFor( ForExp& exp) = 0;
		virtual T visitWhile( WhileExp& exp) = 0;
		virtual T visitAss( Assignment& exp) = 0;
		virtual T visitNull( Null& exp) = 0;
		virtual T visitLet( LetExp& exp) = 0;
		virtual T visitSequence( Sequence& exp) = 0;
		virtual T visitFunction(FunctionExp& exp) = 0;
		virtual T visitExecuteFunction(ExecuteFunction& exp) = 0;
		virtual T visitClass(ClassExp& exp) = 0;
		virtual T visitUseClass( UseClass& exp) = 0;
		virtual T visitUseAttribute( UseAttribute& exp) = 0;
		virtual T visitUseMethod( UseMethod& exp) = 0;

	};

	class Exp
	{
	public:
		Exp() {};
		Exp(std::string t):type(t) 
		{};
	public:
		virtual ~Exp() {};
		virtual int accept(Visitor<int>& v) const{return 0;};
		virtual void accept(Visitor<void>& v) const{};
		virtual Exp* accept(Visitor3<Exp*>& v){return new Exp();};
		bool operator==(Exp* e){
			return type==e->type;
		}
		int operator()();
		std::string type;
	};

	class Bin : public Exp
	{
	public:
		Bin(char oper, Exp* lhs, Exp* rhs)
		: Exp("Bin"), oper_(oper), lhs_(lhs), rhs_(rhs)
		{};
		Bin(Bin& b):Exp("Bin"),oper_(b.oper_),lhs_(b.lhs_),rhs_(b.rhs_){};
		~Bin() { delete lhs_; delete rhs_; }
		int accept(Visitor<int>& v) const {
			return v.visitBin(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitBin(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitBin(*this);
		}
		friend std::ostream& operator<<(std::ostream& o, const Bin& tree);
        friend std::vector<Exp*>& operator+(std::vector<Exp*>& v, Bin* r);
	public:
		char oper_; 
		Exp* lhs_; 
		Exp* rhs_;
	};

	class Num : public Exp
	{
	public:
		Num(int val)
		: Exp("int"),val_(val)
		{};
		Num(Num& val)
		: Exp("int"),val_(val.val_)
		{};
		friend std::ostream& operator<<(std::ostream& o, const Num& tree);
		int accept(Visitor<int>& v) const {
			return v.visitNum(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitNum(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitNum(*this);
		}

		int val_;
	};



	

	class Var : public Exp
	{
	public:
		Var(std::string s,Exp* val)
		: Exp(val->type),val_(val),name_(s)
		{};
		Var(Var& v)
		: Exp(v.type),val_(v.val_),name_(v.name_)
		{};
		friend std::ostream& operator<<(std::ostream& o, const Var& tree);
		int accept(Visitor<int>& v) const {
			return v.visitVar(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitVar(*this);
		}

		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitVar(*this);
		}
		Exp* val_;
		std::string name_;
	};

	class ShowVar : public Exp
	{
	public:
		ShowVar(std::string s)
		: Exp("none"),name_(s)
		{};
		ShowVar(ShowVar& v)
		: Exp(v.type),name_(v.name_)
		{};
		friend std::ostream& operator<<(std::ostream& o, const ShowVar& tree);
		int accept(Visitor<int>& v) const {
			return v.visitShowVar(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitShowVar(*this);
		}

		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitShowVar(*this);
		}
		std::string name_;
	};

	class LetExp : public Exp
	{
	public:
		LetExp():Exp("Let"){
			head_ = new std::vector<Exp*>;
			body_ = new std::vector<Exp*>;
			totalNum++;
			num = totalNum;
		};
		LetExp(LetExp& l):Exp("Let"),head_(l.head_),body_(l.body_),num(l.num){};
		~LetExp(){};
		
		friend std::ostream& operator<<(std::ostream& o, const LetExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitLet(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitLet(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitLet(*this);
		}
		
		std::vector<Exp*> *head_;
		std::vector<Exp*> *body_;
		static int totalNum;
		int num;
	};


	class StringExp : public Exp
	{
	public:
		StringExp(std::string val)
		: Exp("string"),val_(val)
		{};
		StringExp(StringExp& val)
		: Exp("string"),val_(val.val_)
		{};
		friend std::ostream& operator<<(std::ostream& o, const StringExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitStringExp(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitStringExp(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitStringExp(*this);
		}

		std::string val_;
	};


	class Assignment : public Exp
	{
	public:
		Assignment(std::string var, Exp* val):Exp("Ass"),var_(var),val_(val){};
		Assignment(Assignment& val):Exp("Ass"),var_(val.var_),val_(val.val_){};
		~Assignment(){};
		friend std::ostream& operator<<(std::ostream& o, const Assignment& tree);
		int accept(Visitor<int>& v) const {
			return v.visitAss(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitAss(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitAss(*this);
		}
		std::string var_;
		Exp* val_;
	};

	class IfExp : public Exp
	{
	public:
		IfExp(Exp* cond, Exp* then,Exp* els):Exp("If"),cond_(cond),then_(then),els_(els),hasElse(1){};
		IfExp(Exp* cond, Exp* then):Exp("If"),cond_(cond),then_(then),els_(NULL),hasElse(0){};
		IfExp(IfExp& i):Exp("If"),cond_(i.cond_),then_(i.then_),els_(i.els_),hasElse(i.hasElse){};


		int accept(Visitor<int>& v) const {
			return v.visitIf(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitIf(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitIf(*this);
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
		ForExp(Exp* var, Exp* from, Exp* to, Exp* doo):Exp("For"),var_(var),from_(from),to_(to),do_(doo){};
		ForExp(ForExp& f):Exp("For"),var_(f.var_),from_(f.from_),to_(f.to_),do_(f.do_){};
		~ForExp(){};
		friend std::ostream& operator<<(std::ostream& o, const ForExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitFor(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitFor(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitFor(*this);
		}
		Exp* var_;
		Exp* from_;
		Exp* to_;
		Exp* do_;
	};

	class WhileExp : public Exp
	{
	public:
		WhileExp(Exp* cond, Exp* doo):Exp("While"),cond_(cond),do_(doo){};
		WhileExp(WhileExp& w):Exp("While"),cond_(w.cond_),do_(w.do_){};
		~WhileExp(){};
		friend std::ostream& operator<<(std::ostream& o, const WhileExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitWhile(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitWhile(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitWhile(*this);
		}
		Exp* cond_;
		Exp* do_;
	};

	class Null : public Exp
	{
	public:
		Null():Exp("Null"){};
		~Null(){};
		friend std::ostream& operator<<(std::ostream& o, const Null& tree);
		int accept(Visitor<int>& v) const {
			return v.visitNull(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitNull(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitNull(*this);
		}
	};

	class Sequence2 : public Exp{
	public:
		Sequence2():Exp(""){};
		void push(std::string n, std::string t){
			names.push_back(n);
			types.push_back(t);
		}
		std::vector<std::string> names;
		std::vector<std::string> types;
	};

	class Sequence : public Exp
	{
	public:
		Sequence(Exp* e):Exp("Sequence"){
			vector.push_back(e);
		};
		Sequence(Sequence& s):vector(s.vector){};
		~Sequence(){};
		friend std::ostream& operator<<(std::ostream& o, const Sequence& tree);
		int accept(Visitor<int>& v) const {
			return v.visitSequence(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitSequence(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitSequence(*this);
		}
		std::vector<Exp*> vector;
	};

	#include "Function.hh"
	#include "Class.hh"
	#include "Pretty_printer.hh"

	
	#include "Driver.hh"
	
	
	#include "Scope.hh"
	#include "Ressources.hh"
	#include "Visitor.hh"
#endif