// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_release.c - Free a regular expression object from memory
#include <regex_p.h>

void regex_release(pRegex_t r) {

    pRegex_Obj_t regex = (pRegex_Obj_t) r;
    if (!regex) {return;}

    //TODO: Add other freeing code here...

    free(regex);
}
