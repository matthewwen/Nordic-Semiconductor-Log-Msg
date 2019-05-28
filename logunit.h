#ifndef _LOG_UNIT_H
#define _LOG_UNIT_H

#include "SEGGER_RTT.h"

#define ANSI_RED      "\x1b[31m"
#define ANSI_GREEN    "\x1b[32m"
#define ANSI_YELLOW   "\x1b[33m"
#define ANSI_BLUE     "\x1b[34m"
#define ANSI_MAGENTA  "\x1b[35m"
#define ANSI_CYAN     "\x1b[36m"
#define ANSI_RESET    "\x1b[00m" 


#define log_int(val) _p_log_int((#val), (val), __LINE__);
void _p_log_int(char * msg, int num, int line_num);

#define log_str(msg) _p_log_str((#msg), msg, __LINE__);
void _p_log_str(char * name, const char * msg, int line_num);

#define _color(color, ...) do { \
   char * ANSI_LIST[6] = {ANSI_RED,  ANSI_GREEN,  ANSI_YELLOW,\
                          ANSI_BLUE, ANSI_MAGENTA, ANSI_CYAN};\
	char * ansi_color = ANSI_LIST[color];\
	SEGGER_RTT_printf(0, "%s", ansi_color); \
	SEGGER_RTT_printf(0, __VA_ARGS__); \
	SEGGER_RTT_printf(0, "%s\n", ANSI_RESET); \
}while(false);

#define log(...) do { \
	SEGGER_RTT_printf(0, __VA_ARGS__); \
	SEGGER_RTT_printf(0, '\n'); \
}while(false);

#define log_red(...) do { \
	_color(0, __VA_ARGS__);\
}while(false);\

#define log_green(...) do { \
	_color(1, __VA_ARGS__);\
}while(false);\

#define log_yellow(...) do { \
	_color(2, __VA_ARGS__);\
}while(false);\

#define log_blue(...) do { \
	_color(3, __VA_ARGS__);\
}while(false);\

#define log_magenta(...) do { \
	_color(4, __VA_ARGS__);\
}while(false);\

#define log_cyan(...) do { \
	_color(5, __VA_ARGS__);\
}while(false);\

#endif
