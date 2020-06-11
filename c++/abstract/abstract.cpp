#include <iostream> 
using namespace std; 

class Base { 
public: 
    virtual void virtual_function(){
        std::cout << "Base class virtual function\n";
    }
    virtual void pure_irtual_function() = 0;
}; 

class Derived : public Base { 
public: 
    void virtual_function(){
        std::cout << "Derived class virtual function\n";
    }

    virtual void pure_irtual_function(){
        std::cout << "Pure Derived class virtual function\n";           
    }
}; 

// class Also_derived : public Derived { 
// public: 
//     void virtual_function(){
//         std::cout << "Also_derived class virtual function\n";
//     }
// }; 

int main() {

    Base* b1_ptr = NULL;
    Derived* d1_ptr = NULL;
    
    Derived also;
    d1_ptr = static_cast<Derived*>(&also);
    d1_ptr->virtual_function();

    Base b1;

    return 0; 
} 
