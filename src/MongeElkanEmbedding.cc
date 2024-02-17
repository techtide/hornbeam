#include "MongeElkanEmbedding.h"

// Helper function to split a string into words
std::vector<std::string> split(const std::string &str)
{
  std::vector<std::string> words;
  std::string word;
  for (char c : str)
  {
    if (isspace(c))
    {
      if (!word.empty())
      {
        words.push_back(word);
      }
      word.clear();
    }
    else
    {
      word += c;
    }
  }
  if (!word.empty())
  {
    words.push_back(word);
  }
  return words;
}


double calculateTokenCosineSimilarity(const std::string &token1, const std::string &token2)
{
  // Preprocess tokens (lowercase, remove punctuation)
  std::string lower_token1(token1);
  std::string lower_token2(token2);
  std::transform(lower_token1.begin(), lower_token1.end(), lower_token1.begin(), ::tolower);
  std::transform(lower_token2.begin(), lower_token2.end(), lower_token2.begin(), ::tolower);
  for (char &c : lower_token1)
  {
    if (!isalnum(c))
    {
      c = ' ';
    }
  }
  for (char &c : lower_token2)
  {
    if (!isalnum(c))
    {
      c = ' ';
    }
  }

  // Split into words
  std::vector<std::string> words1 = split(lower_token1);
  std::vector<std::string> words2 = split(lower_token2);

  // Create bag-of-words representations
  std::vector<std::string> vocabulary;
  std::unordered_map<std::string, int> counts1, counts2;
  for (const auto &word : words1)
  {
    counts1[word]++;
    if (counts1[word] == 1)
    {
      vocabulary.push_back(word);
    }
  }
  for (const auto &word : words2)
  {
    counts2[word]++;
    if (counts2[word] == 1)
    {
      vocabulary.push_back(word);
    }
  }

  arma::Row<int> vec1(vocabulary.size());
  arma::Row<int> vec2(vocabulary.size());
  for (size_t i = 0; i < vocabulary.size(); ++i)
  {
    vec1(i) = counts1[vocabulary[i]];
    vec2(i) = counts2[vocabulary[i]];
  }

  // Calculate cosine similarity
  double similarity = arma::dot(vec1, vec2) / (arma::norm(vec1) * arma::norm(vec2));

  return similarity;
}


arma::mat hornbeam::MongeElkanEmbedding::compute(const std::string &noteText)
{
  std::vector<std::string> tokens;
  std::istringstream iss(noteText);
  std::string token;
  while (iss >> token)
  {
    tokens.push_back(token);
  }

  arma::mat result(tokens.size(), tokens.size(), arma::fill::zeros);

  for (size_t i = 0; i < tokens.size(); ++i)
  {
    for (size_t j = 0; j < tokens.size(); ++j)
    {
      double similarity = calculateTokenCosineSimilarity(tokens[i], tokens[j]);
      result(i, j) = similarity;
    }
  }

  return result;
}
