// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_new_char_class.c - Parse the char class data into a string
#include <regex_p.h>

pRegex_Obj_t regex_new_char_class(const char* char_data) {
    if (!char_data) {return NULL;}
    if (!(*char_data == '[')) {return NULL;}

    char allowed[127] = ALL_CHARS_PADDING ALL_CHARS;



}
