#include "cli.h"

#include <iostream>

int main() {
    CliOptions options;
    // TODO: Parse CLI flags to override defaults.
    std::cout << "=== Hangman (CLI) ===\n";
    return runCli(options);
}

