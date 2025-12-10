#include "word_list.h"

#include <random>

namespace {
std::vector<std::string> words = {
    "cplusplus", "cursor", "developer", "hangman", "puzzle",
    "keyboard", "monitor", "algorithm", "compile", "debug",
    "pointer", "reference", "template", "lambda", "package",
};
}  // namespace

std::vector<std::string> builtInWords() {
    return words;
}

std::string randomWord() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, words.size() - 1);
    return words[dist(gen)];
}

// TODO: Provide a seedable overload for deterministic tests.
// TODO: Add filtering by difficulty and word length.

