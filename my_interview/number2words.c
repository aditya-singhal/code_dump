/**
 * \file  number2words.c
 * \brief This file is used to convert a number into words format
 * \purpose Interview assignment
 *
 * \author Aditya Singhal
 * \date 30/January/2018
 */

#include <stdint.h>
#include <stdio.h>

#define OUTPUT_BUFFER_SIZE		120

typedef struct {
	uint8_t value;
	uint8_t place;
}NumberPart_t;

const char* __value_in_words[20] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven",
									"twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
const char* __tens_in_words[9] = {"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
const char* __place_in_words[5] = {"hundred","thousand","lakh","crore","arab"};

static uint8_t __convert_number_to_words(uint32_t number, char* number_in_words);
static uint8_t __get_digit_count(uint32_t number);
static uint8_t __get_value_in_words(uint8_t value, char* value_in_words);
static uint8_t __get_place_in_words(uint8_t place, char* place_in_words);
static uint32_t __strlen(const char* str);
static int8_t __memcopy(void* dest, const void* src, uint32_t num);
static int8_t __memset(void* ptr, uint8_t value, uint32_t num);

int main() {
	uint32_t number = 0;
	int8_t status = 0;
	char result[OUTPUT_BUFFER_SIZE] = {0};
	
	while(1){
		printf("\nEnter number: ");
		status = scanf("%u",&number);
		if(status > 0){
			__convert_number_to_words(number,result);
			printf("%s\n",result);
			__memset(result,0,sizeof(result));
		}
		fflush(stdin);
		number=0;
	}
	return 0;
}

static uint8_t __convert_number_to_words(uint32_t number, char* number_in_words) {
	uint8_t digit_count=0;
	uint8_t place = 0;
	NumberPart_t parts[8];
	uint8_t parts_count = 0;
	uint8_t buffer_count = 0;
	uint8_t data_count = 0;
	
	if(number == 0) {
		data_count = __get_value_in_words(number, (number_in_words + buffer_count));
		buffer_count += data_count;
		return buffer_count;
	}
	
	digit_count = __get_digit_count(number);
	place = 1;
	//breaking number into parts(value and place) and storing in a struct
	while(number>0) {
		if((digit_count == place) || (place == 3)){
			parts[parts_count].value = number%10;
			parts[parts_count].place = place;
			number /= 10;
			place++;
		} else {
			parts[parts_count].value = number%100;
			parts[parts_count].place = place;
			number /= 100;
			place += 2;			
		}
		parts_count++;
	}
	
	//converting numbers into words and storing in a buffer
	while(parts_count){
		if(parts[parts_count-1].value != 0) {
			data_count = __get_value_in_words(parts[parts_count-1].value, (number_in_words + buffer_count));
			buffer_count += data_count;
			__memcopy(number_in_words + buffer_count," ",1);	//adding a space
			buffer_count += 1;
			data_count = __get_place_in_words(parts[parts_count-1].place,(number_in_words + buffer_count));
			buffer_count += data_count;
			__memcopy(number_in_words+buffer_count," ",1);	//adding a space
			buffer_count += 1;
		}
		parts_count--;
	}
	return buffer_count;
}

static uint8_t __get_digit_count(uint32_t number){
	uint8_t count=0;
	
	while(number>0) {
		number /= 10;
		count++;
	}
	return count;
}

static uint8_t __get_value_in_words(uint8_t value, char* value_in_words){
	uint8_t ones_place = 0;
	uint8_t tens_place = 0;
	uint8_t count =0;
	
	if(value > 99){
		return 0;
	}
	if(value <= 19){
		__memcopy(value_in_words, __value_in_words[value],__strlen(__value_in_words[value]));
		return __strlen(__value_in_words[value]);
	}
	
	ones_place = value%10;
	value /= 10;
	tens_place = value%10;
	if(tens_place != 0) {
		__memcopy(value_in_words, __tens_in_words[tens_place-1],__strlen(__tens_in_words[tens_place-1]));
		count = __strlen(__tens_in_words[tens_place-1]);
	}
	if(ones_place != 0) {
		__memcopy(value_in_words+count," ",1);	//adding a space
		count += 1;
		__memcopy(value_in_words+count, __value_in_words[ones_place],__strlen(__value_in_words[ones_place]));
		count += __strlen(__value_in_words[ones_place]);
	}
	return count;
}

static uint8_t __get_place_in_words(uint8_t place, char* place_in_words){
	uint8_t count = 0;
	
	switch(place){
		case 3: __memcopy(place_in_words, __place_in_words[0], __strlen(__place_in_words[0]));
				count = __strlen(__place_in_words[0]);
				break;
		case 4: __memcopy(place_in_words, __place_in_words[1], __strlen(__place_in_words[1]));
				count = __strlen(__place_in_words[1]);
				break;
		case 6: __memcopy(place_in_words, __place_in_words[2], __strlen(__place_in_words[2]));
				count = __strlen(__place_in_words[2]);
				break;
		case 8: __memcopy(place_in_words, __place_in_words[3], __strlen(__place_in_words[3]));
				count = __strlen(__place_in_words[3]);
				break;
		case 10: __memcopy(place_in_words, __place_in_words[4], __strlen(__place_in_words[4]));
				 count = __strlen(__place_in_words[4]);
				 break;
		default: count = 0;
				 break;
	}
	return count;
}

static uint32_t __strlen(const char* str) {
	if(str == 0) {
		return 0;
	}
	uint32_t index = 0;

	while(*(str + index) != 0){
		index++;
	}
	return index;
}

static int8_t __memcopy(void* dest, const void* src, uint32_t num) {
	if( (src == 0) || (dest == 0) || (num == 0) ) {
		return -1;
	}	
	uint32_t index = 0;

	for(index = 0; index < num; index++) {
		*(((uint8_t*)dest) + index) = *(((const uint8_t*)src) + index);
	}
	return 0;
}

static int8_t __memset(void* ptr, uint8_t value, uint32_t num) {
	if( (ptr == 0) || (num == 0) ) {
		return -1; 
	}
	uint32_t index = 0;

	for(index = 0; index < num; index++){
		*(((uint8_t*)ptr) + index) = value;
	}
	return 0;
}
