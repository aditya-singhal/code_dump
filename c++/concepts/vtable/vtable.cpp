#include <iostream>
using namespace std;

// vTable
// The vTable, or Virtual Table, is a table of function pointers that is created by the compiler to support dynamic polymorphism.
// Whenever a class contains a virtual function, the compiler creates a Vtable for that class.
// Each object of the class is then provided with a hidden pointer to this table, known as Vptr.
// The Vtable has one entry for each virtual function accessible by the class. 
// These entries are pointers to the most derived function that the current object should call.
// There is a single vtable for each class

// vptr
// The virtual pointer or _vptr is a hidden pointer that is added by the compiler as a member of the class
// to point to the VTable of that class

class Base {
public:
    virtual void func(){
        cout << "func Inside Base class\n";
    }
    void func2(){
        cout << "func2 Inside Base class\n";
        func();
    }
};

class Foo : public Base {
public:
    void func(){
        cout << "func Inside Derived class\n";
    }
};

int main() {
    Foo f;
    f.func2();

    cout << "Base size: " << sizeof(Base) << endl;

    // _vptr is added by the compiler when there is a virtual function inside a class
    cout << "Derived size: " << sizeof(f._vptr) << endl;

    return 0;
}
