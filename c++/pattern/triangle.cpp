#include <iostream>

void print_triangle( int height ) {

	for (int row = height; row >= 1; row--) {
		for (int column=1; column <= height;column++) {
			if (column < row ) {
				printf(" ");
			} else {
				printf("* ");
			}
		}
		printf ("\n");
	}
}

int main() {
	print_triangle(30);

	return 0;
}
