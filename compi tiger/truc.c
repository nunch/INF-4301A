#include "Exp.hh"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <typeinfo>
#include <stdio.h>
 #include <unistd.h>
#include <cstdlib>

/*Ressources vars;
Ressources* Engine::vars2 = &vars;
Ressources* Calculator::vars2 = &vars;
Ressources* VisExp::vars2 = &vars;
Calculator calc;
 int LetExp::totalNum = -1;
*/
int a(){
	throw std::string("ab");
}
void b(){
	if(a()) 1;
}

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
	/*
	std::vector<Exp*> v = {new Num(1), new Num(2)};
	v+new Num(3)+new Num(4)+new Num(5)+new StringExp("ab");
	
	for(auto i=v.begin();i!=v.end();i++){
		std::cout<<**i<<std::endl;
	if(d==0) std::cout << "not equal\n";
	else std::cout<< "equal\n";*/
	//bool c = *a==b;
	//std::cout << c << std::endl;

	/*Exp* a = new Var("a",new Num(0));
	Exp* b = new Var("b", new Num(5));
	Engine e;
	a->accept(e);
	b->accept(e);
	a = new ShowVar("a",new Num(0));
	b = new ShowVar("b", new Num(5));
	Exp* b1 = new Bin('+',a,new Num(1));
	Exp* b2 = new Bin('-',b,new Num(1));
	Exp* a1 = new Assignment("a",b1);
	Exp* a2 = new Assignment("b",b2);
	Sequence* s = new Sequence(a1);
	s->vector+a2;
	Exp* t = new WhileExp(b,s);
	Exp* ee = new Sequence(a);
	((Sequence*) ee )->vector = s->vector;
	std::cout<< *t << std::endl;
	std::cout<< *ee << std::endl;
	std::cout<< *b1 << std::endl;
	std::cout<< *b2 << std::endl;
	std::cout<< *a1 << std::endl;
	std::cout<< *a2 << std::endl;
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
	t->accept(e);
	std::cout<<"a = "<<vars.getVar("a")->accept(calc)<<std::endl;
	std::cout<<"b = "<<vars.getVar("b")->accept(calc)<<std::endl;*/
	
	/*int pid = fork();
	if(pid==0){
		freopen("myfile.txt","r",stdin);
		scanf("%d",&a);
		std::cout<<"fils " <<a<<std::endl;
	}else{
		scanf("%d",&a);
		std::cout<<"papa " <<a<<std::endl;
	}*/
	std::cout<<stdin<<std::endl;
	int a;
	int p[2];
	pipe(p);
	p[0] = dup(0);
	//int stdin_copy = dup(0);
	//freopen("myfile.txt","r",stdin);
	write(p[1], "52", 2*sizeof(char));
	scanf("%d",&a);
	std::cout<<a<<std::endl;
	//dup2(stdin_copy, 0);
	scanf("%d",&a);
	std::cout<<a<<std::endl;
	//std::stri
	/*Engine engine;
	std::string a("truc"),b("int");
	Function* f = new Function(a,b,{"a1","vh","a3"}, {"int","string","int"},new ShowVar("a1"));
	Exp* e = new FunctionExp(f);
	std::cout<<*e<<std::endl;
	e->accept(engine);
	Exp* e1 = new ExecuteFunction(a,{new Num(9), new StringExp("2"),new Num(2)});
	Exp* e2 = new Var("ab",e1);
	e2->accept(engine);
	vars.setVar("ab",new Num(5));
	//Exp* e3 = new Assignment("ab",e1);
	//try{e3->accept(engine);} catch(const std::string& e){std::cout << e<<std::endl;}
	
	std::cout<<*e<<"\n"<<*e2<<"\n";
	std::cout<<*vars.getVar("ab")<<std::endl;*/
	std::string s = "truc"+5;

	
	return 0;
}