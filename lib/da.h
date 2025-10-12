#ifndef DA_H
#define DA_H

#include <limits.h> // INT_MAX, INT_MIN

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

#define da_array_size(vec) ((vec).n_items)

// Make sure we don't try to append values outside of the 32bit signed int range
#define intVec2_append(vec, x) do {		    				\
	long long _val = (long long)(x);					\
	if (_val > INT_MAX || _val < INT_MIN) {					\
	   fprintf(stderr, "Value out of range: %lld\n",   			\
			_val);							\
	    	exit(EXIT_FAILURE); 						\
	}					    				\
	intVec2_append_impl((vec), (int)_val); 					\
} while(0)
	

/* ----- integer array stuff ----- */

typedef void (*writer)(const void* item);


void print_integer(const void* item);
void print_string(const void* item);

/*
 * Print all elements of a vector
 * @Param vector (any data type)
 * @Param number of items in vector \\
 * Call da_array_size(vec) to get the number of items if unknown
 * @Param size of individual item (eg. sizeof(int) for an intVec2)
 * @Param function name that matches the vector data type \\
 * (eg. print_integer for intVec2, print_string for strVec2
 * @Return none
 */
void da_print_vec(const void* vec, size_t n_items, 
		size_t item_size, writer writer_func);	


/*
 * Append to the end (int vec)
 * Called by #intVec2_append macro
 * @Params intVec2, value to append
 * @Return none
 */
void intVec2_append_impl(intVec2* vec, int x);

/*
 * Remove last element (int vec) 
 * @Params intVec2
 * @Return 0 (success) : -1 (array is empty)
 */
void intVec2_remove_last(intVec2* vec);

/*
 * Remove element by value (int vec) 
 * @Params intVec2, value to remove
 * @Return 0 (success) : -1 (value not found) 
 */
int intVec2_rbv(intVec2* vec, int value);



/* ----- string array stuff ----- */


/* Append to the end (string vec) 
 * Same params as intVec2_append_impl()
 */
void strVec2_append(strVec2* vec, char* s);

/* Remove element by value (string vec) *
 * Same params as intVec2_rbv()
 */
void strVec2_rbv(strVec2* vec, const char* value);

/*
 * Remove last element (string vec) 
 * @Params strVec2
 * @Return 0 (success) : -1 (array is empty)
 */
int strVec2_remove_last(strVec2* vec);


/* ----- more to come soontm -----*/

#endif
