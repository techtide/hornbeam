#ifndef NOTE_H
#define NOTE_H

#include "core.h"

namespace hornbeam
{

    /*
     * Data structure for storing notes/text-files in the Obsidian vault,
     * and representing them with their file-wide word/sentence embeddings.
     *
     * To enable support for different word embedding models, each Note object
     * must implement its own computeEmbedding function, connecting to the
     * relevant static model. The knowledge graph will be modeled out of Notes.
     */
    class Note
    {
    public:
        Note(const std::string &filePath, const std::string &noteText, const arma::mat &embedding) : filePath_(filePath), text_(noteText), embedding_(embedding) {
            backlinks_ = findAllBacklinks(noteText);
        }

        std::string getFilePath() const { return filePath_; }
        arma::mat getEmbedding() const { return embedding_; }
        
        std::vector<std::string> getBacklinks() const { return backlinks_; }

    private:
        std::string filePath_;
        arma::mat embedding_;

        std::vector<std::string> findAllBacklinks(const std::string &input);
        
        std::string text_;
        std::vector<std::string> backlinks_;
    };
} // namespace hornbeam

#endif // NOTE_H
