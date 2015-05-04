#ifndef CLASS_HH
#define CLASS_HH 
	
	class Class
	{
	public:
		Class(std::string n):name_(n),super_(NULL){};
		Class(std::string n, Class* super):name_(n),attributes_(super->attributes_), methods_(super->methods_),super_(super){};
		~Class(){};

		void addAttribute(std::string n, Exp* v){
			attributes_[n]=v;
		}

		void addMethods(std::string n, Function* f){
			methods_[n] = f;
		}
		
		std::string name_;
		std::map<std::string, Exp*> attributes_;
		std::map<std::string, Function*> methods_;
		Class* super_;
	};
	// Create class
	class ClassExp : public Exp
	{
	public:
		ClassExp(Class* c_):Exp(""),c(c_){};
		~ClassExp(){};
		friend std::ostream& operator<<(std::ostream& o, const ClassExp& tree);
		int accept(Visitor<int>& v) const {
			return v.visitClass(*this);
		};
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitClass(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitClass(*this);
		}
		Class* c;
	};
	// new Object
	class UseClass : public Exp
	{
	public:
		UseClass(std::string className):Exp(""),className_(className){};
		~UseClass(){};
		friend std::ostream& operator<<(std::ostream& o, const UseClass& tree);
		int accept(Visitor<int>& v) const {
			return v.visitUseClass(*this);
		};
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitUseClass(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitUseClass(*this);
		}

		void init(std::map<std::string, Exp*> a, std::map<std::string, Function*> m){
			attributes_ = a;
			methods_ = m;
		}

		std::string className_;
		std::map<std::string, Exp*> attributes_;
		std::map<std::string, Function*> methods_;
	};

	class UseAttribute : public Exp
	{
	public:
		UseAttribute(std::string name, std::string p):Exp("attribute"),name_(name),p_(p){};
		~UseAttribute(){};
		friend std::ostream& operator<<(std::ostream& o, const UseAttribute& tree);
		int accept(Visitor<int>& v) const {
			return v.visitUseAttribute(*this);
		};
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitUseAttribute(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitUseAttribute(*this);
		}

		std::string name_;
		std::string p_;

	};

	class UseMethod : public Exp
	{
	public:
		UseMethod(std::string name, std::string m, std::vector<Exp*> v):Exp("method"),name_(name), method_(m),exps_(v){};
		~UseMethod(){};
		friend std::ostream& operator<<(std::ostream& o, const UseMethod& tree);
		int accept(Visitor<int>& v) const {
			return v.visitUseMethod(*this);
		};
		Exp* accept(Visitor3<Exp*>& v) {
			return v.visitUseMethod(*this);
		}
		void accept(Visitor<void>& v) const {
			v.visitUseMethod(*this);
		}
		std::string name_;
		std::string method_;
		std::vector<Exp*> exps_;
	};


#endif	