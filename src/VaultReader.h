#ifndef VAULT_READER_H
#define VAULT_READER_H

#include "core.h"

namespace hornbeam
{

  /*
   * Read and process Obsidian vault directories, access and index different
   * notes files in the user's knowledge base or second brain.
   */
  class VaultReader
  {
  public:
    explicit VaultReader(const std::string &vaultPath);

    ~VaultReader();

    // Get all text files in the vault directory
    std::vector<std::string> getFilePaths() const;

    // Get text content of a file
    std::string getFileText(const std::string &filePath) const;

    // Append text to the end of a file
    static bool appendToFile(const std::string &filePath, const std::string &text);

  private:
    std::string vaultPath;

    // Check if the file has a supported extension (.txt or .md)
    static bool isSupportedFileType(const std::filesystem::path &filePath);
  };

} // namespace hornbeam

#endif // VAULT_READER_H
