// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_new_group.c - Create a new group node for the regular expression
#include <regex_p.h>

pRegex_Obj_t regex_new_group(bool orGroup) {
    pRegex_Obj_t regex = malloc(sizeof(Regex_Obj_t));
    if (!regex) {return NULL; /* Malloc error */}

    regex->d1.arr = calloc(ARRLEN_INIT,sizeof(pRegex_Obj_t));
    if (!regex->d1.ptr) {/* Calloc failure */
        free(regex);
        return NULL;
    }
    regex->d2.arrlen[ARRLEN_ALLOC] = ARRLEN_INIT;
    regex->d2.arrlen[ARRLEN_INUSE] = 0;

    if (orGroup) {
        regex->type = REGEX_OR_GROUP;
        regex->func = regex_do_or_group;
 	} else {
        regex->type = REGEX_AND_GROUP;
		regex->func = regex_do_and_group;
    }

    return regex;
}
