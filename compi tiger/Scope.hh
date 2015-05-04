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
			ostr_<<*s.e_;
		}

		void visitGroupe(const GroupeScope& s){
			for(auto it = s.v.begin();it!=s.v.end();it++){
				(*it)->accept(*this);
				ostr_<<"\n";
			}
		}
		
		std::ostream& ostr_;
	};


	inline std::ostream& operator<<(std::ostream& o, const Scope* e)
	{
		Printer printer(o);
		e->accept(printer);
		return o;
	}

	
#endif	