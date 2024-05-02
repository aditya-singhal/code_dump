#include <iostream>

using namespace std;

// Tips:
// Some operators return by value, some by reference. 
// In general, an operator whose result is a new value (such as +, -, etc) must return the new value by value,
// and an operator whose result is an existing value, but modified (such as <<, >>, +=, -=, etc),
// should return a reference to the modified value.

// Pre/Postfix overload
// the compiler looks to see if the overloaded operator has an int parameter. 
// If the overloaded operator has an int parameter, the operator is a postfix overload. 
// If the overloaded operator has no parameter, the operator is a prefix overload.

class custom_int {
private: 
    int data;

public:
    custom_int();
    custom_int(int val);

    custom_int operator+ (const custom_int&);
    // custom_int operator+ (int, const custom_int&);
    custom_int operator+ (int);

    custom_int& operator= (const custom_int&);

    custom_int& operator+= (const custom_int&);
    custom_int& operator<< (const custom_int&);
    void print();
    operator int() const;   // This is needed to handle cases like (5 + custom_int)
};
