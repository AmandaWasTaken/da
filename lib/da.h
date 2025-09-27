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


/*
 * Append to the end (int vec)
 * Called by #intVec2_append macro
 * @Params intVec2, value to append
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


/* Append to the end (string vec) */
void strVec2_append(strVec2* vec, char* s);

/* Remove element by value (string vec) */
void strVec2_rbv(strVec2* vec, const char* value);

/*
 * Remove last element (string vec) 
 * @Params strVec2
 * @Return 0 (success) : -1 (array is empty)
 */
int strVec2_remove_last(strVec2* vec);


/* ----- more to come soontm -----*/

#endif
