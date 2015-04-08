#ifndef EXP_HHttt
#define EXP_HHttt 
	#include <iostream>
	#include <sstream>

	class Variables;
	class Exp;
	class Bin;
	class Num;
	class IfExp;
	class ForExp;
	class Aco;
	class Var;
	class WhileExp;
	class Sequence;
	class Assignment;
	class Null;
	class Visitor
	{
	public:
		virtual int visitBin(const Bin& exp) = 0;
		virtual int visitNum(const Num& exp) = 0;
		virtual int visitIf(const IfExp& exp) = 0;
		virtual int visitVar(const Var& exp) = 0;
		virtual int visitAco(const Aco& exp) = 0;
		virtual int visitFor(const ForExp& exp) = 0;
		virtual int visitWhile(const WhileExp& exp) = 0;
		virtual int visitSequence(const Sequence& exp) = 0;
		virtual int visitAss(const Assignment& exp) = 0;
		virtual int visitNull(const Null& exp) = 0;

	};

	class Exp
	{
	public:
		Exp() {};
		Exp(const Exp& rhs) {};
	public:
		virtual ~Exp() {};
		virtual int accept(Visitor& v) const{return 0;};
		int operator()();
	};

	class Bin : public Exp
	{
	public:
		Bin(char oper, Exp* lhs, Exp* rhs)
		: Exp(), oper_(oper), lhs_(lhs), rhs_(rhs)
		{};
		~Bin() { delete lhs_; delete rhs_; }
		int accept(Visitor& v) const {
			return v.visitBin(*this);
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
		int accept(Visitor& v) const {
			return v.visitNum(*this);
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
		int accept(Visitor& v) const {
			return v.visitAco(*this);
		}
		char aco_;
	};

	class Var : public Exp
	{
	public:
		Var(std::string s,int val)
		: Exp(),val_(val),name_(s)
		{};
		friend std::ostream& operator<<(std::ostream& o, const Var& tree);
		int accept(Visitor& v) const {
			return v.visitVar(*this);
		}
		int val_;
		std::string name_;
	};

	class Assignment : public Exp
	{
	public:
		Assignment(std::string var, int val):Exp(),var_(var),val_(val){};
		~Assignment(){};
		friend std::ostream& operator<<(std::ostream& o, const Assignment& tree);
		int accept(Visitor& v) const {
			return v.visitAss(*this);
		}
		std::string var_;
		int val_;
	};

	class IfExp : public Exp
	{
	public:
		IfExp(Exp* cond, Exp* then,Exp* els):Exp(),cond_(cond),then_(then),els_(els),hasElse(1){};
		IfExp(Exp* cond, Exp* then):Exp(),cond_(cond),then_(then),els_(NULL),hasElse(0){};

		int accept(Visitor& v) const {
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
		ForExp(Exp* var, Exp* from, Exp* to, Exp* doo):Exp(),var_(var),from_(from),to_(to),do_(doo){};
		~ForExp(){};
		friend std::ostream& operator<<(std::ostream& o, const ForExp& tree);
		int accept(Visitor& v) const {
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
		WhileExp(Exp* cond, Exp* doo):Exp(),cond_(cond),do_(doo){};
		~WhileExp(){};
		friend std::ostream& operator<<(std::ostream& o, const WhileExp& tree);
		int accept(Visitor& v) const {
			return v.visitWhile(*this);
		}
		Exp* cond_;
		Exp* do_;
	};

	class Sequence : public Exp
	{
	public:
		Sequence(Exp* e1, Exp* e2):Exp(),e1_(e1),e2_(e2){};
		~Sequence(){};
		friend std::ostream& operator<<(std::ostream& o, const Sequence& tree);
		int accept(Visitor& v) const {
			return v.visitSequence(*this);
		}
		Exp* e1_;
		Exp* e2_;
	};

	class Null : public Exp
	{
	public:
		Null():Exp(){};
		~Null(){};
		friend std::ostream& operator<<(std::ostream& o, const Null& tree);
		int accept(Visitor& v) const {
			return v.visitNull(*this);
		}
	};


	class PrettyPrinter : public Visitor
	{
	public:
		PrettyPrinter(std::ostream& ostr)
		: ostr_(ostr) {};
		int visitBin(const Bin& e) {
			ostr_ << '('; 
			e.lhs_->accept(*this);
			ostr_ << e.oper_;
			e.rhs_->accept(*this); 
			ostr_ << ')';
			return 0;
		}
		int visitNum(const Num& e) {
			ostr_ << e.val_;
			return 0;
		}

		int visitIf(const IfExp& e){
			if(e.hasElse==1){
				ostr_<<"if ";
				e.cond_->accept(*this);
				ostr_<< " then ";
				e.then_->accept(*this);
				ostr_<<" else ";
				e.els_->accept(*this);
			}else{
				ostr_<<"if ";
				e.cond_->accept(*this);
				ostr_<< " then ";
				e.then_->accept(*this);
			}
			return 0;
		}

		int visitVar(const Var& e) {
			ostr_ << "var ";
			ostr_ << e.name_;
			ostr_ << " = ";
			ostr_ << e.val_;
			return 0;
		}

		int visitAco(const Aco& e){
			ostr_<<e.aco_;
			return 0;
		}

		int visitFor(const ForExp& e){
			ostr_<<"for ";
			e.var_->accept(*this);
			ostr_<<" to ";
			e.to_->accept(*this);
			ostr_<<" do ";
			e.do_->accept(*this);
			return 0;
		}

		int visitWhile(const WhileExp& e){
			ostr_<<"while ";
			e.cond_->accept(*this);
			ostr_<<" do ";
			e.do_->accept(*this);
			return 0;
		}

		int visitSequence(const Sequence& e){
			e.e1_->accept(*this);
			ostr_<<", ";
			e.e2_->accept(*this);
			return 0;
		}

		int visitAss(const Assignment& e){
			ostr_<<e.var_;
			ostr_<<" = ";
			ostr_<<e.val_;
			return 0;
		}

		int visitNull(const Null& e){
			ostr_<<"null";
			return 0;
		}
	private:
		std::ostream& ostr_;
	};

	

	class Engine : public Visitor
	{
	public:
		Engine(){};
		int visitBin(const Bin& e) {
			if(e.oper_=='+') return e.lhs_->accept(*this)+e.rhs_->accept(*this);
			else if(e.oper_=='-') return e.lhs_->accept(*this)-e.rhs_->accept(*this); 
			else if(e.oper_=='*') return e.lhs_->accept(*this)*e.rhs_->accept(*this); 
			else if(e.oper_=='/') return e.lhs_->accept(*this)/e.rhs_->accept(*this); 
			return -1;
		}
		int visitNum(const Num& e) {
			return e.val_;
		}

		int visitIf(const IfExp& e){
			int cond = e.cond_->accept(*this);
			if(cond){
				return e.then_->accept(*this);
			}else if(e.hasElse==1){
				return e.els_->accept(*this);
			}
			return 0;
		}

		int visitVar(const Var& e) {
			return e.val_;
		}

		int visitAco(const Aco& e){
			return 0;
		}
		int visitFor(const ForExp& exp){
			return 0;
		}

		int visitWhile(const WhileExp& exp){
			return 0;
		}

		int visitSequence(const Sequence& exp){
			return 0;
		}

		int visitAss(const Assignment& e){
			return e.val_;
		}

		int visitNull(const Null& e){
			return 0;
		}

		static void setVars(Variables* v){
			vars = v;
		}

		static Variables* vars;
	};

	inline std::ostream& operator<<(std::ostream& o, const Exp& e)
	{
		std::stringstream ss;
		std::string s;
		PrettyPrinter printer(ss);
		e.accept(printer);
		s = ss.str();
		if(s!="") o<<s;
		return o;
	}

	inline int Exp::operator()()
	{
		Engine calc;
		return this->accept(calc);
	}


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

	inline Exp* createVar(std::string s,int i){
		return new Var(s,i);
	}

	inline Exp* createAco(char c){
		return new Aco(c);
	}

	inline Exp* createFor(Exp* var, Exp* from, Exp* to, Exp* doo){
		return new ForExp(var,from,to,doo);
	}

	inline Exp* createSequence(Exp* e1, Exp* e2){
		return new Sequence(e1,e2);
	}

	inline Exp* createWhile(Exp* cond, Exp* doo){
		return new WhileExp(cond,doo);
	}
	
#endif