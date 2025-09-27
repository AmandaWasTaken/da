#include <stdlib.h>
#include <stdio.h>
#include "../lib/da.h"
#include "../lib/da_util.h"


int main(int argc, char** argv){

	// checking that logs work
	da_log_info("Hello :D");
	da_log_error("Error :D");

	// creating an int vector
	intVec2 ivec = {0};
	intVec2_append(&ivec, 69);

	// haha wysi like and comment if you get joke
	intVec2_append(&ivec, 727); 
	
	for(size_t i = 0; i < ivec.n_items; i++){
		printf("%i\n", ivec.items[i]);
	} 

	da_log_info("Initializing str vector");
	strVec2 svec = {0};
	strVec2_append(&svec, "Hello");
	strVec2_append(&svec, "FAGGOT!!!");
	da_log_info("Added values to str vector");
	for(size_t i = 0; i < svec.n_items; i++){
		printf("%s\n", svec.items[i]);
	}

	da_log_info("Exiting. . .\n");
        return 0;
}





