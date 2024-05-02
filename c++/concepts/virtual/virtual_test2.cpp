// C++ Program to Demonstrate the Concept of Dynamic binding
// with the help of virtual function
#include <iostream>
using namespace std;

class GFG {
public:
	void call_Function() // function that call print
	{
        cout << "Base call_Function" << endl;
		print();
	}
	void print() // the display function
	{
		cout << "Printing the Base class Content" << endl;
	}
};

class GFG2 : public GFG // GFG2 inherit a publicly
{
public:
	void print() // GFG2's display
	{
		cout << "Printing the Derived class Content" << endl;
	}
	virtual void call_Function() // function that call print
	{
        cout << "Derived call_Function" << endl;
		print();
	}
};

int main()
{
	GFG geeksforgeeks; // Creating GFG's object
	geeksforgeeks.call_Function(); // Calling call_Function
	GFG2 geeksforgeeks2; // creating GFG2 object
	geeksforgeeks2.call_Function(); // calling call_Function for GFG2 object


    // Testing run time polymorphism
    GFG* geeksforgeeks3;
    geeksforgeeks3 = &geeksforgeeks2;
    
    geeksforgeeks3->call_Function();    // This will call child's class function
    
    geeksforgeeks3->GFG::call_Function();   // To explicitely call the Base class function

	return 0;
}
