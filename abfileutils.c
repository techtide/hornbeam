#include "abcoredeps.h"

void copyFile(const char *srcPath, const char *destPath) {
    FILE *source, *destination;
    char buffer[BUFSIZ];
    size_t bytes;

    source = fopen(srcPath, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    destination = fopen(destPath, "wb");
    if (destination == NULL) {
        fclose(source);
        perror("Error creating destination file");
        return;
    }

    while ((bytes = fread(buffer, 1, BUFSIZ, source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

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

    size_t newDirPathLen = strlen(newDirPath);
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        size_t entryNameLen = strlen(entry->d_name);
        size_t requiredSize = newDirPathLen + 1 + entryNameLen + 1; // 1 for "/", 1 for null terminator
        if (requiredSize > sizeof(newPath)) {
            fprintf(stderr, "Error: Path exceeds buffer size\n");
            continue;
        }

        snprintf(newPath, sizeof(newPath), "%s/%s", newDirPath, entry->d_name);

        if (stat(newPath, &fileInfo) == -1) {
            perror("Error getting file info");
            continue;
        }

        if (S_ISDIR(fileInfo.st_mode)) {
            exploreDirectory(newPath);
        } else if (S_ISREG(fileInfo.st_mode)) {
            if (strstr(entry->d_name, ".txt") != NULL || strstr(entry->d_name, ".md") != NULL) {
                copyFile(newPath, newPath);
            }
        }
    }

    closedir(dir);
}

void moveFile(const char *srcPath, const char *destPath) {
    if (rename(srcPath, destPath) != 0) {
        perror("Error moving file");
    }
}

void deleteFile(const char *filePath) {
    if (remove(filePath) != 0) {
        perror("Error deleting file");
    }
}

int fileExists(const char *filePath) {
    FILE *file;
    if ((file = fopen(filePath, "r")) != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

void listFiles(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirPath);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Files in directory %s:\n", dirPath);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

size_t fileSize(const char *filePath) {
    struct stat fileInfo;
    if (stat(filePath, &fileInfo) == -1) {
        perror("Error getting file info");
        return -1;
    }
    return fileInfo.st_size;
}

char *readFileContent(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char *content = (char *)malloc(fileSize + 1);
    if (content == NULL) {
        fclose(file);
        perror("Error allocating memory");
        return NULL;
    }

    if (fread(content, 1, fileSize, file) != fileSize) {
        fclose(file);
        free(content);
        perror("Error reading file");
        return NULL;
    }

    content[fileSize] = '\0'; // Null-terminate the string
    fclose(file);
    return content;
}

void writeFileContent(const char *filePath, const char *content) {
    FILE *file = fopen(filePath, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    if (fwrite(content, 1, strlen(content), file) != strlen(content)) {
        fclose(file);
        perror("Error writing to file");
        return;
    }

    fclose(file);
}
