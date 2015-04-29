#ifndef VISITOR_HH
#define VISITOR_HH value
	class Calculator : public Visitor<int>
	{
	public:
		Calculator(){};
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
			return e.val_->accept(*this);
		}

		int visitShowVar(const ShowVar& e) {
			return e.val_->accept(*this);
		}

		int visitAco(const Aco& e){
			return 0;
		}
		int visitFor(const ForExp& exp){
			return 0;
		}

		int visitStringExp(const StringExp& e) {
			return 0;
		}

		int visitWhile(const WhileExp& exp){
			return 0;
		}


		int visitAss(const Assignment& e){
			return e.val_->accept(*this);
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
		static Variables* vars2;
	};

	class Engine : public Visitor<void>
	{
	public:
		Engine(){};
		void visitBin(const Bin& e) {
			
		}
		
		void visitNum(const Num& e) {
			
		}

		void visitIf(const IfExp& e){
			int cond = (*e.cond_)();
			if(cond){
				e.then_->accept(*this);
			}else if(e.hasElse==1){
				e.els_->accept(*this);
			}
		}

		void visitVar(const Var& e) {
			
		}

		void visitShowVar(const ShowVar& e) {
			
		}

		void visitAco(const Aco& e){
			
		}
		
		void visitFor(const ForExp& e){
			for(int i=(*e.var_)();i<(*e.to_)();i++){
				vars2->setVar(((Var*)e.var_)->name_, new Num(i));
				e.do_->accept(*this);
			}
		}

		void visitStringExp(const StringExp& e) {
			
		}

		void visitWhile(const WhileExp& e){
			while((*e.cond_)()){
				e.do_->accept(*this);
			}
		}


		void visitAss(const Assignment& e){

			vars2->setVar(e.var_,e.val_);
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
			for(auto i = exp.vector.begin(); i!=exp.vector.end();i++) (*i)->accept(*this);
		}

		static Variables* vars2;
	};

	inline int Exp::operator()()
	{
		Calculator calc;
		return this->accept(calc);
	}

#endif