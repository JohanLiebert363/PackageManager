#include <stdio.h>
#include <stdlib.h>

int main() {
    char host[128];
    printf("Host to ping: ");
    scanf("%127s", host);

    char cmd[256];
    sprintf(cmd, "ping -c 4 %s", host);

    system(cmd);
}
