#include <iostream> 
#include "template_test.h"
using namespace std; 
#include <string>

template <typename T> 
Array<T>::Array(T arr[], int s) { 
	ptr = new T[s]; 
	size = s; 
	for(int i = 0; i < size; i++) 
		ptr[i] = arr[i]; 
} 

template <typename T> 
void Array<T> :: print() { 
	for (int i = 0; i < size; i++) {
		cout<<" "<<*(ptr + i); 
	}
	cout << endl; 
} 

template <typename T1>
void destroy(T1* &p) {
	cout<< "Destroy " << "\n";
	delete p;
	p = 0; 
}

template<int max, int min, typename T>
T limit(T val) {
	// //assert(min > max);
	if (val< min){
		return min;
	} else if (val> max){ 
		return max;
	} else {
		return val;
	}
}

int main() {
	string *msg_ptr = new string("Hello");
	destroy<string>(msg_ptr);
	
	int v = 0;
	cin >> v;
	cout<< "Limit value: " << limit<15,-3>(v) <<endl;
	//cout<< "Limit value: " << limit(v) <<endl;
	
	return 0;
}
