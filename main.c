#include "abcoredeps.h"
#include "utils.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <directory_path>\n", argv[0]);
    return 1;
  }

  exploreDirectory(argv[1]);

  printf("Done\n");
  return 0;
}
