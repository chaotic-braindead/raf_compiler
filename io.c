#define _GNU_SOURCE
#include "include/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

ssize_t getline(char **restrict buffer, size_t *restrict size,
                FILE *restrict fp) {
  register int c;
  register char *cs = NULL;

  if (cs == NULL) {
    register int length = 0;
    while ((c = getc(fp)) != EOF) {
      cs = (char *)realloc(cs, ++length+1);
      if ((*(cs + length - 1) = c) == '\n') {
        *(cs + length) = '\0';
        *buffer = cs;
                break;
      }
    }
    return (ssize_t)(*size = length);
  } else {
    while (--(*size) > 0 && (c = getc(fp)) != EOF){
      if ((*cs++ = c) == '\n')
        break;
        }
    *cs = '\0';
  }
  return (ssize_t)(*size=strlen(*buffer));
}

char* rafCompilerIO(const char *filename){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    fp = fopen(filename, "rb");
    long long read;

    if(fp == NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    char *buf = calloc(1, sizeof(char));
    buf[0] = '\0';
    while(read = getline(&line, &len, fp) != -1){
        buf = realloc(buf, (strlen(buf) + strlen(line) + 1) * sizeof(char));
        strcat(buf, line);
    }

    fclose(fp);
    if(line)
        free(line);

    return buf;
}
    