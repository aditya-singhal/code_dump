#include <iostream> 
using namespace std; 

// Base is an abstract class
class Base { 
public: 
    virtual void virtual_function(){
        std::cout << "Base class virtual function\n";
    }
    virtual void pure_virtual_function() = 0;
}; 

class Derived : public Base { 
public: 
    void virtual_function(){
        std::cout << "Derived class virtual function\n";
    }

    virtual void pure_virtual_function(){
        std::cout << "Pure Derived class virtual function\n";           
    }
}; 


// No need to define the pure virtual function of the Base class
// This class inherits the definition of pure_virtual_function from Derived class 
class Also_derived : public Derived { 
public: 
    void virtual_function(){
        std::cout << "Also_derived class virtual function\n";
    }
}; 

int main() {

    Base* b1_ptr = NULL;
    Derived* d1_ptr = NULL;
    
    Derived derived_obj;
    b1_ptr = static_cast<Derived*>(&derived_obj);
    b1_ptr->virtual_function();

    // Creating an object of an abstract class is not allowed
    // Base b1;

    Also_derived also;
    b1_ptr = static_cast<Derived*>(&also);
    b1_ptr->virtual_function();
    b1_ptr->pure_virtual_function();    // Derived class pure_virtual_function will get called

    return 0; 
} 
