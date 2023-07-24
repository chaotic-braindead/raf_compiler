#include "include/main.h"
#include "include/raf.h"
#include <stdio.h>

int main(int argv, char* args[]){
    char *src = "int main(){\n char x = 10; int[2]; EXIT_SUCCESS; }";
    rafCompile(src);
    return 0;
}