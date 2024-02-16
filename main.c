#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

/*  
 *  copyFile:
 *   - (const char*) srcPath: the path of the source file
 *   - (const char*) destPath: the path of the new dest file
 *  Copies a file from a given source directory to another directory,
 *  taking in the source path of the file and the desired output path.
 */
void copyFile(const char *srcPath, const char *destPath) {
    FILE *srcFile, *destFile;
    char buffer[4096];
    size_t bytesRead;

    srcFile = fopen(srcPath, "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    destFile = fopen(destPath, "wb");
    if (destFile == NULL) {
        perror("Error creating destination file");
        fclose(srcFile);
        return;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

/* 
 * exploreDirectory:
 *  - (const char*) dirPath: the path to the directory
 * Build a clone of the original folder using DFS, only copying those files
 * which have extensions ending in *.txt or *.md.
 */
void exploreDirectory(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileInfo;
    char newPath[MAX_PATH_LENGTH];
    char newDirPath[MAX_PATH_LENGTH];

    dir = opendir(dirPath);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    snprintf(newDirPath, sizeof(newDirPath), "%s_backlinked", dirPath);
    mkdir(newDirPath, 0755);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(newPath, sizeof(newPath), "%s/%s", dirPath, entry->d_name);

        if (stat(newPath, &fileInfo) == -1) {
            perror("Error getting file info");
            continue;
        }

        if (S_ISDIR(fileInfo.st_mode)) {
            exploreDirectory(newPath);
        } else if (S_ISREG(fileInfo.st_mode)) {
            if (strstr(entry->d_name, ".txt") != NULL || strstr(entry->d_name, ".md") != NULL) {
                char newFilePath[MAX_PATH_LENGTH];
                snprintf(newFilePath, sizeof(newFilePath), "%s/%s", newDirPath, entry->d_name);
                copyFile(newPath, newFilePath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    exploreDirectory(argv[1]);

    printf("Done\n");
    return 0;
}
