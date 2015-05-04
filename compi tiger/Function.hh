#ifndef FUNCTION_HH
#define FUNCTION_HH 
	
	#include <string>

	class Function
	{
	public:
		Function(std::string name,  std::string returnType, Exp* body):name_(name),returnType_(returnType),body_(body){};
		Function(std::string name,  std::string returnType, std::vector<std::string> n, std::vector<std::string> t,Exp* body):
		name_(name),returnType_(returnType),names_(n),types_(t),body_(body){};
		~Function(){};

		void setExps(std::vector<Exp*> e){
			if(e.size()!=names_.size()) throw std::string("function "+name_+" requires "+std::to_string(names_.size())+" parameters but you gave it "+std::to_string(e.size())+" parameters");
			for(unsigned i=0;i<e.size();i++){
				if(e[i]->type!=types_[i]) throw std::string("In function "+name_+", parameter n°"+std::to_string(i+1)+" has not the required type ("+types_[i]+")");
			}
			exps_ = e;
		}

		std::string& getType(){return returnType_;}
		
		std::string& name_;
		std::string& returnType_;
		std::vector<std::string> names_;
		std::vector<Exp*> exps_;
		std::vector<std::string> types_;
		Exp* body_;

	};

	class FunctionExp : public Exp
	{
	public:
		FunctionExp(Function* f_):Exp(""),f(f_){type = f->returnType_;};
		~FunctionExp(){};
		friend std::ostream& operator<<(std::ostream& o, const FunctionExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitFunction(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitFunction(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitFunction(*this);
		}

		Function* f;

	};

	class ExecuteFunction : public Exp
	{
	public:
		ExecuteFunction(std::string name, std::vector<Exp*> e):Exp(""),name_(name),exps_(e){};
		~ExecuteFunction(){};
		friend std::ostream& operator<<(std::ostream& o, const ExecuteFunction& tree);
		int accept(Visitor<int>& v) const {
			return v.visitExecuteFunction(*this);
		}
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitExecuteFunction(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitExecuteFunction(*this);
		}

		std::string name_;
		std::vector<Exp*> exps_;

	};
	
#endif