#ifndef DRIVER_HH
#define DRIVER_HH value

	class Driver
	{
	public:
		Driver(){};
		~Driver(){
			for(unsigned i=0;i<v.size();i++){
				delete v[i];
			}
			for(unsigned i=0;i<f.size();i++){
				delete f[i];
			}
		};

		static Exp* createBin(char oper, Exp* lhs, Exp* rhs){
			Exp* e = new Bin(oper,lhs,rhs);
			v.push_back(e);
			return e;
		}

		static Exp* createNum(int val){
			Exp* e = new Num(val);
			v.push_back(e);
			return e;
		}

		static Exp* createVar(std::string s,Exp* val){
			Exp* e = new Var(s,val);
			v.push_back(e);
			return e;
		}

		static Exp* createShowVar(std::string s){
			Exp* e = new ShowVar(s);
			v.push_back(e);
			return e;
		}

		static Exp* createLetExp(){
			Exp* e = new LetExp();
			v.push_back(e);
			return e;
		}

		static Exp* createStringExp(std::string s){
			Exp* e = new StringExp(s);
			v.push_back(e);
			return e;
		}

		static Exp* createAssignment(std::string var, Exp* val){
			Exp* e = new Assignment(var,val);
			v.push_back(e);
			return e;
		}

		static Exp* createIfExp(Exp* cond, Exp* then,Exp* els){
			Exp* e = new IfExp(cond,then,els);
			v.push_back(e);
			return e;
		}

		static Exp* createIfExp(Exp* cond, Exp* then){
			Exp* e = new IfExp(cond,then);
			v.push_back(e);
			return e;
		}

		static Exp* createForExp(Exp* var, Exp* from, Exp* to, Exp* doo){
			Exp* e = new ForExp(var,from,to,doo);
			v.push_back(e);
			return e;
		}

		static Exp* createWhileExp(Exp* cond, Exp* doo){
			Exp* e = new WhileExp(cond,doo);
			v.push_back(e);
			return e;
		}

		static Exp* createNull(){
			Exp* e = new Null();
			v.push_back(e);
			return e;
		}

		static Exp* createSequence2(){
			Exp* e = new Sequence2();
			v.push_back(e);
			return e;
		}

		static Exp* createSequence(Exp* ee){
			Exp* e = new Sequence(ee);
			v.push_back(e);
			return e;
		}

		static Exp* createFunctionExp(Function* f){
			Exp* e = new FunctionExp(f);
			v.push_back(e);
			return e;
		}

		static Exp* createExecuteFunction(std::string name, std::vector<Exp*> e){
			Exp* ee = new ExecuteFunction(name,e);
			v.push_back(ee);
			return ee;
		}

		static Function* createFunction(std::string name,  std::string returnType, Exp* body){
			Function* e = new Function(name, returnType, body);
			f.push_back(e);
			return e;
		}

		static Function* createFunction(std::string name,  std::string returnType, std::vector<std::string> n, std::vector<std::string> t,Exp* body){
			Function* e = new Function(name, returnType,n,t, body);
			f.push_back(e);
			return e;
		}


		
		static std::vector<Exp*> v;
		static std::vector<Function*> f;
	};

#endif