// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_prepare.c - Convert a regular expression string into a regex object
#include <regex_p.h>

pRegex_t regex_prepare(const char* exp) {

    pRegex_Obj_t regex;
    if (!exp) {return NULL; /* Bad string */}

    regex = regex_new_group(false);
    if (!regex) {return NULL; /* Malloc error */}

    char c;
    const char* str_start = exp;
    size_t str_len = 0;
    rIndex index = 0;
    while((c = str_start[index])) {
        switch(c) {

            default:
                str_len+=1;
                break;
        }
    }

    if (str_len > 0) {
//        regex_add_group()
    }

error:
    if (regex) {regex_release(regex);}
    return NULL;
}
