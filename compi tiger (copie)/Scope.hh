#ifndef SCOPE_HH
#define SCOPE_HH
	
	class SousScope;
	class GroupeScope;

	class Visitor2
	{
	public:
		virtual void visitSous(const SousScope& s) = 0;
		virtual void visitGroupe(const GroupeScope& s) = 0;
	};

	
	class Scope
	{
	public:
		Scope(){};
		~Scope(){};
		virtual void accept(Visitor2& p)const = 0;
	};

	class SousScope : public Scope
	{
	public:
		SousScope(Exp* e, int n):Scope(),e_(e),num(n){};
		SousScope(Exp* e):Scope(),e_(e),num(-1){};
		~SousScope(){};

		friend std::ostream& operator<<(std::ostream& o, const SousScope& tree);
		
		void accept(Visitor2& p)const{
			p.visitSous(*this);
		}

		Exp* e_;
		int num;
	};

	class GroupeScope : public Scope
	{
	public:
		GroupeScope(int n):Scope(),num(n){};
		GroupeScope():Scope(),num(-1){};
		~GroupeScope(){};

		void addScope(Scope* s){
			v.push_back(s);
		};

		friend std::ostream& operator<<(std::ostream& o, const GroupeScope& tree);

		void accept(Visitor2& p)const{
			p.visitGroupe(*this);
		}

		std::vector<Scope*> v;
		int num;
	};

	class Printer : public Visitor2
	{
	public:
		Printer(std::ostream& ostr):ostr_(ostr){};
		~Printer(){};

		void visitSous(const SousScope& s){
			for(int j = 0;j<s.num;j++) ostr_<<'\t';
			ostr_<<*s.e_;
			ostr_<<'\n';
		}

		void visitGroupe(const GroupeScope& s){
			for(int j = 1;j<s.num;j++) ostr_<<'\t';
			ostr_<<"{\n";
			for(auto it = s.v.begin();it!=s.v.end();it++){
				(*it)->accept(*this);
			}
			for(int j = 1;j<s.num;j++) ostr_<<'\t';
			ostr_<<"}\n";
		}
		
		std::ostream& ostr_;
	};


	inline std::ostream& operator<<(std::ostream& o, const Scope* e)
	{
		Printer printer(o);
		e->accept(printer);
		return o;
	}

	class Variables
	{
	public:
		Variables(){
			isSet=0;
			Scope* s;
			scopes.push_back(s);
		};
		~Variables(){};

		void newScope(LetExp* l){
			Scope* s;
			scopes.push_back(s);

			if(isSet==0){
				first = l;
				isSet = 1;
				actual = l;
			}
			else{
				actual->body_->push_back(l);
				previousLet.push_back(actual);
				actual = l;
			}
		}

		void newVar(std::string s, Exp* i){
			if(vars[scopes.back()].count(s)==1){
				throw std::string("variable "+s+" already exists");
			}
			vars[scopes.back()][s] = i;
		}

		void affiche(){
			std::cout<<*((Exp*)first)<<std::endl;
		}

		void setVar(std::string s, Exp* i){
			for(auto it = scopes.rbegin();it!=scopes.rend();it++){
				std::map<std::string,Exp*> v = vars[*it];
				int truc = v.count(s);
				if(truc==1) {
					vars[*it][s]=i;
					return;
				}
			}
			throw std::string("no variable exists with that name");
			
		}

		Exp* getVar(std::string s){
			for(auto it = scopes.rbegin();it!=scopes.rend();it++){
				std::map<std::string,Exp*> v = vars[*it];
				int truc = v .count(s);
				if(truc!=0) {
					return v[s];
				}
			}
			throw std::string("no variable exists with that name");
		}

		bool hasVar(std::string s){
			for(auto it = scopes.rbegin();it!=scopes.rend();it++){
				std::map<std::string,Exp*> v = vars[*it];
				int truc = v.count(s);
				if(truc!=0) return true;
			}
			return false;
		}

		void deleteScope(){
			if(scopes.size()==1) throw std::string("problem in scope");
			vars.erase(scopes.back());
			scopes.pop_back();
			actual = previousLet.back();
			previousLet.pop_back();
			LetExp::totalNum--;
		}

		void addExpInBody(Exp* e){
			actual->body_->push_back(e);
		}

		void addExpInHead(Exp* e){
			actual->head_->push_back(e);
		}

	private:
		std::vector<Scope*> scopes;
		std::map<Scope*,std::map<std::string,Exp*> > vars;
		std::vector<GroupeScope*> scop;

		int isSet;
		LetExp* first;
		LetExp* actual;
		std::vector<LetExp*> previousLet;
	};
#endif	