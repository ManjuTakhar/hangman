// Core hangman game logic.
#pragma once

#include <string>
#include <unordered_set>
#include <vector>

class HangmanGame {
public:
    HangmanGame(std::string secret, int maxLives);

    // Apply a guess; returns true when the guess reveals at least one letter.
    bool guess(char letter);

    // TODO: Support full-word guesses with a bigger penalty on failure.

    bool isWon() const;
    bool isLost() const;
    int remainingLives() const;
    const std::unordered_set<char>& guessedLetters() const;
    std::string maskedWord() const;
    const std::string& secret() const;

private:
    std::string secret_;
    std::unordered_set<char> guessed_;
    int lives_;
};

