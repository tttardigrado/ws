#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char * readFile(const char * path) {
    // Try to open the file
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file \"%s\".\n", path);
        exit(74);
    }

    // Get the size of the size of the file
    fseek(file, 0L, SEEK_END);
    unsigned fileSize = ftell(file);
    rewind(file);

    // Alocate enough memory and read the file into a null-terminated-string buffer 
    char* buffer = (char*)malloc(fileSize + 1);
    unsigned bytesRead = fread(buffer, sizeof(char), fileSize, file);
    buffer[bytesRead] = '\0';

    // Close the file and return the string buffer
    fclose(file);
    return buffer;
}

FILE * openWriteFile(const char * path) {
    // Try to open the file
    FILE * file = fopen(path, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file \"%s\".\n", path);
        exit(74);
    }

    return file;
}

bool streq(const char * str1, const char * str2) {
    return strcmp(str1, str2) == 0;
}