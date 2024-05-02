#include <stdio.h>

int main() {
	// char str1[] = "Hello";
	// char str2[] = "World";
	char str1[] = {'H','e','l','l','o','\0'};
	char str2[] = {'W','o','r','l','d','\0'};
	//str1 = str2;
	printf ("sizeof str1: %x\t sizeof str2: %x\n", sizeof(str1), sizeof(str2));
	printf("%s %s \n", str1, str2);

    return 0;
}