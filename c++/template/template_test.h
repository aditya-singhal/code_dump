#include <iostream> 
using namespace std; 

template <typename T> 
class Array { 
private: 
	T *ptr; 
	int size; 
public: 
	Array(T arr[], int s); 
	void print(); 
};
