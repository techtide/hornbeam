#include "NoteEmbeddingModel.h"

template <typename... Args>
hornbeam::NoteEmbeddingModel::NoteEmbeddingModel(const std::string &modelName, Args &&...args)
    : modelName(modelName), parameters(std::forward<Args>(args)...) {}

std::string hornbeam::NoteEmbeddingModel::getModelName() const
{
  return modelName;
}

void hornbeam::NoteEmbeddingModel::printModel() const
{
  std::cout << "Model Name: " << modelName << std::endl;
  std::cout << "Parameters: ";
  printParameters(parameters);
  std::cout << std::endl;
}

template <typename T>
void hornbeam::NoteEmbeddingModel::printParameters(const T &param) const
{
  std::cout << param << " ";
}

template <typename T, typename... Args>
void hornbeam::NoteEmbeddingModel::printParameters(const T &first, const Args &...args) const
{
  std::cout << first << " ";
  printParameters(args...);
}