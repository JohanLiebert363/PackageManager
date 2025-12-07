#include <stdio.h>
#include <stdlib.h>

int main() {
    char city[64];
    printf("City: ");
    scanf("%63s", city);

    char cmd[128];
    sprintf(cmd, "curl -s wttr.in/%s", city);

    system(cmd);
}
