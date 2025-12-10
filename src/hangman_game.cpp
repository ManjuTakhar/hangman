#include "hangman_game.h"

#include <algorithm>
#include <cctype>

namespace {
char normalize(char c) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}
}  // namespace

HangmanGame::HangmanGame(std::string secret, int maxLives)
    : secret_(std::move(secret)), lives_(maxLives) {
    std::transform(secret_.begin(), secret_.end(), secret_.begin(), normalize);
}

bool HangmanGame::guess(char letter) {
    letter = normalize(letter);
    if (guessed_.count(letter) > 0 || isWon() || isLost()) {
        return false;
    }
    // TODO: ignore or warn on non alphabetic characters rather than accepting them.
    guessed_.insert(letter);

    bool hit = secret_.find(letter) != std::string::npos;
    if (!hit) {
        --lives_;
    }
    return hit;
}

bool HangmanGame::isWon() const {
    for (char c : secret_) {
        if (!guessed_.count(c)) {
            return false;
        }
    }
    return true;
}

bool HangmanGame::isLost() const {
    return lives_ <= 0 && !isWon();
}

int HangmanGame::remainingLives() const {
    return lives_;
}

const std::unordered_set<char>& HangmanGame::guessedLetters() const {
    return guessed_;
}

std::string HangmanGame::maskedWord() const {
    std::string masked;
    masked.reserve(secret_.size());
    for (char c : secret_) {
        masked.push_back(guessed_.count(c) ? c : '_');
    }
    return masked;
}

const std::string& HangmanGame::secret() const {
    return secret_;
}

