#pragma once

#include <string>
#include <vector>

// Returns a random word from a built-in set.
std::string randomWord();

// TODO: Allow loading words from a user-provided file and difficulty levels.
// TODO: Validate words for alphabetic-only and minimum length.
std::vector<std::string> builtInWords();

