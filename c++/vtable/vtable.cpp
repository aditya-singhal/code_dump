#include <iostream>
using namespace std;

class Base
{
public:
    virtual void func(){
        cout << "func Inside Base class\n";
    }
    void func2(){
        cout << "func2 Inside Base class\n";
        func();
    }
};

class Foo : public Base
{
public:
    void func(){
        cout << "func Inside Derived class\n";
    }
};

int main() {
    Foo f;
    f.func2();

    return 0;
}
