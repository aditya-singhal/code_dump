#include<stdio.h>
#include "static_check.h"

static unsigned int number = 10;

static void static_function()
{
    printf("I am a static function\n");
}

unsigned int* get_address_of_static_variable()
{
    printf("Address of static variable:%u\n", &number);
    return &number;
}

void print_static_variable()
{
    printf("value of static variable:%u\n", number );
}

fptr get_address_of_static_function()
{
	fptr __myfptr = &static_function;
	return __myfptr;
}
