#ifndef ABFILEUTILS_H
#define ABFILEUTILS_H

#include "abcoredeps.h"

/*
 *  copyFile:
 *   - (const char*) srcPath: the path of the source file
 *   - (const char*) destPath: the path of the new dest file
 *  Copies a file from a given source directory to another directory,
 *  taking in the source path of the file and the desired output path.
 */
void copyFile(const char *, const char *);

/*
 * exploreDirectory:
 *  - (const char*) dirPath: the path to the directory
 * Build a clone of the original folder using DFS, only copying those files
 * which have extensions ending in *.txt or *.md.
 */
void exploreDirectory(const char *);

/*
 * moveFile:
 *  - (const char*) srcPath: the path of the source file
 *  - (const char*) destPath: the path of the destination directory
 * Moves a file from a given source path to a new destination directory.
 */
void moveFile(const char *, const char *);

/*
 * deleteFile:
 *  - (const char*) filePath: the path of the file to delete
 * Deletes the file specified by the given file path.
 */
void deleteFile(const char *);

/*
 * fileExists:
 *  - (const char*) filePath: the path of the file to check
 * Returns 1 if the file exists, 0 otherwise.
 */
int fileExists(const char *);

/*
 * listFiles:
 *  - (const char*) dirPath: the path of the directory
 * Prints a list of all files in the specified directory.
 */
void listFiles(const char *);

/*
 * fileSize:
 *  - (const char*) filePath: the path of the file
 * Returns the size of the file specified by the given path.
 */
size_t fileSize(const char *);

/*
 * readFileContent:
 *  - (const char*) filePath: the path of the file
 * Reads the content of the file specified by the given path and returns it as a string.
 */
char *readFileContent(const char *);

/*
 * writeFileContent:
 *  - (const char*) filePath: the path of the file
 *  - (const char*) content: the content to write to the file
 * Writes the specified content to the file at the given path.
 */
void writeFileContent(const char *, const char *);

#endif