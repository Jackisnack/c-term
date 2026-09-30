#include <_stdio.h>
#include <sys/dirent.h>
#include <sys/stat.h>
#include <dirent.h>

int main (int argc, char *argv[]) {
    // Error-handling and dir initialization
    const char *dir_path = (argc > 1) ? argv[1] : "."; // This takes an argument!!!
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("opendir");
        return 1;
    }
    // Fetch Current Working Directory --> printf
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
