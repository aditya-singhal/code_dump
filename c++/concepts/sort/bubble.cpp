#include <iostream>
#include <stdint.h>

void bubble_sort(int arr[], int size){
	int temp = 0;

	std::cout << "\nbubble_sort: " << "\n";
	//std::cout << "size: " << sizeof(arr) << "\n";
	for (int i=0; i<size; i++) {
		for (int j=0; j< (size-1); j++) {
			if (arr[j] > arr[j+1]) {
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			} else {
				//No swapping
			}
		}
	}

	for (int i=0; i<size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}


int main(int argc, char const *argv[]) {
	uint32_t size = 0;
	int array[] = {2,3,1,5,0,3,1,9,10,22,11};
	
	for (int i=0; i<11; i++){
		std::cout << array[i] << " ";
	}

	bubble_sort(array,11);
	return 0;
}