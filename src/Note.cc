#include "Note.h"

std::vector<std::string> hornbeam::Note::findAllBacklinks(const std::string& input) {
    std::vector<std::string> backlinks;
    std::regex pattern("\\[([^\\[\\]]+)\\]");
    std::smatch matches;

    auto words_begin = std::sregex_iterator(input.begin(), input.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        backlinks.push_back(match[1]);
    }

    return backlinks;
}
