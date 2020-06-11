#include <iostream> 
using namespace std; 


#include <iostream> 
#include <string> 
using namespace std; 

class Int { 
    int x; 
  
public:
	Int(){
		cout << "Ctor called" << endl; 
	}
	~Int(){
		cout << "Dtor called" << endl; 
	}

    // Int(int x_in = 0) : x{ x_in } { 
    //     cout << "Conversion Ctor called" << endl; 
    // } 
    operator string() { 
        cout << "Conversion Operator" << endl; 
        // return to_string(x); 
    }
    operator char() { 
        cout << "float Conversion Operator" << endl; 
        return float(x); 
    }
}; 

class Derived : public Int{

};

int main() {
	Derived d1;
	Int i1;
	//Int *b1 = (Int*)(&d1);
	//Int *b1 = reinterpret_cast<Int*>(&d1);
	Int *b2 = dynamic_cast<Int*>(&d1);
	Derived *d2 = static_cast<Derived*>(1);
	//Int *b3 = dynamic_cast<Int*>(&d1);

	return 0;
}


/*
int main() {
    char val = 0;

	Int obj(3);
    val = static_cast<char>(obj);

    // string str = obj;
    // obj = static_cast<Int>('a'); 
    // string str2 = static_cast<string>(obj); 
    // obj = static_cast<Int>(30); 
    return 0; 
} 


/*
int main() 
{ 
    int a = 10; 
    char c = 'a'; 
  
    // pass at compile time, may fail at run time 
    //int* q = (int*)&c;  
    int* p = static_cast<int*>(&c); 
    int val = c;

	std::cout << "Value of q = " << *p << "\n"; 
    
    return 0; 
} 
*/