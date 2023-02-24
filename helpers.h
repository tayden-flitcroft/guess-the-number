#include <vector>

void generateRules(int attempts, int maximumNum);
void generatePreviousGuesses (std::vector<int> previousGuesses, int answer, std::string difficulty);
void generateHint(double currentGuess, int answer, std::vector<std::string> prefixes);