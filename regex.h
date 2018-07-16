// Regular Expression Engine (Written in C)
// (C) Comprosoft 2018
//
//  regex.h - Public regular expression header
#ifndef PUBLIC_REGEX_HEADER
#define PUBLIC_REGEX_HEADER

#include <stddef.h>     /* For size_t */
#include <stdint.h>

typedef void *pRegex_t;       // Regular expression object
typedef uint32_t rIndex;      // Index in regular expression

//Represents a single match in the string
typedef struct {
    const char* str;    //Start of matched string (or NULL if no match)
    rIndex len;         //Length of the matched string (in characters)
} Regex_Match_t, *pRegex_Match_t;

typedef struct {
    pRegex_Match_t matches;     //Array of all regular expression matches (may be NULL)
    rIndex len;                 //Number of elements in the array (may be 0)
} Regex_Matches_t;


pRegex_t regex_prepare(const char*);
void regex_release(pRegex_t);


//start_index is used for matching the next regular expression (can be NULL)
Regex_Match_t regex_match(pRegex_t regex, const char* str, rIndex* start_index);
Regex_Matches_t regex_match_all(pRegex_t regex, const char* str);




#endif // PUBLIC_REGEX_HEADER Included
