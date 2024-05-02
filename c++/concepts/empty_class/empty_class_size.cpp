#include <iostream>

class empty{
public:
	empty(){}
	void bye();

	int& array = a;
	int a;
};

void empty::bye() {
	int a = 0;
}


int main(){
	empty obj;
	std::cout << "size of an empty class: " << sizeof(obj) << "\n";
/*
	obj.array[0] = 5;
	std::cout << "value: " << obj.array[0] << "\n";
	obj.array[1] = 2;
	std::cout << "value: " << obj.array[1] << "\n";
	obj.array[2] = 3;
	std::cout << "value: " << obj.array[2] << "\n";
*/
	// Both variable and its reference is pointing to the same memory location
	std::cout << "&: " << &obj.array << "\n";
	std::cout << "&: " << &obj.a << "\n";

	//std::cout << obj.arr << "\n";

	return 0;
}