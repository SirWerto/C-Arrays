

#ifndef ARRAY_H_
#define ARRAY_H_


//DEFINES
#define BUFF 10

//STRUCT
typedef struct s_array array;


//FUNCTIONS

//Create and destroy
array * new(size_t d_str);

void destroy(array * a);

//Modifie
bool add(array * a, void * str);	//Add an element at the end

bool remove_o(array * a, void * str);	//Remove the first equal element

void * remove_i(array * a, int index);	//Remove the i element

//Equals
bool equal_o(void * str1, void * str2, size_t size);

bool equal(array * a1, array * a);

//Getters
size_t size(array * a);

bool isempty(array * a);

void * get(array * a, size_t i);

//Sort
void sort(array * a, bool (*compare)(void * str1, void * str2));

//Erros
void * AError(void * e, char * s);

#endif // ARRAY_H_
