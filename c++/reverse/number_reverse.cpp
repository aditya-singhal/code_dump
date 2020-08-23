#include <iostream>
#include <stdint.h>
#include <math.h>
#include <bitset>

void reverse(uint32_t number){
	uint32_t arr[10] = {0};
	uint32_t count = 0;
	uint32_t index = 0;

	std::cout << "Enter number: \n";
	std::cin >> number;

	while(number){
		arr[count] = number % 10;
		number = number / 10;
		count++;
	}
	while(count){
		number += arr[index] * pow(10,count-1);
		count--;
		index++;
	}

	std::cout << "Final number: "<< number << "\n";	
}

bool even_number(uint32_t number){
	if ( (number % 2 ) == 0){
		std::cout << "Yes!\n";
		return true;
	} else {
		std::cout << "No!\n";
		return false;
	}
}

void swap_bits(uint32_t number, uint8_t bit1, uint8_t bit2){
	uint8_t bit_value1 = 0;
	uint8_t bit_value2 = 0;

	std::cout << "number: "<< std::bitset<32>(number) << "\n";
	bit_value1 = (number >> bit1) & 0x01;
	bit_value2 = (number >> bit2) & 0x01;
	if(bit_value1 == 1){
		number |= ( 1<<bit2);
	} else {
		number &= ~( 1<<bit2);
	}
	if(bit_value2 == 1){
		number |= (1<<bit1);
	} else {
		number &= ~(1<<bit1);
	}
	std::cout << "number: "<< std::bitset<32>(number) << "\n";	
}

struct A {
	int x;
	char *str = "hello"; 
};

bool string_reversal(std::string str){
	uint8_t length = 0;

	length = str.length();
	for (int i=0; i < length/2;i++){
		swap(str[i],str[length-i-1]);
	}
}

int main(){
	uint32_t number = 0;

	std::cout << "Enter number: \n";
	std::cin >> number;

	//reverse(number);
	//even_number(number);
	//swap_bits(number, 7,6);
	A a_obj;
	A *a_ptr = &a_obj;

	a_obj.x = number;
	std::cout << "x: " << a_obj.x << "\n";
	std::cout << "x: " << a_ptr->x << "\n";
	std::cout << "str: " << a_obj.str << "\n";
	std::cout << "str: " << a_ptr->str << "\n";

	return 0;
}
