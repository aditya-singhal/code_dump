#include <iostream>

using namespace std;

class Parent
{
public:
    int a = 0;
    int b = 2;
};

class Child : public Parent
{
public:
    int b = 5;
};

int main() {
    Child* c = new Child();

    std::cout << "hello: " << c->b << endl; // It will print child's variable value
    std::cout << "hello: " << c->Parent::b << endl; // It will print parent's variable value

    return 0;
}