#include <iostream>

using namespace std;

int main() { 
	const int var = 10; // This will get stored in the RO memory region

    // Typecasting from const int* to int* is not allowed in C++, but gives only warning in the C language
	// int *ptr = static_cast<int*>(&var);
	// *ptr = 12; 

    // Typecasting is only allowed to const pointer
    const int *ptr = static_cast<const int*>(&var);
    cout << "var = " << *ptr << "\n";

    // Donot initialize to NULL otherwise compiler will throw an error when we tried to intitialize to actual address
    int data1 = 10; 
    int* const const_ptr = NULL; 
    // const_ptr = &data1;

	return 0; 
}

