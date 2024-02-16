#include "VaultReader.h"

hornbeam::VaultReader::VaultReader(const std::string &vaultPath) : vaultPath(vaultPath) {}

hornbeam::VaultReader::~VaultReader() {}

std::vector<std::string> hornbeam::VaultReader::getFilePaths() const
{
    std::vector<std::string> textFiles;

    for (const auto &entry : std::filesystem::recursive_directory_iterator(vaultPath))
    {
        if (entry.is_regular_file() && isSupportedFileType(entry.path()))
        {
            textFiles.push_back(entry.path().string());
        }
    }

    return textFiles;
}

std::string hornbeam::VaultReader::getFileText(const std::string &filePath) const
{
    std::ifstream fileStream(filePath);
    if (!fileStream.is_open())
    {
        std::cerr << "Error: Unable to open file: " << filePath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}

bool hornbeam::VaultReader::appendToFile(const std::string &filePath, const std::string &text)
{
    std::ofstream outputFile(filePath, std::ios_base::app);
    if (outputFile.is_open())
    {
        outputFile << text;
        outputFile.close();
        return true;
    }
    else
    {
        std::cerr << "Error: Unable to open file for appending: " << filePath << std::endl;
        return false;
    }
}

bool hornbeam::VaultReader::isSupportedFileType(const std::filesystem::path &filePath)
{
    std::string extension = filePath.extension().string();
    return extension == ".txt" || extension == ".md";
}
