#include "cli.h"

#include "hangman_game.h"
#include "word_list.h"

#include <iostream>
#include <string>

namespace {
char promptLetter() {
    std::cout << "Enter a letter: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        return '\0';
    }
    return input.front();
}

void render(const HangmanGame& game) {
    std::cout << "\nWord: " << game.maskedWord() << '\n';
    std::cout << "Lives left: " << game.remainingLives() << '\n';
    std::cout << "Guessed: ";
    for (char c : game.guessedLetters()) {
        std::cout << c << ' ';
    }
    std::cout << '\n';
}
}  // namespace

int runCli(const CliOptions& options) {
    HangmanGame game(randomWord(), options.lives);

    while (!game.isWon() && !game.isLost()) {
        render(game);
        char letter = promptLetter();
        if (letter == '\0') {
            std::cout << "Please type at least one character.\n";
            continue;
        }

        // TODO: Reject multi-character guesses and non-letters before passing to game.
        bool hit = game.guess(letter);
        if (hit) {
            std::cout << "Nice! '" << letter << "' is in the word.\n";
        } else {
            std::cout << "No luck with '" << letter << "'.\n";
        }
    }

    render(game);
    if (game.isWon()) {
        std::cout << "\nYou won! The word was \"" << game.secret() << "\".\n";
    } else {
        std::cout << "\nYou lost. The word was \"" << game.secret() << "\".\n";
    }

    if (options.showSecretOnExit && !game.isWon()) {
        std::cout << "(Tip) Remember the word for next time!\n";
    }

    // TODO: Add replay loop without restarting the program.
    return 0;
}

