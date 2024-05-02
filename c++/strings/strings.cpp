#include <stdio.h>
#include <string.h>
#include <cstdlib>

#define MAX 12

int main() {

	//example 1
	// char str1[] = "Hello";
	// char str2[] = "World";
	// char str1[] = {'H','e','l','l','o'};
	// char str2[] = {'W','o','r','l','d'};
	// str1 = str2;
	// printf("%s %s \n", str1, str2);

	//example 2
	// char *p = "abcde";
	// printf("%lu %lu %lu \n", sizeof(p), strlen(p), sizeof("abcde") );

	//example 3
	char src[] = "test_string123";
	char src1[] = {'H','e','l','l','o','\0'};
	char *dest;
	printf("src length: %d\n", strlen(src));
	printf("src1 length: %d %s \n", strlen(src1), src1);
	dest = (char*) malloc (strlen(src));
	strcpy(dest, src);
	printf("%s\n", dest);
	printf("%s\n", src);
	free(dest);

	//example 4
	// char *str;
	// strcpy(str, "PRISM");
	// printf("%s\n", str);

	return 0;
}
