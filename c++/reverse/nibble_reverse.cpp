#include <iostream>

void nibble_reverse( uint8_t number ){
	std::cout << "before: " << (int)number << "\n";
	for (int i=0; i<4; i++) {
		if (((1<<7) & number) != 0){
			number = number << 1;
			number |= 0x01;
		} else {
			number = number << 1;
		}

	}
	std::cout << "after: " << (int)number << "\n";
}

int main () {
	uint8_t number = 0xAB;
	
	nibble_reverse(number);
	return 0;
}
