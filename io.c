#include "include/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static ssize_t getline(char **buffer, size_t *length, FILE *fp){
    size_t bufferSize = 128;
    int i;
    char c; 

    if(!*buffer){
        if(!(*buffer = malloc(bufferSize * sizeof(char))))
            exit(1);
    }
    i = 0;
    while((c = fgetc(fp)) != EOF){
        if(i + 1 >= *length){
            *buffer = realloc(*buffer, *length + bufferSize);
        }
        (*buffer)[i++] = c;
        if(c == '\n') break;
    }
    (*buffer)[i] = '\0';
    *length = i;
    return !i && c == EOF ? -1 : i;
}

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

    char *buf = malloc(1);
    buf[0] = '\0';
    while((read = getline(&line, &len, fp)) != -1){
        buf = realloc(buf, strlen(buf) + strlen(line) + 1);
        strcat(buf, line);
    }
    fclose(fp);
    if(line) free(line);
    return buf;
}
    