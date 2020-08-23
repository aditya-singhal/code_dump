// A Simple C++ program to reverse a string 
//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std; 

void swap_char(char& a, char& b){
	a = a + b;
	b = a - b;
	a = a - b;
}

// Function to reverse a string 
void reverseStr(string& str) { 
	int n = str.length(); 

	// Swap character starting from two 
	// corners 
	for (int i = 0; i < n / 2; i++) {
		swap_char(str[i], str[n - i - 1]); 
	}
} 

// Driver program 
int main() 
{ 
	string str = "geeksforgeeks"; 
	reverseStr(str); 
	cout << str << "\n"; 
	return 0; 
} 


