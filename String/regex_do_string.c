// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//	regex_do_string.c - Compare string literals for the regular expression
#include <regex_p.h>


rIndex regex_do_string(pRegex_Obj_t regex, const char* str) {

	if (!(regex && str)) {return FUNC_FAILED;}

	size_t len = strlen(regex->d1.str);
	if (strncmp(regex->d1.str,str,len) == 0) {
		return (rIndex) len;
	}

	return FUNC_FAILED;	//Strings do not compare
}
