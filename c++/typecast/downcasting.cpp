#include <iostream> 
using namespace std; 

class Base { 
public:
    virtual void print() {
        cout << "I am in base class\n";
    }; 
};

class Derived : public Base { 
public:
    void print() {
        cout << "I am in derived class\n";
    }
};

int main()  {
	Base b;
	Derived d;

	Base *pb = static_cast<Base*>(&d);      	// #1
	Derived *pd = dynamic_cast<Derived*>(&b); 	// #2
    if (pd == NULL) {
        cout << "base class typecasting to derived pointer never succeed!";
    } else {
        cout << "base class to derive class typecasting is possible!"; 
    }

	return 0;
}