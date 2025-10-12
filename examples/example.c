#include <stdio.h>
#include <stdlib.h>
#include "../lib/da.h"
#include "../lib/da_util.h"


int main(int argc, char** argv){

	// Initialize an int array
	intVec2 vec = {0};
	da_log_info("Initialized int array 'vec'");


	// Add values 0..9 to the array and print values
	for(size_t i = 0; i < 10; i++){
		intVec2_append(&vec, i);	
	}
	
	da_log_info("Added values 0..9 to vec");
	da_log_info("Printing all values of vec");

	da_print_vec(vec.items, vec.n_items, sizeof(int), print_integer);

	// Remove elements from int array by value
	intVec2_rbv(&vec, 5);
	intVec2_rbv(&vec, 2);

	// Example of using return value of intVec2_rbv
	if(intVec2_rbv(&vec, 69420) != 0){
		da_log_error("Value 69420 not found!");
	}

	// Remove last element from int array
	intVec2_remove_last(&vec);
	da_log_info("Removed items 3 and 5 by value and the last value in array");

	// Print values again to show that the removal worked as expected
	da_log_info("Printing all values after removing some");
	da_print_vec(vec.items, vec.n_items, sizeof(int), print_integer);


	// Initialize a string array
	strVec2 strvec = {0};
	da_log_info("Initialized str array 'strvec'");


	// Add some strings to the array and print values
	strVec2_append(&strvec, "Hello World");
	strVec2_append(&strvec, "Another string :D!");
	da_log_info("Added some values to strvec");
	da_log_info("Printing all values of strvec");

	da_print_vec(strvec.items, strvec.n_items,
			sizeof(char*), print_string);

	// Remove the last element in string array and print again
	strVec2_remove_last(&strvec);
	da_log_info("Removed last element from string array");
	da_log_info("Printing all values of strvec");
	da_print_vec(strvec.items, strvec.n_items,
			sizeof(char*), print_string);

	strVec2_rbv(&strvec, "Hello World");
	strVec2_append(&strvec, "Third string");
	da_log_info("Removed string \"Hello World\" from strvec\n "
			"and added \"Third string\"");
	da_log_info("Printing all values of strvec");
	da_print_vec(strvec.items, strvec.n_items,
		sizeof(char*), print_string);
	
        return 0;
}
