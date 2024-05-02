#include <iostream> 
//#include "template_test.h"
using namespace std; 

class Base {
public:
	int a;
	void print_hello(){
		cout << "hello\n";
	};
	virtual void print_world(){
		cout << "Base world\n";
	}
};

class Child : public Base{	
public:
	void print_world(){
		cout << "Child world\n";
	}
};

class Infant : public Child {
public:
	void print_world(){
		cout << "Infant world\n";
	}
};

int main() { 
	Base b;
	Child c;
	Infant i;
	
	Base* ptr1 = &c;
	Base* ptr2 = new Child();
	Base& ptr3 = c;

	//Child* ptr3 = new Base();
	Child* ptr4 = dynamic_cast<Child*>(ptr2);	//success
	if (ptr4 == NULL) {
		std::cout << "NULL" << "\n";	
	}
	
	ptr3.print_world();
	std::cout << "sizeof(b): " << sizeof(b) << "\n";
	std::cout << "sizeof(c): " << sizeof(c) << "\n";

	return 0; 
} 
