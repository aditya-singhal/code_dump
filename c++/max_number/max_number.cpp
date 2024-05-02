#include <iostream>
#include <math.h> 

#define MIN_NUMBER  pow(2,31)

int array[10] = {10,-1,-2,-3,-5,2,4,5,10,0};
//int array[10] = {10,10,10,10,10,10,10,10,10,10};

int main() {
    int max = MIN_NUMBER;
    int second_max = MIN_NUMBER;

    for (int i=0; i<10; i++) {
        if(array[i] > max) {
            second_max = max;
            max = array[i];
        }
        if ((array[i] > second_max) && (array[i] < max)) {
            second_max = array[i];
        }
    }

    std::cout << "max number: " << max << "\n";
    if (second_max == MIN_NUMBER) {
        std::cout << "second max number not present!\n";
    } else {
        std::cout << "second max number: " << second_max << "\n";
    }

    return 0;
}
