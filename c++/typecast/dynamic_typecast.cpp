#include <iostream>
using namespace std;

class Base {
public:
    virtual void DoIt() = 0;    // pure virtual
    virtual ~Base() {};
};

class Foo : public Base
{
public:
    virtual void DoIt() { cout << "Foo\n"; }; 
    void FooIt() { cout << "Fooing It...\n"; }
};

class Bar : public Base
{
public :
    virtual void DoIt() { cout << "Bar\n"; }
    void BarIt() { cout << "baring It...\n"; }
};

Base* CreateRandom()
{
    if( (rand()%2) == 0 )
        return new Foo;
    else
        return new Bar;
}

int main()
{
    for( int n = 0; n < 10; ++n ) {
        Base* base = CreateRandom();

        base->DoIt();

        Bar* bar = dynamic_cast<Bar*>(base);
        Foo* foo = dynamic_cast<Foo*>(base);
        if( bar )
            bar->BarIt();
        if( foo )
            foo->FooIt();
    }
  return 0;

}
