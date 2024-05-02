#include <iostream>

void nibble_reverse( uint8_t number ){
	bool is_msb_set = false;

	std::cout << "before: " << (int)number << "\n";
	for (int i=0; i<4; i++) {
		if (((1<<7) & number) !=0 ){
			is_msb_set = true;
		} else {
			is_msb_set = false;
		}
		number = number << 1;
		if (is_msb_set == true) {
			number |= 0x01;	
		}
	}
	std::cout << "after: " << (int)number << "\n";
}

int main () {
	uint8_t number = 0xAB;
	
	nibble_reverse(number);
	return 0;
}
