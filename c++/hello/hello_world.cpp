#include <iostream>
using namespace std;

class abc{
	const int a = 100;
public:
	abc(){
		cout << "const a: " << a << "\n";
	}
};

class empty_class {
public:	
	int a = 20;
};

struct empty_struct {
	int a = 20;
};

int main(){
	int a = 7;
	int *ptr = &a;
	cout << "&a: " << &a << "\n";	//&a
	cout << "&ptr: " << &ptr << "\n";
	cout << "&*ptr: " << &*ptr << "\n";	//&a
	cout << "*&ptr: " << *&ptr << "\n";	//&a

	short int array[] = {5, 10, 15, 20, 25};
	short int *ptr1 = &array[1];
	short int *ptr2 = &array[2];
	cout << "ptr1: " << ptr1 << "\n";
	cout << "ptr2: " << ptr2 << "\n";
	cout << "ptr2 - ptr1: " << ptr2 - ptr1 << "\n";

	char* c = NULL;
	cout << "sizeof(c): " << sizeof(c) << "\n";	

	struct empty_struct e1;
	cout << "sizeof(e1): " << sizeof(e1) << "\n";	

	empty_class c1;
	struct empty_struct s1;
	cout << "c1.a: " << c1.a << "\n";	//&a
	cout << "s1.a: " << s1.a << "\n";	//&a

	//void main(){
	//...
	//static int i = initialize();
	//...
	//print i;
	//...
	//}

	//Suppose initialize function returns a value 20. What is the output?"

	std::cout << "Hello world!\n";
	return 0;
}
