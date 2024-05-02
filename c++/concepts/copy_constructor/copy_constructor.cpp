// CPP Program to demonstrate the use of copy constructor
// and assignment operator

#include <iostream>
#include <stdio.h>

using namespace std;

class Test {
public:
	Test() {}
	
    Test(const Test& t) {
		cout << "Copy constructor called " << endl;
	}

	Test& operator=(const Test& t) {
		cout << "Assignment operator called " << endl;
		return *this;
	}
};

int main() {
	Test t1, t2;
	t2 = t1;    // t2.operator=(t1);
	Test t3 = t1;   // Test t3(t1);

	return 0;
}
