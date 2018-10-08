// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//	regex_do_or_gruop.c - Keep doing function calls to find the longest length
#include <regex_p.h>


rIndex regex_do_or_group(pRegex_Obj_t regex, const char* str) {

	if (!(regex && str)) {return FUNC_FAILED;}

	//Call every sub-function until first success	
	rIndex i;
	rIndex tempLen, len = FUNC_FAILED;
	for (i = 0; i < regex->d2.arrlen[ARRLEN_INUSE]; ++i) {
		tempLen = regex->d1.arr[i]->func(
			regex->d1.arr[i], str
		);

		if (tempLen != FUNC_FAILED) {
			//Find the longest length possible
			if ((len == FUNC_FAILED) || (tempLen > len)) {len = tempLen;}
		}
	}

	return len;
}
