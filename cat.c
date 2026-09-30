#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    FILE* fptr;
    char str[100];
    const char *filename = argv[1];
    if (access(filename, R_OK) == 0) {
        fptr = fopen(filename, "r");
        while (fgets(str, sizeof(str), fptr) != NULL) {
            printf("%s",str);
        }
        fclose(fptr);
    } else printf("File does not exist.\n");
    return 0;
}
