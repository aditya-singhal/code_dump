#include <iostream>

class Base {
public:
	int a = 1;
	int b = 2;
};

class Derived : public Base {
public:
	int b=3;
};

int main(){
	Base b1;
	Derived d1;

	std::cout << "sizeof(b1): " << sizeof(b1) << "\n";
	std::cout << "sizeof(d1): " << sizeof(d1) << "\n";
	std::cout << "value: " << d1.Base::b << "\n";

	return 0;
}
