// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_free_string.c - Release a regular expression string object from memory
#include <regex_p.h>

void regex_free_string(pRegex_Obj_t regex) {
    if (!regex) {return;}
    if (regex->type != REGEX_STRING) {return;}

    //Make sure to not free a short string
    if (regex->d1.str != regex->d2.short_str) {
        if (regex->d1.str) {free(regex->d1.str);}
    }

    free(regex);
}
