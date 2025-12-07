#include <stdio.h>
#include <stdlib.h>

int main() {
    char note[256];
    printf("Write a note: ");
    fgets(note, 256, stdin);

    FILE *f = fopen("notes.txt", "a");
    fprintf(f, "%s\n", note);
    fclose(f);

    printf("Saved to notes.txt\n");
}
