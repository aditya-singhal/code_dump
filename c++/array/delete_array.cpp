#include <iostream>

class hello {
public:
	hello(){
		std::cout << "ctr called\n";
	}
	~hello(){
		std::cout << "dtr called\n";
	}
};

 
int main() {

	hello *array = new hello[5];

	delete[] array;

	// array[0] = 1;
	// array[1] = 2;
	// array[2] = 3;
	// array[3] = 4;
	// array[4] = 5;

 //    std::cout << "Value of ptr1 = " << array[0] << "\n"; 
 //    std::cout << "Value of ptr2 = " << array[1] << "\n"; 
 //    std::cout << "Value of ptr3 = " << array[2] << "\n"; 
 //    std::cout << "Value of ptr4 = " << array[3] << "\n"; 
 //    std::cout << "Value of ptr5 = " << array[4] << "\n"; 

	std::cout << "Hello world!\n";
	return 0;
}
