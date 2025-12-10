#pragma once

struct CliOptions {
    int lives = 6;
    bool showSecretOnExit = true;
};

// Runs an interactive hangman game in the terminal.
int runCli(const CliOptions& options);

// TODO: Add support for parsing command-line flags into CliOptions.

