	#include <iostream>

class singleton {
	singleton();
	static singleton* instance;
public:
	static singleton* get_object();
	int value;
	void print();
};

singleton::singleton() {
	std::cout << "singleton class constructor\n";
	value = 100;
}

void singleton::print() {
	std::cout << "I am a singleton class, value: " << value << "\n";
}

singleton* singleton::get_object() {
	if (instance == NULL){
		instance = new singleton();
	} else {
		std::cout << "Instance already created\n";		
	}
	return instance;
}

singleton*::singleton::instance = NULL;

int main() {
	singleton* obj1 = singleton::get_object();
	if (obj1 != NULL){
		obj1->print();
	}

	singleton* obj2 = singleton::get_object();
	if (obj2 != NULL){
		obj2->print();
	}

	return 0;
}
