#include <iostream>
#include <vector>

void generateRules (int attempts, int maximumNum) {
    std::vector<std::string> rules = {
            "The number is between 0 - " + std::to_string(maximumNum),
            "The number is a whole number (no decimals)",
            "You can guess up to " + std::to_string(attempts) + " times",
            "You will be given hints as to whether you should increase or decrease your guess"
    };

    for (const auto& current : rules) {
        std::cout << "\n " << current << ".";
    }
}

void generatePreviousGuesses (std::vector<int> previousGuesses, int answer, std::string difficulty) {
    std::string previousGuessesString;

    for (int i = previousGuesses.size() - 1; i >= 0; i--) {
        int current = previousGuesses[i];
        int difference = abs(answer - current);

        if (i != previousGuesses.size() - 1) {
            std::cout <<  ", ";
        }

        if (difference > 50) {
            // Red
            std::cout << "\x1B[31m" << current << "\033[0m";
        } else if (difference > 10 && difference <= 50) {
            // Yellow
            std::cout << "\x1B[33m" << current << "\033[0m";
        } else {
            // Green
            std::cout << "\x1B[32m" << current << "\033[0m";
        }
    }
    std::cout << "\n";
}

void generateHint(double currentGuess, int answer, std::vector<std::string> prefixes) {
    // Select a random prefix based on the vectors size
    std::string hintPrefix = prefixes[rand() % prefixes.size()];
    std::string direction = currentGuess > answer ? "Go Lower." : "Go Higher.";
    std::cout << hintPrefix + " " + direction << std::endl;
}