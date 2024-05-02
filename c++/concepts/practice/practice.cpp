#include <iostream>

void func(int A[], int B[], int size) {
	int temp = 1;
	for (int i=0; i<size;i++){
		for (int j=0; j<size;j++){
			if (i != j){
				temp = temp * A[j];
			}
		}
		B[i] = temp;
		temp = 1;
	}
	for (int i=0; i<size;i++){
		std::cout << B[i] << "\n";
	}
}

int main() {
	int A[4] = {2, 1, 5, 9};
	int B[4];
	func(A, B, 4);
	return 0;
}