#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to get file size
long getFileSize(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    printf("Unable to return file/directory sizes");
}

// Function to list files, types, and sizes
void listFiles(const char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }

    struct dirent* entity;
    entity = readdir(dir);

    while (entity != NULL) {
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dirname, entity->d_name);

            printf("%s\n", entity->d_name);

            if (entity->d_type == DT_REG) {
                printf("File\n");
            } else if (entity->d_type == DT_DIR) {
                printf("Directory\n");
            } else {
                printf("Other\n");
            }

            long size = getFileSize(path);
            if (size >= 0) {
                printf("%ld bytes\n", size);

                // Delete files and directories with size 0
                if (size == 0) {
                    remove(path);
                    printf("Deleted: %s\n", path);
                }

                // Delete files with ".sh" extension without listing
                if (entity->d_type == DT_REG && strstr(entity->d_name, ".sh") != NULL) {
                    remove(path);
                    printf("Deleted: %s\n", path);
                }
            } else {
                printf("Cannot determine size for: %s\n", path);
            }
        }

        entity = readdir(dir);
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    listFiles(".");
    return 0;
}
