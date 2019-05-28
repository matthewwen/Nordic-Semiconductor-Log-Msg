#include "logunit.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char * _remove_space(char * msg);

char * _remove_space(char * msg) {
	for (;isspace(*msg); msg = msg + 1) {}
	return msg;
}

void _p_log_int(char * name, int num, int line_num) {
	name        = _remove_space(name);
	bool is_num = (*name >= '0' && *name <= '9') || *name == '-';

	if (is_num) {
		SEGGER_RTT_printf(0, "Line Number: %d, Value: %d\n", line_num, num);
	}
	else {
		SEGGER_RTT_printf(0, "Line Number: %d, Name: %s, Value: %d\n", line_num, name, num);
	}
}

void _p_log_str(char * name, const char * msg, int line_num) {
	name        = _remove_space(name);
	bool is_str = *name == '"';
	if (is_str) {
		SEGGER_RTT_printf(0, "Line Number: %d, MSG: %s\n", line_num, msg);
	}
	else {
		SEGGER_RTT_printf(0, "Line Number: %d, Name: %s, MSG: %s\n", line_num, name, msg);
	}
}
