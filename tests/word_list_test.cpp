#include <cassert>
#include <unordered_set>

#include "word_list.h"

int main() {
    auto words = builtInWords();
    assert(!words.empty());

    std::unordered_set<std::string> unique(words.begin(), words.end());
    assert(unique.size() == words.size());  // expect no duplicates

    auto word = randomWord();
    assert(unique.count(word) == 1);

    // TODO: Add determinism hook for randomWord and validate min word length.
    return 0;
}

