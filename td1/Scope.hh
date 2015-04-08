#ifndef SCOPE_HH
#define SCOPE_HH
	
	#include <map>
	#include <vector>
	#include <string>
	#include <iostream>
	#include <sstream>
	#include "Exp.hh"
	
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
			actual = new GroupeScope(1);
			first = actual;
			Scope* s;
			scopes.push_back(s);
		};
		~Variables(){};

		void newScope(){
			Scope* s;
			scopes.push_back(s);
			GroupeScope* tmp = new GroupeScope(actual->num+1);
			actual->addScope(tmp);
			previous.push_back(actual);
			actual = tmp;
		}

		void newVar(std::string s, int i){
			if(vars[scopes.back()].count(s)==1){
				throw std::string("variable "+s+" already exists");
			}
			vars[scopes.back()][s] = i;
		}

		void newExp(Exp* e){
			exps[scopes.back()].push_back(e);
		}

		std::vector<Exp*> getExp(){
			return exps[scopes.back()];
		}

		void affiche(){
			std::cout<<first<<std::endl;
		}

		void setVar(std::string s, int i){
			for(auto it = scopes.rbegin();it!=scopes.rend();it++){
				std::map<std::string,int> v = vars[*it];
				int truc = v.count(s);
				if(truc==1) {
					vars[*it][s]=i;
					return;
				}
			}
			throw std::string("no variable exists with that name");
			
		}

		int getVar(std::string s){
			for(auto it = scopes.rbegin();it!=scopes.rend();it++){
				std::map<std::string,int> v = vars[*it];
				int truc = v .count(s);
				if(truc!=0) {
					return v[s];
				}
			}
			throw std::string("no variable exists with that name");
		}

		bool hasVar(std::string s){
			for(auto it = scopes.rbegin();it!=scopes.rend();it++){
				std::map<std::string,int> v = vars[*it];
				int truc = v.count(s);
				if(truc!=0) return true;
			}
			return false;
		}

		void deleteScope(){
			if(scopes.size()==1) throw std::string("problem in scope");
			vars.erase(scopes.back());
			scopes.pop_back();
			actual = previous.back();
			previous.pop_back();
		}

		void addExp(Exp* e){
			SousScope* s = new SousScope(e,actual->num);
			actual->addScope(s);
		}



	private:
		std::vector<Scope*> scopes;
		std::map<Scope*,std::map<std::string,int> > vars;
		std::vector<GroupeScope*> scop;
		std::map<Scope*, std::vector<Exp*> > exps;
		GroupeScope* first;
		GroupeScope* actual;
		std::vector<GroupeScope*> previous;
		int maxScope=-1;
	};

#endif	