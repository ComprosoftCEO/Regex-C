// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//	regex_do_and_gruop.c - Do all of the function calls of everyting inside this group
//	  Returns the length of the matched string on success, or FUNC_FAILED on failure
#include <regex_p.h>


rIndex regex_do_and_group(pRegex_Obj_t regex, const char* str) {

	if (!(regex && str)) {return FUNC_FAILED;}

	//Call every sub-function using function pointers	
	rIndex i;
	rIndex tempLen, len = 0;
	for (i = 0; i < regex->d2.arrlen[ARRLEN_INUSE]; ++i) {
		tempLen = regex->d1.arr[i]->func(
			regex->d1.arr[i], str + len
		);

		if (tempLen == FUNC_FAILED) {return FUNC_FAILED;}
		len += tempLen;
	}

	return len;
}

