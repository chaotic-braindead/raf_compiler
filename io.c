#include "include/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rafCompilerIO(const char *filename){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    fp = fopen(filename, "rb");
    ssize_t read;
    if(fp == NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    char *buf = calloc(1, sizeof(char));
    buf[0] = '\0';
    while(read = getline(&line, &len, fp)){
        printf("%d\n", read);
        buf = realloc(buf, (strlen(buf) + strlen(line) + 1) * sizeof(char));
        strcat(buf, line);
    }
    fclose(fp);
    if(line)
        free(line);

    return buf;
}
    