#ifndef VISITOR_HH
#define VISITOR_HH value
	
	#include <typeinfo> 

	class Calculator : public Visitor<int>
	{
	public:
		Calculator(){};
		int visitBin(const Bin& e) {
			//std::cout  << " calcu bin" << std::endl;
			if(e.oper_=='+') return e.lhs_->accept(*this)+e.rhs_->accept(*this);
			else if(e.oper_=='-') return e.lhs_->accept(*this)-e.rhs_->accept(*this); 
			else if(e.oper_=='*') return e.lhs_->accept(*this)*e.rhs_->accept(*this); 
			else if(e.oper_=='/') return e.lhs_->accept(*this)/e.rhs_->accept(*this);
			return -1;
		}

		int visitNum(const Num& e) {
			std::cout  << " calcu num" << std::endl;
			return e.val_;
		}

		int visitIf(const IfExp& e){
			std::cout  << " calcu if" << std::endl;
			int cond = e.cond_->accept(*this);
			if(cond){
				return e.then_->accept(*this);
			}else if(e.hasElse==1){
				return e.els_->accept(*this);
			}
			return 0;
		}

		int visitVar(const Var& e) {
			std::cout  << " calcu var" << std::endl;
			return vars2->getVar(e.name_)->accept(*this);
		}

		int visitShowVar(const ShowVar& e) {
			std::cout  << " calcu showvar " << e.name_ << std::endl;

			return vars2->getVar(e.name_)->accept(*this);
		}

		int visitAco(const Aco& e){
			return 0;
		}

		int visitFor(const ForExp& exp){
			return 0;
		}

		int visitStringExp(const StringExp& e) {
			std::cout  << " calcu stringexp" << std::endl;
			return e.val_!="";
		}

		int visitWhile(const WhileExp& exp){
			return 0;
		}


		int visitAss(const Assignment& e){
			return 0;
		}

		int visitNull(const Null& e){
			return 0;
		}

		int visitLet(const LetExp& exp){
			return 0;
		}

		int visitIn(const InExp& exp){
			return 0;
		}
		
		int visitEnd(const EndExp& exp){
			return 0;
		}
		int visitSequence(const Sequence& exp){
			return 0;
		}
		static Ressources* vars2;
	};

	class VisExp : public Visitor3<Exp*>
	{
	public:
		VisExp(){};
		Exp* visitBin( Bin& exp){
			return new Num(exp.accept(calc));
		}
		Exp* visitNum( Num& exp){
			return &exp;
		}
		Exp* visitIf( IfExp& exp){
			if(exp.cond_->accept(calc)) return exp.then_->accept(*this);
			else if(exp.hasElse==1) return exp.els_->accept(*this);
			return new Null();
		}
		Exp* visitVar( Var& exp){
			return exp.val_;
		}
		Exp* visitShowVar( ShowVar& exp){
			return exp.val_;
		}
		Exp* visitStringExp( StringExp& exp){
			return &exp;
		}
		Exp* visitAco( Aco& exp){
			return new Null();
		}
		Exp* visitFor( ForExp& exp){
			return new Null();
		}
		Exp* visitWhile( WhileExp& exp){
			return new Null();
		}
		Exp* visitAss( Assignment& exp){
			return new Null();
		}
		Exp* visitNull( Null& exp){
			return new Null();
		}
		Exp* visitLet( LetExp& exp){
			return new Null();
		}
		Exp* visitIn( InExp& exp){
			return new Null();
		}
		Exp* visitEnd( EndExp& exp){
			return new Null();
		}
		Exp* visitSequence( Sequence& exp){
			return new Null();
		}

		Calculator calc;
	};

	
	class Engine : public Visitor<void>
	{
	public:
		Engine(){};
		void visitBin(const Bin& e) {
			std::cout  << " Engine bin" << std::endl;
		}
		
		void visitNum(const Num& e) {
			std::cout  << " Engine num" << std::endl;
			
		}

		void visitIf(const IfExp& e){
			std::cout  << " Engine if" << std::endl;
			int cond = (*e.cond_)();
			if(cond){
				e.then_->accept(*this);
			}else if(e.hasElse==1){
				e.els_->accept(*this);
			}
		}

		void visitVar(const Var& e) {
			std::cout  << " Engine var" << std::endl;
			vars2->newVar(e.name_,e.val_);
		}

		void visitShowVar(const ShowVar& e) {
			
		}

		void visitAco(const Aco& e){
			
		}
		
		void visitFor(const ForExp& e){
			std::cout  << " Engine for" << std::endl;
			for(int i=(*e.var_)();i<(*e.to_)();i++){
				vars2->setVar(((Var*)e.var_)->name_, new Num(i));
				e.do_->accept(*this);
			}
		}

		void visitStringExp(const StringExp& e) {
			
		}

		void visitWhile(const WhileExp& e){
			std::cout  << " Engine while" << std::endl;
			while(e.cond_->accept(calc)){
				std::cout<<e.cond_->accept(calc)<<std::endl;
				e.do_->accept(*this);
			}
		}


		void visitAss(const Assignment& e){
			Exp* exp = new Assignment(e.var_,e.val_);
			std::cout  << " Engine ass : " <<*exp <<  std::endl;

			vars2->setVar(e.var_,e.val_->accept(vis));
		}

		void visitNull(const Null& e){
		}

		void visitLet(const LetExp& exp){
		}

		void visitIn(const InExp& exp){
		}
		
		void visitEnd(const EndExp& exp){
		}

		void visitSequence(const Sequence& exp){
			std::cout  << " Engine sequence " << std::endl;
			for(auto i = exp.vector.begin(); i!=exp.vector.end();i++) (*i)->accept(*this);
		}

		Calculator calc;
		VisExp vis;
		static Ressources* vars2;
	};

	inline int Exp::operator()()
	{
		Calculator calc;
		return this->accept(calc);
	}

#endif