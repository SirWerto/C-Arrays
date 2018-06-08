

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//DEFINES
#define BUFF 10

//STRUCT
typedef struct s_array array;

/*typedef struct s_array{
	size_t n;	//Number of actual elements
	size_t buff;	//Diff betwin de array and n
	size_t nr;	//Real dimension of the array
	size_t dstr;	//Dimension of the struct
	void * ar;	//The array
}s_array;*/


//FUNCTIONS

//Create and destroy
array * new(size_t d_str);

void destroy(array * a);

//Modifie
bool add(array * a, void * str);	//Add an element at the end

void * remove_o(array * a, void * str);	//Remove the first equal element

void * remove_i(array * a, int index);	//Remove the i element

//Equals
bool equal_o(void * str1, void * str2, size_t size);

bool equal(array * a1, array * a);

//Getters
size_t size(array * a);

bool isempty(array * a);

void * get(array * a, size_t i);

//Erros
void * AError(void * e, char * s);

#endif // ARRAY_H_
