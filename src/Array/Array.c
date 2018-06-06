
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Array.h"

//STRUCT
typedef struct s_array{
	size_t n;	//Number of actual elements
	size_t buff;	//Diff betwin de array and n
	size_t nr;	//Real dimension of the array
	size_t dstr;	//Dimension of the struct
	void * ar;	//The array
}s_array;



//FUNCTIONS

array * new(size_t d_str){
	array * a =(array*) malloc(sizeof(array));
	if(!a)
		return NULL;
	a->ar = malloc(d_str*BUFF);
	if(!a->ar){
		free(a);
		return NULL;}

	a->n = 0;
	a->buff = BUFF;
	a->nr = BUFF;
	a->dstr = d_str;
return a;
}

void destroy(array * a){
	if(!a)
		return;
	if(!a->ar)
		free(a);
		a = NULL;
		return;
	free(a->ar);	
	a->ar = NULL;	//Proof
	free(a);
	a = NULL;
}

bool add(array * a, void * str){	//Add an element at the end
	if(!a || !a->ar || !str || a->dstr != sizeof(&str))
		return false;
	if(a->buff == 0){
		a->ar = realloc(a->ar, a->dstr*(a->nr+BUFF));
		if(!a->ar)
			return false;
		a->nr += BUFF;
		a->buff += BUFF;
	}
	unsigned char * point =(unsigned char*) a->ar;
	point += a->n * a->dstr;
	if(!(memcpy(point, str, a->dstr)))
		return false;
	a->n++;
	a->buff--;

return true;}	

void * remove_o(array * a, void * str){

return NULL;}	

void * remove_i(array * a, int index){
return NULL;}

size_t size(array * a){
	if(!a || !a->ar)
		return 0;
return a->n;
}


//size_t size(array * a){
	//return (a || a->ar)?a->n:0;
//}

bool isempty(array * a){
	return (a && a->ar)? (a->n): false;
}



void * get(array * a, size_t i){
	if(!a || !a->ar || i >= a->n)
		return NULL;
	unsigned char * point =(unsigned char*) a->ar;
	point += i * a->dstr;
	
return point;
}

bool equal_o(void * str1, void * str2, size_t size){
	if(!str1 || !str2 || size == 0)
		return false;
	unsigned char *p1 = str1, *p2 = str2;
	for(int i = 0; i < size; i++, p1++, p2++){
		if(*p1 != *p2)
			return false;
	}
return true;
}

bool equal(array * a1, array * a2){
	if(!a1 || !a2 || a1->n != a2->n || a1->dstr != a2->dstr)
		return false;
	unsigned char *p1 = a1->ar, *p2 = a2->ar;
	int size = a1->n * a1->dstr;
	for(int i = 0; i < size; i++, p1++, p2++){
		if(*p1 != *p2)
			return false;
	}

return true;
}



void * AError(void * e, char * s){
	printf("\nERROR: %s ", s);
return e;
}



