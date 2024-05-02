#include <iostream>

class my_vector {
	int *ptr;

public:
	my_vector(int number);
	int& operator[](int index);
};
