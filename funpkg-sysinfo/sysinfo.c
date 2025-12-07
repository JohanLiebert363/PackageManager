#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("OS Info:\n");
    system("uname -a");

    printf("\nCPU Info:\n");
    system("lscpu | head");

    printf("\nMemory:\n");
    system("free -h");
}
