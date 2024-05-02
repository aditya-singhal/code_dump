#include <iostream> 
using namespace std; 
  
class A { 
public: 
    long a; 
    A() { 
        cout << "A constructor called!\n";
        a = 10; 
    } 
};

class B : virtual public A { 
public: 
    B() { 
        cout << "B constructor called!\n";
        a = 20; 
    } 
}; 
  
class C : virtual public A { 
public: 
    C() { 
        cout << "C constructor called!\n";
        a = 30; 
    } 
}; 
  
class D : public B, public C { 
public: 
    D() { 
        cout << "D constructor called!\n";

        // Reference to a is ambiguous in this case. We have refer like B::a = 40, to be specific
        a = 40; //B::a = 40; 
    } 
}; 
  
int main() { 
    A A_object;
    cout << "A = " << sizeof(A_object) << endl; 
    B B_object;
    cout << "B = " << sizeof(B_object) << endl; 
    C C_object;
    cout << "C = " << sizeof(C_object) << endl; 
    D D_object;
    cout << "D = " << sizeof(D_object) << endl; 
  
    return 0; 
} 
