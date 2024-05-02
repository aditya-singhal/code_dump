// Test char* to int* and vice-versa


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

/*
int main() {
	Derived d1;
	Int i1;
	//Int *b1 = (Int*)(&d1);
	//Int *b1 = reinterpret_cast<Int*>(&d1);
	//Int *b2 = static_cast<Int*>(&d1);
	//Derived *d2 = dynamic_cast<Derived*>(&i1);
	Int *b3 = dynamic_cast<Int*>(&d1);
	return 0;
}
*/

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
*/

int main() 
{ 
    int a = 10; 
    char c = 'a'; 
  
    //int* q = (int*)&c;  // pass at compile time, may fail at run time 
    int* p = static_cast<int*>(&c); // Correct/C++ way. invalid static_cast from type 'char*' to type 'int*'
    int val = c;
	std::cout << "Value of q = " << *p << "\n"; 
    
    return 0; 
} 