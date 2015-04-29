#ifndef FUNCTION_HH
#define FUNCTION_HH 

	class Function
	{
	public:
		Function(std::string name,  std::string returnType):name_(name),returnType_(returnType){};
		Function(std::string name,  std::string returnType, std::map<std::string, Exp*> param):
		name_(name),returnType_(returnType),parameters_(param){};
		~Function(){};

		void addInstruction(Exp* e){
			instructions_.push_back(e);
		}

		
		std::string name_;
		std::map<std::string, Exp*> parameters_;
		std::vector<Exp*> instructions_;
		std::string returnType_;

	};
	
#endif