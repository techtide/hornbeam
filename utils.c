#include "utils.h"

void copyFile(const char *srcPath, const char *destPath)
{
  FILE *srcFile, *destFile;
  char buffer[4096];
  size_t bytesRead;

  srcFile = fopen(srcPath, "rb");
  if (srcFile == NULL)
  {
    perror("Error opening source file");
    return;
  }

  destFile = fopen(destPath, "wb");
  if (destFile == NULL)
  {
    perror("Error creating destination file");
    fclose(srcFile);
    return;
  }

  while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0)
  {
    fwrite(buffer, 1, bytesRead, destFile);
  }

  fclose(srcFile);
  fclose(destFile);
}

void exploreDirectory(const char *dirPath)
{
  DIR *dir;
  struct dirent *entry;
  struct stat fileInfo;
  char newPath[MAX_PATH_LENGTH];
  char newDirPath[MAX_PATH_LENGTH];

  dir = opendir(dirPath);
  if (dir == NULL)
  {
    perror("Error opening directory");
    return;
  }

  snprintf(newDirPath, sizeof(newDirPath), "%s_backlinked", dirPath);
  mkdir(newDirPath, 0755);

  size_t newDirPathLen = strlen(newDirPath);
  while ((entry = readdir(dir)) != NULL)
  {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
    {
      continue;
    }

    size_t entryNameLen = strlen(entry->d_name);
    size_t requiredSize = newDirPathLen + 1 + entryNameLen + 1; // 1 for "/", 1 for null terminator
    if (requiredSize > sizeof(newPath))
    {
      fprintf(stderr, "Error: Path exceeds buffer size\n");
      continue;
    }

    snprintf(newPath, sizeof(newPath), "%s/%s", newDirPath, entry->d_name);

    if (stat(newPath, &fileInfo) == -1)
    {
      perror("Error getting file info");
      continue;
    }

    if (S_ISDIR(fileInfo.st_mode))
    {
      exploreDirectory(newPath);
    }
    else if (S_ISREG(fileInfo.st_mode))
    {
      if (strstr(entry->d_name, ".txt") != NULL || strstr(entry->d_name, ".md") != NULL)
      {
        copyFile(newPath, newPath);
      }
    }
  }

  closedir(dir);
}