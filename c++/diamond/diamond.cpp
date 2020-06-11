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
        a = 10; 
    } 
}; 
  
class C : virtual public A { 
public: 
    C() { 
        cout << "C constructor called!\n";
        a = 10; 
    } 
}; 
  
class D : public B, public C { 
public: 
    D() { 
        cout << "D constructor called!\n";
        a = 10; 
    } 
}; 
  
int main() { 
    A A_object; // object creation of class d 
    cout << "A = " << sizeof(A_object) << endl; 
    B B_object; // object creation of class d 
    cout << "B = " << sizeof(B_object) << endl; 
    C C_object; // object creation of class d 
    cout << "C = " << sizeof(C_object) << endl; 
    D D_object; // object creation of class d 
    cout << "D = " << sizeof(D_object) << endl; 
  
    return 0; 
} 
