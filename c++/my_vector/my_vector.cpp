#include "my_vector.h"

my_vector::my_vector( int number ) {
	ptr = new int[number];
	std::cout << "size: " << sizeof(ptr) << "\n";
	//ptr[5] = 5;
}

int& my_vector::operator[]( int index ) {
	return ptr[index];
}

int main() {
	int a = 0;
	my_vector v1(100);
	v1[5] = 6;
	a = v1[5];
	std::cout << "v1[5]: " << a << "\n";
	return 0;
}
