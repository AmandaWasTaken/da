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

	for(size_t i = 0; i < vec.n_items; i++){
		printf("%i, ", vec.items[i]);
	}
	printf("\n");

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
	for(size_t i = 0; i < vec.n_items; i++){
		printf("%i, ", vec.items[i]);
	}
	printf("\n");


	// Initialize a string array
	strVec2 strvec = {0};
	da_log_info("Initialized str array 'strvec'");


	// Add some strings to the array and print values
	strVec2_append(&strvec, "Hello World");
	strVec2_append(&strvec, "Another string :D!");
	da_log_info("Added some values to strvec");
	da_log_info("Printing all values of strvec");

	for(size_t i = 0; i < strvec.n_items; i++){
		printf("%s\n", strvec.items[i]);
	}

	// Remove the last element in string array and print again
	strVec2_remove_last(&strvec);
	da_log_info("Removed last element from string array");
	da_log_info("Printing all values of strvec");
	for(size_t i = 0; i < strvec.n_items; i++){
		printf("%s\n", strvec.items[i]);
	}

	strVec2_rbv(&strvec, "Hello World");
	strVec2_append(&strvec, "Third string");
	da_log_info("Removed string \"Hello World\" from strvec\n "
			"and added \"Third string\"");
	da_log_info("Printing all values of strvec");
	for(size_t i = 0; i < strvec.n_items; i++){
		printf("%s\n", strvec.items[i]);
	}
        return 0;
}
