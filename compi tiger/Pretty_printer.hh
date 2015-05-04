#ifndef PRETTYPRINTER_HH
#define PRETTYPRINTER_HH value

class PrettyPrinter : public Visitor<void>
	{
	public:
		PrettyPrinter(std::ostream& ostr)
		: ostr_(ostr) {};
		void visitBin(const Bin& e) {
			e.lhs_->accept(*this);
			ostr_ << e.oper_;
			e.rhs_->accept(*this); 
		}

		void visitNum(const Num& e) {
			ostr_ << e.val_;
		}

		void visitIf(const IfExp& e){
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
		}

		void visitVar(const Var& e) {
			ostr_ << "var ";
			ostr_ << e.name_;
			ostr_ << " = ";
			e.val_->accept(*this);
		}

		void visitShowVar(const ShowVar& e) {
			//e.val_->accept(*this);
			ostr_<<e.name_;
		}

		void visitStringExp(const StringExp& e) {
			ostr_ << "\""<<e.val_<<"\"";
		}

		void visitFor(const ForExp& e){
			ostr_<<"for ";
			e.var_->accept(*this);
			ostr_<<" to ";
			e.to_->accept(*this);
			ostr_<<" do ";
			e.do_->accept(*this);
		}

		void visitWhile(const WhileExp& e){
			ostr_<<"while ";
			e.cond_->accept(*this);
			ostr_<<" do ";
			e.do_->accept(*this);
		}


		void visitAss(const Assignment& e){
			ostr_<<e.var_;
			ostr_<<" = ";
			e.val_->accept(*this);
		}

		void visitNull(const Null& e){
			ostr_<<"null";
		}


		void visitLet(const LetExp& exp){
			ostr_<<"let\n";
			for (auto i = exp.head_->begin(); i != exp.head_->end(); i++)
			{
				for(int i=0;i<exp.num+1;i++) ostr_<<'\t';
				(*i)->accept(*this);
				ostr_<<'\n';
			}
			for(int i=0;i<exp.num;i++) ostr_<<'\t';
			ostr_<<"in\n";
			for (auto i = exp.body_->begin(); i != exp.body_->end(); i++)
			{
				for(int i=0;i<exp.num+1;i++) ostr_<<'\t';
				(*i)->accept(*this);
				ostr_<<'\n';
			}
			for(int i=0;i<exp.num;i++) ostr_<<'\t';
			ostr_<<"end";
		}

		void visitSequence(const Sequence& e){
			ostr_<<"(";
			for(unsigned i=0;i<e.vector.size()-1;i++){
				e.vector[i]->accept(*this);
				ostr_<<"; ";
			}
			e.vector[e.vector.size()-1]->accept(*this);
			ostr_<<")";
		}

		void visitFunction(const FunctionExp& e){
			ostr_<<"function "<<e.f->name_<<"(";
			for(unsigned i=0;i<e.f->names_.size();i++){
				if(i!=e.f->names_.size()-1) ostr_<<e.f->names_[i]<<" : "<<e.f->types_[i]<<", ";
				else ostr_<<e.f->names_[i]<<" : "<<e.f->types_[i];
			}
			ostr_<<") ";
			if(e.f->returnType_!="null") ostr_<<" : "<<e.f->returnType_<<" ";
			ostr_<<"= ";
			e.f->body_->accept(*this);

		}

		void visitClass(const ClassExp& e){
			ostr_<<"class "<<e.c->name_;
			if(e.c->super_!=NULL) ostr_<<" extends "<<e.c->super_->name_;
			ostr_<<"\n{\n";
			for(auto it = e.c->attributes_.begin();it!=e.c->attributes_.end();it++){
				ostr_<<"\t"<<it->first<<" := "<<it->second;
			}
			for(auto it = e.c->methods_.begin();it!=e.c->methods_.end();it++){
				ostr_<<"\tmethods "<<it->first<<'(';
				for(unsigned i = 0;i<it->second->names_.size();i++){
					if(i!=it->second->names_.size()-1) ostr_<<it->second->names_[i]<< " : "<<it->second->types_[i]<<", ";
					else ostr_<<it->second->names_[i]<< " : "<<it->second->types_[i];
				}
				ostr_<<") ";
				if(it->second->returnType_!="null") ostr_<<" : "<<it->second->returnType_<<" ";
				ostr_<<"= ";
				it->second->body_->accept(*this);
			}
			ostr_<<"\n}";
		}

		void visitExecuteFunction(const ExecuteFunction& e){
			ostr_<<e.name_<<"(";
			for(unsigned i=0;i<e.exps_.size();i++){
				if(i!=e.exps_.size()-1){
					e.exps_[i]->accept(*this);
					ostr_<<", ";
				}else e.exps_[i]->accept(*this);
			}
			ostr_<<")";
		}

		void visitUseClass(const UseClass& exp){
			ostr_<<"new "<<exp.className_; 
		}
		void visitUseAttribute(const UseAttribute& exp){
			ostr_<<exp.name_<<"."<<exp.p_;
		}
		void visitUseMethod(const UseMethod& exp){
			ostr_<<exp.name_<<"."<<exp.method_<<"(";
			for(unsigned i=0;i<exp.exps_.size();i++){
				if(i!=exp.exps_.size()-1){
					exp.exps_[i]->accept(*this);
					ostr_<<", ";
				}else exp.exps_[i]->accept(*this);
			}
			ostr_<<")";
		}


	private:
		std::ostream& ostr_;
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
#endif