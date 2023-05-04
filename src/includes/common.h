#ifndef COMMON_H
#define COMMON_H
#include <stdbool.h>

char * readFile(const char * path);

bool streq(const char * str1, const char * str2);

void error(int code , const char * msg);

#endif  // COMMON_H