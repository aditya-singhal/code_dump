//Static Class Members
#include<iostream>
using namespace std;

class A {
public:
    static int integer;
    const int integer_2;
    const int number = 5;
    const int value = 3;

    int getInt();
    A(int a);
    A();
    ~A();
};

int A::integer = 1;
//const int A::number = 2;

A::A(int a):integer_2(a) {
    cout << "param\n";
}

A::A():integer_2(1) {
    cout << "default\n";
}

A::~A() {
    cout << "param\n";
}


int A::getInt() {
    return integer;
}

int main() {
    A firstInstance;
    A secondInstance;
    
    cout<<"\nsize: = "<< sizeof(firstInstance) << "\n";
    cout<<"\nnumber: = "<< firstInstance.integer_2 << "\n";

    cout<<"\nfirstInstance = "<<firstInstance.getInt();
    cout<<"\nsecondInstance = "<<secondInstance.getInt();  
    cout<<"\n\nSet secondInstance.integer = 2";
    secondInstance.integer = 2;
    cout<<"\n\nfirstInstance = "<<firstInstance.getInt();
    cout<<"\nsecondInstance = "<<secondInstance.getInt(); 
    
    return 0;
}