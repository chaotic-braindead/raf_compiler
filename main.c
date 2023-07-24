#include "include/main.h"
#include "include/raf.h"
#include <stdio.h>

int main(int argv, char* args[]){
    char *src = "int main(){\n int x = 10; int y = 2; int z = x + y; char *test = \"hello world\"; return EXIT_SUCCESS; }";
    rafCompile(src);
    return 0;
}