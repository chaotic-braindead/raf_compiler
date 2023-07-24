#include "include/main.h"
#include "include/raf.h"
#include "include/io.h"
#include <stdio.h>

int main(int argv, char* args[]){
    
    char *src = rafCompilerIO("test.raf");
    printf("%s", src);
    // rafCompile(src);
    return 0;
}