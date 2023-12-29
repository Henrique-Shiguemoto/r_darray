#include <stdio.h>
#include "rdarray.h"

typedef struct rstruct{
	int a;
	double b;
	char c;
	short s;
} rstruct;

void PrintRStructArray(rdarray* array){
	printf("rdarray(rstruct): \n");
	for (int i = 0; i < array->length; ++i){
		rstruct* c_array = rdarray_at(array, i);
		printf("\t -> a = %d, b = %lf, c = %c, s = %d\n", c_array->a, c_array->b, c_array->c, c_array->s);
	}
}

void PrintIntArray(rdarray* array){
	printf("rdarray(int): \n");
	for (int i = 0; i < array->length; ++i){
		printf("\t - %d\n", *(int*)rdarray_at(array, i));
	}
}

int main(void) {
	// example with structs
	rdarray array = rdarray_create(sizeof(rstruct));
	
	// {1}
	rstruct a = {.a = 1, .b = 1, .c = '1', .s = 1};
	rdarray_push(&array, &a);
	PrintRStructArray(&array);

	// {2, 1}
	rstruct b = {.a = 2, .b = 2, .c = '2', .s = 2};
	rdarray_push_at(&array, &b, 0);
	PrintRStructArray(&array);

	// {2, 3, 1}
	rstruct c = {.a = 3, .b = 3, .c = '3', .s = 3};
	rdarray_push_at(&array, &c, 1);
	PrintRStructArray(&array);

	// {2, 3, 1, 4}
	rstruct d = {.a = 4, .b = 4, .c = '4', .s = 4};
	rdarray_push(&array, &d);
	PrintRStructArray(&array);

	// {2, 5, 3, 1, 4}
	rstruct e = {.a = 5, .b = 5, .c = '5', .s = 5};
	rdarray_push_at(&array, &e, 1);
	PrintRStructArray(&array);

	// {2, 5, 3, 4}
	rstruct f = {0};
	rdarray_pop_at(&array, &f, 3);
	PrintRStructArray(&array);

	// {5, 3, 4}
	rdarray_pop_at(&array, &f, 0);
	PrintRStructArray(&array);

	// {5, 3}
	rdarray_pop_at(&array, &f, array.length - 1);
	PrintRStructArray(&array);

	rdarray_delete(&array);

	// example with primitive data types

	rdarray int_array = rdarray_create(sizeof(int));

	// {1}
	int a_i = 1;
	rdarray_push(&int_array, &a_i);
	PrintIntArray(&int_array);

	// {1, 2}
	int b_i = 2;
	rdarray_push_at(&int_array, &b_i, int_array.length); //same as rdarray_push
	PrintIntArray(&int_array);

	// {1, 3, 2}
	int c_i = 3;
	rdarray_push_at(&int_array, &c_i, 1);
	PrintIntArray(&int_array);

	// {4, 1, 3, 2}
	int d_i = 4;
	rdarray_push_at(&int_array, &d_i, 0);
	PrintIntArray(&int_array);

	// {4, 1, 3, 2, 5}
	int e_i = 5;
	rdarray_push(&int_array, &e_i);
	PrintIntArray(&int_array);

	// {4, 1, 3, 5}
	int p = 0;
	rdarray_pop_at(&int_array, &p, 3);
	PrintIntArray(&int_array);

	// {4, 3, 5}
	rdarray_pop_at(&int_array, &p, 1);
	PrintIntArray(&int_array);

	// {4, 3}
	rdarray_pop(&int_array, &p);
	PrintIntArray(&int_array);

	// {3}
	rdarray_pop_at(&int_array, &p, 0);
	PrintIntArray(&int_array);

	// {}
	rdarray_pop(&int_array, &p);
	PrintIntArray(&int_array);

	rdarray_delete(&int_array);

	return 0;
}