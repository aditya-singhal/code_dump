#include <iostream>
#include <stdint.h>


bool substr_search(std::string str, std::string sub_str){
	uint32_t count = 0;

	for (int i=0; i<=(str.length()-sub_str.length());i++){
		for (int j=0; j<sub_str.length();j++){
			if( str[i+j] == sub_str[j]) {
				count++;
				if (sub_str.length() == count){
					return true;
				}
			} else {
				count = 0;
				break;
			}
		}
	}
	return false;
}

int main(){
	std::cout << "Is sub_str found: " << substr_search("hello", "oo") << "\n";
	std::cout << "Is sub_str found: " << substr_search("hello", "elm") << "\n";
	std::cout << "Is sub_str found: " << substr_search("helloworld", "owo") << "\n";
	std::cout << "Is sub_str found: " << substr_search("helloworld", "owd") << "\n";
	std::cout << "Is sub_str found: " << substr_search("helloworld", "helloworld") << "\n";
	std::cout << "Is sub_str found: " << substr_search("h", "helloworld") << "\n";
	std::cout << "Is sub_str found: " << substr_search("h", "h") << "\n";
	std::cout << "Is sub_str found: " << substr_search("h", "hello") << "\n";
}
