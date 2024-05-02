#include "simple_list.h"

//This is used to print list data using object name
template <typename T> 
std::ostream& operator<<( std::ostream& os, simple_list<T> &list ) {
	list.print_list();
	return os;
}

int main() {
	simple_list<char> my_list;
	simple_list<char>::simple_iterator itr;

	my_list.push_end('b');
	my_list.push_end('c');
	my_list.push_end('d');
	my_list.push_end('e');
	my_list.push_front('a');
	//my_list.print_list();

	std::cout << "Print using for loop:\n";
	for (itr = my_list.begin(); itr != my_list.end(); ++itr) {
		std::cout << *itr << "  ";
	}

	itr = my_list.begin();
	itr++;
	++itr;
	itr+=2;
	std::cout << "\n\nInsert after ++itr(4 times) :\n";	
	itr = my_list.insert_after(itr,'f');
	
	std::cout << "Print using for loop:\n";
	for (itr = my_list.begin(); itr != my_list.end(); ++itr) {
		std::cout << *itr << "  ";
	}

	itr = my_list.begin();
	++itr;
	++itr;
	++itr;
	std::cout << "\n\nErase after ++itr(3 times) :\n";	
	itr = my_list.erase_after(itr);

	std::cout << "Print using for loop:\n";
	for (itr = my_list.begin(); itr != my_list.end(); ++itr) {
		std::cout << *itr << "  ";
	}

	std::cout << "\n\nPrint using << overloading :\n";
	std::cout << my_list;
	std::cout << "\n\n";

	return 0;
}
