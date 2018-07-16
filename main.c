#include <regex.h>
#include <stdio.h>

int main() {

    pRegex_t regex = regex_prepare("Regular Expression");
    Regex_Match_t match;
    rIndex index = 0;

    while((match = regex_match(regex,"String",&index)).str) {
        //Do something
    }
    regex_release(regex);

    return 0;
}
