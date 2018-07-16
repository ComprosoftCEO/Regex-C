# C Regular Expression Engine

## Compiling and Running
This library is designed to work with the cross-platform IDE [Code::Blocks](http://www.codeblocks.org/). To compile, open regex.cbp in Code::Blocks, and it should compile. As of this point, no special constants need to be defined on Windows or Linux.

<br>

## Usage:
```c
#include <regex.h>

pRegex_t regex = regex_prepare("Regular Expression");
Regex_Match_t match;
rIndex index = 0;

while((match = regex_match(regex,"String",&index)).str) {
  //Do something...
}

regex_release(regex);
```

<br>

## Regular Expression Features Supported:
This project is not done, yet...
