#ifndef NOTE_EMBEDDING_MODEL_H
#define NOTE_EMBEDDING_MODEL_H

#include "core.h"

namespace hornbeam
{
  class NoteEmbeddingModel
  {
  public:
    // Each model should implement this function, which accepts a string
    // containing all of the lines in a text file, and returns the word
    // embeddings matrix.
    virtual arma::mat compute(const std::string &noteText) = 0;
  };
} // namespace hornbeam

#endif // NOTE_EMBEDDING_MODEL_H
