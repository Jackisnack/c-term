#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *filename = argv[1];
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("filename");
        return EXIT_FAILURE;
    }
    char str[100];
    while (fgets(str, sizeof(str), fptr) != NULL) {
        fputs(str, stdout);
    }
    if (ferror(fptr)) {
        perror("filename");
        fclose(fptr);
        return EXIT_FAILURE;
    }
    fclose(fptr);
    return EXIT_SUCCESS;
}
