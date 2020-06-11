#include <iostream>

int main() {
	int prev = 0;
	int current = 1;
	int next = 0;

	for (int i=0; i<50;i++){
		std::cout << current << "\n";
		next = prev + current;
		prev = current;
		current = next;
	}

	while(1);
	return 0;
}