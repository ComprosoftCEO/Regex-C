// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_new_string.c - Create a new regex string node
#include <regex_p.h>

pRegex_Obj_t regex_new_string(const char* str, size_t len) {

    pRegex_Obj_t regex = malloc(sizeof(Regex_Obj_t));
    if (!regex) {return NULL; /* Malloc error */}

    regex->type = REGEX_STRING;
    if (len <= SHORT_STR_LEN) {

        //Copy into the short string buffer
        strncpy(regex->d2.short_str,str,len);
        regex->d1.str = regex->d2.short_str;

    } else {

        //Allocate a new string buffer
        regex->d1.str = (char*) calloc(len+1,sizeof(char));
        if (!regex->d1.str) {
            free(regex);
            return NULL;
        }
        strncpy(regex->d1.str,str,len);
    }

    regex->d1.str[len+1] = 0;   /*Null terminate */
    return regex;
}
