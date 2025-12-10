# Hangman (C++)

A simple CLI hangman game. Guess letters to reveal the hidden word before running out of lives.

## Project Layout
- `src/main.cpp` - entry point wiring the CLI options.
- `src/cli.cpp` / `include/cli.h` - interactive terminal loop.
- `src/hangman_game.cpp` / `include/hangman_game.h` - core game rules.
- `src/word_list.cpp` / `include/word_list.h` - built-in word selection.

## Build & Run
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o hangman
./hangman
```

## Run Tests
Simple assert-style tests live under `tests/`.
```bash
g++ -std=c++17 -Iinclude tests/hangman_game_test.cpp src/hangman_game.cpp -o hangman_game_test
./hangman_game_test

g++ -std=c++17 -Iinclude tests/word_list_test.cpp src/word_list.cpp -o word_list_test
./word_list_test
```

## How to Play
- The game shows masked letters with `_` and reports remaining lives.
- Type a single letter and press enter to guess.
- Win by revealing all letters before your lives reach zero.

## Notes & TODOs
- TODO: parse command-line flags to tweak lives or word lists.
- TODO: load words from a user-supplied file with difficulty tiers.
- TODO: add a replay loop so you can keep playing without restarting.
- TODO: add deterministic seed for `randomWord` to make tests reproducible.
- TODO: validate input (letters only, single char) before guessing.
- TODO: support full-word guesses with penalties on wrong attempts.

## Extension Ideas
- Add ASCII art for each life state and surface it in the CLI renderer.
- Persist high scores or streaks to a local file.
- Provide a `--word-file` flag to load custom lists (tie into TODO above).
- Add colorized output and input validation for non-letters.
- Expose a library API that the CLI (and future GUI) can share.

Feel free to extend the code and fill the TODOs.