#include <iostream> 
//#include "template_test.h"
using namespace std; 

class Base{
public:
	int a;
	void print_hello(){
		cout << "hello\n";
	};
	virtual void print_world(){}
};

class Child : public Base{	
public:
	void print_world(){
		cout << "world\n";
	}
};

int main() { 
	Base b;
	Child c;
	Base* ptr1 = dynamic_cast<Base*>(&c);
	Base* ptr2 = new Child();

	//Child* ptr3 = new Base();
	Child* ptr3 = dynamic_cast<Child*>(ptr2);	//success
	if (ptr3 == NULL) {
		std::cout << "NULL" << "\n";	
	}
	
	std::cout << "sizeof(b): " << sizeof(b) << "\n";
	std::cout << "sizeof(c): " << sizeof(c) << "\n";

	return 0; 
} 
