#ifndef RESSOURCES_HH
#define RESSOURCES_HH value
	
	class Ressources
	{
	public:
		Ressources(){
			isSet=0;
			generalScope = new GroupeScope();
			scopes.push_back(generalScope);
		};
		~Ressources(){};

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

		void newFunction(std::string s, Function* i){
			if(functions[scopes.back()].count(s)==1){
				throw std::string("function "+s+" already exists");
			}
			functions[scopes.back()][s] = i;
		}

		void newClass(std::string s, Class* i){
			if(classes[scopes.back()].count(s)==1){
				throw std::string("class "+s+" already exists");
			}
			classes[scopes.back()][s] = i;
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

		Function* getFunction(std::string s){
			for(auto it = scopes.rbegin();it!=scopes.rend();it++){
				std::map<std::string,Function*> v = functions[*it];
				int truc = v .count(s);
				if(truc!=0) {
					return v[s];
				}
			}
			throw std::string("no function exists with that name");
		}

		Class* getClass(std::string s){
			for(auto it = scopes.rbegin();it!=scopes.rend();it++){
				std::map<std::string,Class*> v = classes[*it];
				int truc = v .count(s);
				if(truc!=0) {
					return v[s];
				}
			}
			throw std::string("no class exists with that name");
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
			functions.erase(scopes.back());
			classes.erase(scopes.back());
			scopes.pop_back();
			if(previousLet.size()>0){
				actual = previousLet.back();
				previousLet.pop_back();
			}
			LetExp::totalNum--;
		}

		void addExpInBody(Exp* e){
			actual->body_->push_back(e);
		}

		void addExpInHead(Exp* e){
			actual->head_->push_back(e);
		}

		void addExpInGeneralScope(Exp* e){
			generalScope->addScope(new SousScope(e));
		}

	private:
		std::vector<Scope*> scopes;
		std::map<Scope*,std::map<std::string,Exp*> > vars;
		std::map<Scope*,std::map<std::string,Function*> > functions;
		std::map<Scope*,std::map<std::string,Class*> > classes;
		std::vector<GroupeScope*> scop;

		GroupeScope* generalScope;
		int isSet;
		LetExp* first;
		LetExp* actual;
		std::vector<LetExp*> previousLet;
	};

#endif