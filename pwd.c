#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

int main (int argc, char *argv[]) {
    if (argc != 1) {
        fprintf(stderr, "%s takes no arguments.\n", argv[0]);
        return EXIT_FAILURE;
    }
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd() error");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
