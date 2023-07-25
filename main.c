#include "include/main.h"
#include "include/raf.h"
#include "include/io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char* args[]){
    char *src = rafCompilerIO(args[1]);
    rafCompile(src);
    if(src) free(src);
    return 0;
}