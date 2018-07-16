// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_add_group.c - Add a regex object into a group
#include <regex_p.h>

//Add a sub object to this group
bool regex_add_group(pRegex_Obj_t regex, pRegex_Obj_t to_add) {
    if (!(regex && to_add)) {return false;}
    if (!(regex->type == REGEX_AND_GROUP || regex->type == REGEX_OR_GROUP)) {
        return false;
    }

    //When to resize the array
    if (regex->d2.arrlen[ARRLEN_INUSE] >= regex->d2.arrlen[ARRLEN_ALLOC]) {
        pRegex_Obj_t new_ptr = realloc(regex->d1.ptr,
                                       (regex->d2.arrlen[ARRLEN_ALLOC] + ARRLEN_INC) * sizeof(Regex_Obj_t));
        if (!new_ptr) {return false;}

        regex->d1.ptr = new_ptr;
        regex->d2.arrlen[ARRLEN_ALLOC]+=ARRLEN_INC;
    }

    regex->d1.arr[regex->d2.arrlen[ARRLEN_INUSE]] = to_add;
    regex->d2.arrlen[ARRLEN_INUSE]+=1;
    return true;
}
