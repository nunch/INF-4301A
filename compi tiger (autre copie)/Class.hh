#ifndef CLASS_HH
#define CLASS_HH 
	
	class Class
	{
	public:
		Class(std::string n):name(n){};
		~Class(){};

		void addAttribute(std::string n, Exp* v){
			attributes_[n]=v;
		}

		void addMethods(std::string n, Function* f){
			methods_[n] = f;
		}
		
		std::string name;
		std::map<std::string, Exp*> attributes_;
		std::map<std::string, Function*> methods_;
	};


#endif	