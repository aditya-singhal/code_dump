#include <iostream>

class Base { virtual void vf(){} };
class Derived : public Base { };

int main() {
	Base b;
	Derived d;

	Base* bptr = &b;
	Derived* dptr = static_cast<Derived*>(&b);

	// pd = dynamic_cast<Derived*>(pBDerived);
	// pd = dynamic_cast<Derived*>(pBBase);

	while(1);
	return 0;
}
