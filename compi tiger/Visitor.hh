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
		int visitSequence(const Sequence& exp){
			return 0;
		}
		int visitFunction(const FunctionExp& e){
			return e.f->body_->accept(*this);
		}
		int visitExecuteFunction(const ExecuteFunction& e){
			return 0;
		}
		int visitClass(const ClassExp& e){
			return 0;
		}
		int visitUseClass(const UseClass& e){
			return 0;
		}
		int visitUseAttribute(const UseAttribute& e){
			return 0;
		}
		int visitUseMethod(const UseMethod& e){
			return 0;
		}

		static Ressources* vars2;
	};

	class VisExp : public Visitor3<Exp*>
	{
	public:
		VisExp(){};
		Exp* visitBin( Bin& exp){
			std::string type1 = exp.lhs_->accept(*this)->type;
			std::string type2 = exp.rhs_->accept(*this)->type;
			if(type1=="string" && type2=="string"){
				if(exp.oper_=='+') {
					StringExp* e1 = (StringExp*) exp.lhs_->accept(*this);
					StringExp* e2 = (StringExp*) exp.rhs_->accept(*this);
					return new StringExp(e1->val_.erase(e1->val_.size()-1)+e2->val_.erase(0,1));
				}
				else throw new std::string("The operation "+std::string(exp.oper_,1)+" is not allowed with string");
			}
			else if(type1=="string" && type2=="int"){
				if(exp.oper_=='+') {
					StringExp* e1 = (StringExp*) exp.lhs_->accept(*this);
					Num* e2 = (Num*) exp.rhs_->accept(*this);
					std::string s= std::to_string(e2->val_);
					std::cout <<"truc "+s+" ou "<<e2->val_<<"\n";
					return new StringExp(e1->val_.erase(e1->val_.size()-1)+s+"\"");
				}
				else throw new std::string("The operation "+std::string(exp.oper_,1)+" is not allowed with a string and a number");
			}
			else if(type1=="int" && type2=="string"){
				if(exp.oper_=='+') {
					Num* e1 = (Num*) exp.lhs_->accept(*this);
					StringExp* e2 = (StringExp*) exp.rhs_->accept(*this);
					std::string s= std::to_string(e1->val_);
					std::cout <<"truc "+s+" ou "<<e1->val_<<"\n";
					return new StringExp("\""+s+e2->val_.erase(0,1));
				}
				else throw new std::string("The operation "+std::string(exp.oper_,1)+" is not allowed with a string and a number");
			}
			else if(type1=="int" && type2=="int"){
				Num* e1 = (Num*) exp.lhs_->accept(*this);
				Num* e2 = (Num*) exp.rhs_->accept(*this);
				switch(exp.oper_){
					case '+':
						return new Num(e1->val_+e2->val_);
						break;
					case '-':
						return new Num(e1->val_-e2->val_);
						break;
					case '*':
						return new Num(e1->val_*e2->val_);
						break;
					case '/':
						if(e2->val_==0) throw new std::string("You can divide by 0");
						return new Num(e1->val_/e2->val_);
						break;
					case '&':
						if(e1->val_ && e2->val_) return new Num(1);
						return new Num(0);
						break;
					case '|':
						if(e1->val_ || e2->val_) return new Num(1);
						return new Num(0);
						break;
					default:
						throw new std::string("The operation "+std::string(exp.oper_,1)+" is not allowed with numbers");
				}
			}
			throw new std::string("You can only do operation with number or string");
		}
		Exp* visitNum( Num& exp){
			return &exp;
		}
		Exp* visitIf( IfExp& exp){
			if(exp.cond_->accept(calc)) return exp.then_->accept(*this);
			else if(exp.hasElse==1) return exp.els_->accept(*this);
			return new Null();
		}
		Exp* visitVar( Var& e){
			vars2->newVar(e.name_,e.val_);
			return vars2->getVar(e.name_)->accept(*this);
		}
		Exp* visitShowVar( ShowVar& e){
			return vars2->getVar(e.name_)->accept(*this);
		}
		Exp* visitStringExp( StringExp& exp){
			return &exp;
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
		Exp* visitSequence( Sequence& exp){
			return new Null();
		}
		Exp* visitFunction(FunctionExp& e){
			return e.f->body_->accept(*this);
		}

		Exp* visitExecuteFunction(ExecuteFunction& e){
			try{
			Function* f = vars2->getFunction(e.name_);
			f->setExps(e.exps_);
			vars2->newScope(new LetExp());
			for(unsigned i=0;i<f->names_.size();i++){
				Var* v = new Var(f->names_[i],f->exps_[i]);
				v->accept(*this);
			}
			Exp*  ee = f->body_->accept(*this);
			vars2->deleteScope();
			return ee;
			} catch(const std::string& m){
				throw m;
			}
		}

		Exp* visitClass(ClassExp& e){
			return new Null();
		}

		Exp* visitUseClass(UseClass& e){
			try{
				Class* c = vars2->getClass(e.className_);
				e.init(c->attributes_, c->methods_);
				return &e;
			}catch(const std::string& m){
				throw m;
			}
		}

		Exp* visitUseAttribute(UseAttribute& e){
			UseClass* ee =(UseClass*) vars2->getVar(e.name_);
			if(ee==NULL) throw std::string("variable : "+e.name_+" is not an object of a class");
			return ee->attributes_[e.p_];
		}

		Exp* visitUseMethod(UseMethod& e){
			try{
				Function* f = ((UseClass*) vars2->getVar(e.name_))->methods_[e.name_];
				f->setExps(e.exps_);
				vars2->newScope(new LetExp());
				for(unsigned i=0;i<f->names_.size();i++){
					Var* v = new Var(f->names_[i],f->exps_[i]);
					v->accept(*this);
				}
				Exp*  ee = f->body_->accept(*this);
				vars2->deleteScope();
				return ee;
			} catch(const std::string& m){
				throw m;
			}
		}


		Calculator calc;
		static Ressources* vars2;
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
			int cond = e.cond_->accept(vis)->accept(calc);
			if(cond){
				e.then_->accept(*this);
			}else if(e.hasElse==1){
				e.els_->accept(*this);
			}
		}

		void visitVar(const Var& e) {
			Exp* ee = e.val_->accept(vis);
			vars2->newVar(e.name_,ee);
		}

		void visitShowVar(const ShowVar& e) {
			if(!vars2->hasVar(e.name_)) throw std::string("not a statement");
		}
		
		void visitFor(const ForExp& e){
			for(int i=(*e.var_)();i<(*e.to_)()+1;i++){
				vars2->setVar(((Assignment*)e.var_)->var_, new Num(i));
				e.do_->accept(*this);
			}
		}

		void visitStringExp(const StringExp& e) {
			
		}

		void visitWhile(const WhileExp& e){
			while(e.cond_->accept(calc)){
				std::cout<<e.cond_->accept(calc)<<std::endl;
				e.do_->accept(*this);
			}
		}


		void visitAss(const Assignment& e){
			try{
			Exp* ee = e.val_->accept(vis);
			vars2->setVar(e.var_,ee);
			} catch(const std::string& m){
				throw m;
			}
		}

		void visitNull(const Null& e){
		}

		void visitLet(const LetExp& exp){
		}

		void visitSequence(const Sequence& exp){
			for(auto i = exp.vector.begin(); i!=exp.vector.end();i++) (*i)->accept(*this);
		}

		void visitFunction(const FunctionExp& e){
			vars2->newFunction(e.f->name_,e.f);
		}


		void visitExecuteFunction(const ExecuteFunction& e){
			Function* f = vars2->getFunction(e.name_);
			std::vector<Exp*> v;
			for(unsigned i=0;i<e.exps_.size();i++) v.push_back(e.exps_[i]->accept(vis));
			f->setExps(v);
			vars2->newScope(new LetExp());
			for(unsigned i=0;i<f->names_.size();i++){
				Var* v = new Var(f->names_[i],f->exps_[i]);
				v->accept(*this);
			}
			f->body_->accept(*this);
			vars2->deleteScope();
		}

		void visitClass(const ClassExp& e){
			vars2->newClass(e.c->name_,e.c);
		}

		void visitUseClass(const UseClass& e){

		}

		void visitUseAttribute(const UseAttribute& e){

		}

		void visitUseMethod(const UseMethod& e){

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