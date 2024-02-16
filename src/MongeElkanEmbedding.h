#ifndef MONGE_ELKAN_EMBEDDING_H
#define MONGE_ELKAN_EMBEDDING_H

#include "NoteEmbeddingModel.h"

namespace hornbeam
{
  class MongeElkanEmbedding : public NoteEmbeddingModel
  {
  public:
    MongeElkanEmbedding() : NoteEmbeddingModel("Monge Elkan", similarityMatrix) { }

    // Compute Monge Elkan distance
    arma::mat compute(const std::string& noteText) override;

  private:
    arma::mat similarityMatrix;
  };
} // namespace hornbeam

#endif // MONGE_ELKAN_EMBEDDING_H