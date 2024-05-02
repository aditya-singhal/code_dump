
#include <stdio.h>
#include <string.h>


int main() {
	int count = 9, t = 0;
	int n = (count+7)/8;

	switch(count % 8){
		case 0:
			printf("hello\n");
		
		default:
		printf("world\n");
	}
	
	return 0;
}
