#include <cassert>
#include <string>

#include "hangman_game.h"

void test_basic_flow() {
    HangmanGame game("cursor", 3);
    assert(game.maskedWord() == "______");
    assert(!game.isWon());
    assert(!game.isLost());
    assert(game.remainingLives() == 3);

    // Correct guess
    assert(game.guess('c') == true);
    assert(game.maskedWord()[0] == 'c');
    assert(game.remainingLives() == 3);

    // Incorrect guess
    assert(game.guess('z') == false);
    assert(game.remainingLives() == 2);

    // Finish the win
    game.guess('u');
    game.guess('r');
    game.guess('s');
    game.guess('o');
    assert(game.isWon());
    assert(!game.isLost());
}

void test_repeated_guess() {
    HangmanGame game("test", 2);
    assert(game.guess('t') == true);
    assert(game.guess('t') == false);  // repeats should not change state
    assert(game.remainingLives() == 2);
}

int main() {
    test_basic_flow();
    test_repeated_guess();
    // TODO: Add tests for full-loss scenario, non-letter inputs, and word guesses.
    return 0;
}

