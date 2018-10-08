// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex_p.h - Private header for all internal regular expression functions
#ifndef PRIVATE_REGEX_HEADER
#define PRIVATE_REGEX_HEADER

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


//All types of regular expression nodes
typedef enum {
    REGEX_NULL,
    REGEX_AND_GROUP,    //Group of items that all need to match
    REGEX_OR_GROUP,     //Group of items where only one needs to match
    REGEX_STRING,       //Match this string exactly
    REGEX_CHAR_CLASS,   //Match one character in this list
    REGEX_BOUNDS        //Used for *, +, and {,}
} eRegex_Type;

#define ARRLEN_INIT     10      //Array starts with 10 items
#define ARRLEN_INC      10      //After every realloc, array gains 10 items
#define ARRLEN_ALLOC    0       //First index of length array is number allocated
#define ARRLEN_INUSE    1       //Second index of length array is number in use

#define LOWER_BOUND  0       //First index of bounds array is LOWER bound
#define UPPER_BOUND  1       //Second index of bounds array is UPPER bound
#define NO_UPPER_BOUND (rIndex) -1

#define SHORT_STR_LEN   7   //A short string is 7 or fewer characters (not including NULL)

#define ALL_CHARS " !\"#$\%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
#define ALL_CHARS_PADDING "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define FUNC_FAILED (rIndex) -1			// When the call to regex->func fails



//Private regular expression object
typedef struct REGEX_OBJECT {
    union {
        char* str;                  //String of characters (or character class)
        struct REGEX_OBJECT* ptr;   //Pointer to a single regex object
        struct REGEX_OBJECT** arr;  //Array of regex objects
        void* other;                //Reserved for any other data type
    } d1;

    union {
        rIndex arrlen[2];       //Number of objects in the array, objects allocated in total
        rIndex bounds[2];       //Lower,Upper bounds for *, +, and {,}
        char short_str[8];      //Can store a short string, up to 7 characters + NULL
        bool not;               //Used to negate the operation
    } d2;

    eRegex_Type type;   // Type of this node
	rIndex (*func)(struct REGEX_OBJECT* this,const char* str);		//Function to call
} Regex_Obj_t, *pRegex_Obj_t;

typedef void (*Regex_Free_Func)(pRegex_Obj_t);



//Group Functions:
pRegex_Obj_t regex_new_group(bool orGroup);
bool regex_add_group(pRegex_Obj_t regex, pRegex_Obj_t to_add);
void regex_free_group(pRegex_Obj_t);
rIndex regex_do_or_group(pRegex_Obj_t regex, const char* str);
rIndex regex_do_and_group(pRegex_Obj_t regex, const char* str);


//String functions
pRegex_Obj_t regex_new_string(const char* str, size_t len);
void regex_free_string(pRegex_Obj_t);
rIndex regex_do_string(pRegex_Obj_t regex, const char* str);


//Character class
//  char_data automatically handles the parsing, starting at [ and ending at ]
pRegex_Obj_t regex_new_char_class(const char* char_data);
pRegex_Obj_t regex_free_char_class(pRegex_Obj_t);
rIndex regex_do_char_class(pRegex_Obj_t regex, const char* str);


//Bounds object
pRegex_Obj_t regex_new_bounds(rIndex min, rIndex max, pRegex_Obj_t to_add);
void regex_free_bounds(pRegex_Obj_t);
rIndex regex_do_bounds(pRegex_Obj_t regex, const char* str);

#endif // PRIVATE_REGEX_HEADER Included
