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
			ostr_ << e.val_;
		}

		void visitAco(const Aco& e){
			ostr_<<e.aco_;
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

		void visitIn(const InExp& exp){
			ostr_<<"in";
		}
		void visitEnd(const EndExp& exp){
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