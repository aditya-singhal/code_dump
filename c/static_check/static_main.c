#include <stdio.h>
#include"static_check.h"

extern number;

int main ()
{
    //unsigned int * variable = NULL;
    
    //variable = get_address_of_static_variable();
    //printf("Address of static variable in main file:%u\n", variable );
    //print_static_variable();
    //*variable = 20;
    //print_static_variable();

    //printf( "number from main file:%d\n", number );
    //static_function();

	fptr test_fptr;
	test_fptr = get_address_of_static_function();
	test_fptr();

    return 0;
}

