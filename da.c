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

void intVec2_append_safe(intVec2* vec, int x){
	
	if(vec->n_items >= vec->capacity){
			if(vec->capacity == 0) vec->capacity = 256;
			else vec->capacity *= 2;
			vec->items = realloc(vec->items, 
					vec->capacity * sizeof(*vec->items));
		}
		vec->items[vec->n_items++] = x;
}

void intVec2_remove_last(intVec2* vec){

	if(vec->n_items == 0) return;

	vec->n_items--;
	
	int* res = realloc(vec->items, vec->n_items * sizeof(int));
	if(res || vec->n_items == 0) vec->items = res;

}

// Remove by value
void intVec2_rbv(intVec2* vec, int value){

	size_t idx = 0;
	while(vec->items[idx] != value) idx++;

	for(size_t i = idx; i < vec->n_items; i++){
		vec->items[i] = vec->items[i + 1];
	}
	
	vec->n_items--;
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

void strVec2_remove_last(strVec2* vec){

	if(vec->n_items == 0) return;
	vec->items[vec->n_items--] = '\0';
	
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
