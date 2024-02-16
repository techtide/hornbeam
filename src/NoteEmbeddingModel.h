#ifndef NOTE_EMBEDDING_MODEL_H
#define NOTE_EMBEDDING_MODEL_H

#include "core.h"

namespace hornbeam
{
  class NoteEmbeddingModel
  {
  public:
    // Constructor to initialise the model name and its custom parameters
    template <typename... Args>
    NoteEmbeddingModel(const std::string &modelName, Args &&...args);

    // Each model should implement this function, which accepts a string
    // containing all of the lines in a text file, and returns the word
    // embeddings matrix.
    virtual arma::mat compute(const std::string& noteText) = 0;

    std::string getModelName() const;

    void printModel() const;

  protected:
    // Helper function to print parameters recursively
    template <typename T>
    void printParameters(const T &param) const;

    template <typename T, typename... Args>
    void printParameters(const T &first, const Args &...args) const;

  private:
    std::string modelName;

    // Tuple to store the parameters of the model
    std::tuple<> parameters; // Base case for no parameters
  };
} // namespace hornbeam

#endif // NOTE_EMBEDDING_MODEL_H
