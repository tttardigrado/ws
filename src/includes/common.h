#ifndef COMMON_H
#define COMMON_H
#include <stdbool.h>
#include <stdio.h>

char * readFile(const char * path);

FILE * openWriteFile(const char * path);

bool streq(const char * str1, const char * str2);

#endif  // COMMON_H