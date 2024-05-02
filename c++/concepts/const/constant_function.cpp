// C++ program to demonstrate the constant function
// https://www.geeksforgeeks.org/const-keyword-in-cpp/

#include <iostream>
using namespace std;

class Test {
	int value;

public:
	Test(int v = 0) { value = v; }

	// We get compiler error if we add a line like "value = 100;" in this function.
    // When a function is declared as const, it can be called on any type of object, const object as well as non-const objects.
	int get_value() const { 
        return value; 
    }

	// a nonconst function trying to modify value
	void set_value(int val) { 
        value = val; 
    }
};

// Driver Code
int main()
{
    // Whenever an object is declared as const, it needs to be initialized at the time of declaration. 
    // However, the object initialization while declaring is possible only with the help of constructors
	Test t(20);

	// non-const object invoking const function, no error
	cout << t.get_value() << endl;

    // An object declared as const cannot be modified and hence, can invoke only const member functions as
    // these functions ensure not to modify the object.
	const Test t_const(10);

	// const object invoking const function, no error
	cout << t_const.get_value() << endl;

	// const object invoking non-const function, CTE
	// t_const.set_value(15);

	// non-const object invoking non-const function, no error
	t.set_value(12);
	cout << t.get_value() << endl;

	return 0;
}
