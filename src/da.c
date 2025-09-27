#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

typedef struct {
	int* items;
	size_t capacity;
	size_t n_items;
} intVec2;

typedef struct {
	char** items;
	size_t capacity;
	size_t n_items;
} strVec2;

void intVec2_append_impl(intVec2* vec, int x){
	
	if(vec->n_items >= vec->capacity){
			if(vec->capacity == 0) vec->capacity = 256;
			else vec->capacity *= 2;
			vec->items = realloc(vec->items, 
					vec->capacity * sizeof(*vec->items));
		}
		vec->items[vec->n_items++] = x;
}

int intVec2_remove_last(intVec2* vec){

	if(vec->n_items == 0) return -1;

	vec->n_items--;
	
	int* res = realloc(vec->items, vec->n_items * sizeof(int));
	if(res || vec->n_items == 0) vec->items = res;
	return 0;
}

// Remove by value
int intVec2_rbv(intVec2* vec, int value){

	size_t idx = 0;
	while(vec->items[idx] != value){
		if(idx >= vec->n_items){
			fprintf(stderr,
				"Value %i not found in array\n", value);
			return -1;
		}
		idx++;
	}

	for(size_t i = idx; i < vec->n_items; i++){
		vec->items[i] = vec->items[i + 1];
	}
	
	vec->n_items--;
	return 0;
}

void strVec2_append(strVec2* vec, char* s){
	if(vec->n_items >= vec->capacity){
			if(vec->capacity == 0) vec->capacity = 256;
			else vec->capacity *= 2;
			vec->items = realloc(vec->items, 
					vec->capacity * sizeof(*vec->items));
		}
		vec->items[vec->n_items++] = s;
}

int strVec2_remove_last(strVec2* vec){

	if(vec->n_items == 0) return -1;
	vec->items[vec->n_items--] = '\0';
	return 0;	
}

void strVec2_rbv(strVec2* vec, const char* value){

	for(size_t i = 0; i < vec->n_items; i++){
		if(strcmp(vec->items[i], value) == 0){	
			for(size_t j = i; j < vec->n_items; j++){
				vec->items[j] = vec->items[j + 1];
			}

			vec->n_items--;

			char** tmp = realloc(vec->items,
					vec->n_items * sizeof(char *));
			if(tmp != NULL || vec->n_items != 0)
				vec->items = tmp;

			return;
		}
	}
}
