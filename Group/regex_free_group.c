// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_free_group.c - Release a group from memory
#include <regex_p.h>

void regex_free_group(pRegex_Obj_t regex) {
    if (!regex) {return;}
    if (!(regex->type == REGEX_AND_GROUP || regex->type == REGEX_OR_GROUP)) {
        return;
    }

    //Release all entries in the array
    if (regex->d1.arr) {
        rIndex i;
        for (i = 0; i < regex->d2.arrlen[ARRLEN_INUSE]; ++i) {
            regex_release((pRegex_t) regex->d1.arr[i]);
        }
        free(regex->d1.arr);
    }

    free(regex);
}
