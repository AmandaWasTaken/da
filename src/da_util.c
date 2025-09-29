#include <stdio.h>

#define RED 	"\e[0;31m"
#define GREEN 	"\e[0;32m"
#define WHITE 	"\e[0;37m"


void da_log_info(const char* __restrict info){
	fprintf(stdout, "%s[INFO]:  %s%s\n",
			GREEN, WHITE, info);
}

void da_log_error(const char* __restrict err){
	fprintf(stdout, "%s[ERROR]: %s%s\n",
			RED, WHITE, err);
}
