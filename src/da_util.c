#include <stdio.h>

#define RED 	"\e[0;31m"
#define GREEN 	"\e[0;32m"
#define YELLOW	"\e[0;33m"
#define WHITE 	"\e[0;37m"

typedef enum {
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
} da_log_level;

void da_log(const char* msg, int log_level){

	switch(log_level){
		case LOG_INFO:
		      fprintf(stdout, "%s[INFO]: %s%s\n",
				      GREEN, msg, WHITE);
		      break;
		case LOG_WARN:
		      fprintf(stdout, "%s[WARNING]: %s%s\n",
				      YELLOW, msg, WHITE);
		      break;
		case LOG_ERROR:
		      fprintf(stderr, "%s[ERROR]: %s%s\n",
				      RED, msg, WHITE);
		      break;
	}
}
