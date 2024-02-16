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