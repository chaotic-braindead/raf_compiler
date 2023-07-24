#include <stddef.h>
#include <stdio.h>
#ifndef RAF_IO_H
#define RAF_IO_H

ssize_t getline(char **buffer, size_t *length, FILE *fp);

char* rafCompilerIO(const char *filename);

#endif