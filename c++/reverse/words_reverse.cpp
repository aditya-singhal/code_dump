// C++ program to print reverse 
// of words in a string. 
#include<iostream> 

using namespace std; 

string wordReverse(string str) 
{ 
	int letter_index = str.length() - 1; 
	int start, end = letter_index + 1; 
	string result = ""; 
	
	while(letter_index >= 0) { 
		if(str[letter_index] == ' ') { 
			start = letter_index + 1; 
			while(start != end) {
				result += str[start++];
			}
			
			result += ' '; 
			end = letter_index; 
		} 
		letter_index--; 
	} 
	start = 0; 
	while(start != end) {
		result += str[start++]; 
	}
	
	return result; 
} 

// Driver code 
int main() { 
	string str = "I AM A GEEK";
	cout << wordReverse(str); 
	return 0; 
} 

