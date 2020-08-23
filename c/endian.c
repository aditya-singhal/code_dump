#include <stdio.h>
#include <stdint.h>

uint32_t number = 0x01020304;
uint8_t* ptr = (uint8_t*)&number;


int main()
{

	if (*ptr == 0x01)
	{
		printf("Big Endian\n");
	}
	else
	{
		printf("Little Endian\n");
	}
	
	return 0;
}
