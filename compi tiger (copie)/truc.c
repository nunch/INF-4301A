	#include "Exp.hh"
//#include "Scope.hh"
#include <iostream>
#include <vector>
#include <map>
#include <string>

int main(int argc, char const *argv[])
{
	/*try{
	Variables vars;
	vars.newScope();
	vars.newScope();
	vars.newVar("a",1);
	std::cout << vars.getVar("a")<<'\n';
	vars.setVar("a",5);

	std::cout << vars.getVar("a")<<'\n';
	}catch(const std::string& msg){
		std::cout<<msg;
	}*/
	/*Scope* s1;
	Scope* s2;
	Scope* s3;
	Scope* s4;
	Scope* s5;
	Scope* s6;
	std::vector<Scope*> v;
	std::cout <<s1<<s2<<s3<<s4<<s5<<s6<<std::endl;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);
	v.push_back(s6);
	for(auto it = v.begin();it!=v.end();it++) std::cout<<*it;b
		std::cout<<std::endl;*/
	/*GroupeScope* e1 = new GroupeScope(1);
	GroupeScope* e2 = new GroupeScope(2);
	GroupeScope* e3 = new GroupeScope(2);
	GroupeScope* e4 = new GroupeScope(3);
	GroupeScope* e5 = new GroupeScope(4);

	SousScope* s1 = new SousScope(new Var("1",new StringExp("truc")),1);
	SousScope* s2 = new SousScope(new Var("2",new Num(2)),1);
	SousScope* s3 = new SousScope(new Var("3",new Num(3)),1);
	SousScope* s4 = new SousScope(new Var("4",new Num(4)),2);
	SousScope* s5 = new SousScope(new Var("5",new Num(5)),2);
	SousScope* s6 = new SousScope(new Var("6",new Num(6)),3);
	SousScope* s7 = new SousScope(new Var("7",new Num(7)),3);
	SousScope* s8 = new SousScope(new Var("8",new Num(8)),4);
	SousScope* s9 = new SousScope(new Var("9",new Num(9)),1);

	e1->addScope(s1);
	e1->addScope(e2);
	e1->addScope(s2);
	e1->addScope(e3);
	e1->addScope(s3);
	e2->addScope(s4);
	e2->addScope(e4);
	e2->addScope(s5);
	e4->addScope(s6);
	e4->addScope(e5);
	e4->addScope(s7);
	e5->addScope(s8);
	e1->addScope(e3);
	e1->addScope(s9);

	std::cout<< e1 << std::endl;
	Variables eee;*
	Exp* e = new LetExp();

	((LetExp*)e)->head_->push_back(new Num(1));
	((LetExp*)e)->body_->push_back(new Num(2));
	std::cout << *e << std::endl;
	*/
	std::vector<int> v = {1,2,3};
	auto v1 = v;
	v1.push_back(4);
	for(auto i = v.begin();i!=v.end();i++) std::cout<<*i << " ";
		std::cout << '\n';
	for(auto i = v1.begin();i!=v1.end();i++) std::cout<<*i << " ";

	return 0;
}