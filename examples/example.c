#include <stdio.h>
#include <stdlib.h>
#include "../lib/da.h"
#include "../lib/da_util.h"


int main(int argc, char** argv){

	// Initialize an int array
	intVec2 vec = {0};
	da_log("Initialized int array 'vec'", LOG_INFO);


	// Add values 0..9 to the array and print values
	for(size_t i = 0; i < 10; i++){
		intVec2_append(&vec, i);	
	}
	
	da_log("Added values 0..9 to vec", LOG_INFO);
	da_log("Printing all values of vec", LOG_INFO);

	da_print_vec(vec.items, vec.n_items, sizeof(int), print_integer);

	// Remove elements from int array by value
	intVec2_rbv(&vec, 5);
	intVec2_rbv(&vec, 2);

	// Example of using return value of intVec2_rbv
	if(intVec2_rbv(&vec, 69420) != 0){
		da_log("Value 69420 not found!", LOG_WARN);
	}

	// Remove last element from int array
	intVec2_remove_last(&vec);
	da_log("Removed items 3 and 5 by value and the last value in array", LOG_INFO);

	// Print values again to show that the removal worked as expected
	da_log("Printing all values after removing some", LOG_INFO);
	da_print_vec(vec.items, vec.n_items, sizeof(int), print_integer);


	// Initialize a string array
	strVec2 strvec = {0};
	da_log("Initialized str array 'strvec'", LOG_INFO);


	// Add some strings to the array and print values
	strVec2_append(&strvec, "Hello World");
	strVec2_append(&strvec, "Another string :D!");
	da_log("Added some values to strvec", LOG_INFO);
	da_log("Printing all values of strvec", LOG_INFO);

	da_print_vec(strvec.items, strvec.n_items,
			sizeof(char*), print_string);

	// Remove the last element in string array and print again
	strVec2_remove_last(&strvec);
	da_log("Removed last element from string array", LOG_INFO);
	da_log("Printing all values of strvec", LOG_INFO);
	da_print_vec(strvec.items, strvec.n_items,
			sizeof(char*), print_string);

	strVec2_rbv(&strvec, "Hello World");
	strVec2_append(&strvec, "Third string");
	da_log("Removed string \"Hello World\" from strvec\n "
			"and added \"Third string\"", LOG_INFO);
	da_log("Printing all values of strvec", LOG_INFO);
	da_print_vec(strvec.items, strvec.n_items,
		sizeof(char*), print_string);
	
        return 0;
}
