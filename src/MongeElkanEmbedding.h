#ifndef MONGE_ELKAN_EMBEDDING_H
#define MONGE_ELKAN_EMBEDDING_H

#include "core.h"
#include "NoteEmbeddingModel.h"

namespace hornbeam
{
  class MongeElkanEmbedding : public NoteEmbeddingModel
  {
  public:
    // Compute Monge Elkan distance
    arma::mat compute(const std::string& noteText) override;
  };
} // namespace hornbeam

#endif // MONGE_ELKAN_EMBEDDING_H