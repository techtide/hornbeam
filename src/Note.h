#ifndef NOTE_H
#define NOTE_H

#include <string>
#include <unordered_map>
#include <vector>
#include "FileEmbedding.h"

namespace hornbeam
{
    /*
     * Data structure for storing notes/text-files in the Obsidian vault,
     * and representing them with their file-wide word/sentence embeddings.
     * 
     * To enable support for different word embedding models, each Note item
     * must implement its own computeEmbedding function, connecting to the
     * relevant static model.
     */
    class Note
    {
    public:
        Note(const std::string &filePath) : filePath_(filePath) {
            embedding_ = computeEmbedding();
        }

        std::string getFilePath() const { return filePath_; }
        FileEmbedding getEmbedding() const { return embedding_;}
        int getGroupId() const;

    private:
        std::string filePath_;
        FileEmbedding embedding_;
        int groupId_;

        FileEmbedding computeEmbedding();
    };
} // namespace hornbeam

#endif // NOTE_H
