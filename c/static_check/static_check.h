#include<stdio.h>

typedef void (*fptr)(void);

unsigned int* get_address_of_static_variable();
void print_static_variable();
fptr get_address_of_static_function();

