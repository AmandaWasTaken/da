#define GREEN "\e[0;32m"
#define YELLOW	"\e[0;33m"
#define WHITE "\e[0;37m"
#define RED "\e[0;31m"

typedef enum {
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
} da_log_level;

void da_log(const char* msg, int log_level);
