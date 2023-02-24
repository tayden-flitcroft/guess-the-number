#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "helpers.h"

int main() {
    srand(time(nullptr));

    std::map<std::string, std::map<std::string, int>> difficultyData {
            {"Easy", {
                    {"maximumAttempts", 12},
                    {"maximumNumber", 100}
                }
            }, {"Medium", {
                    {"maximumAttempts", 10},
                    {"maximumNumber", 200}
                }
            }, {"Hard", {
                    {"maximumAttempts", 8},
                    {"maximumNumber", 300}
                }
            }, {"Expert", {
                    {"maximumAttempts", 9},
                    {"maximumNumber", 500}
                }
            }
    };

    std::vector<std::string> listOfAllResponses;
    std::ifstream responses ("../motivational-prefixes.txt");
    while (!responses.eof()) {
        std::string text;
        getline(responses, text);
        listOfAllResponses.push_back(text);
    }

    std::vector<std::string> difficulties = {"Easy", "Medium", "Hard", "Expert"};

    int selectedDifficulty;
    int MAXIMUM_ATTEMPTS;
    int MAXIMUM_RANDOM_NUM;

    std::cout << "Select a Difficulty:" << std::endl;

    for (int i = 0; i < difficulties.size(); i++) {
        std::cout << "[" << i << "]" << " " << difficulties[i] << std::endl;
    }
    std::cout << "\nDifficulty: ";
    std::cin >> selectedDifficulty;

    if (selectedDifficulty > difficulties.size() - 1) {
        // If no difficulty option is selected, default to easy mode
        selectedDifficulty = 0;
    }

    MAXIMUM_ATTEMPTS = difficultyData[difficulties[selectedDifficulty]]["maximumAttempts"];
    MAXIMUM_RANDOM_NUM = difficultyData[difficulties[selectedDifficulty]]["maximumNumber"];

    int randomNumber = rand() % (MAXIMUM_RANDOM_NUM + 1);
    char shouldBegin;
    int currentGuess;
    std::vector<int> previousAttempts;

    std::cout << "Guess my random number!\n";
    std::cout << "\nRules:";
    generateRules(MAXIMUM_ATTEMPTS, MAXIMUM_RANDOM_NUM);
    std::cout << "\n\nAre you ready? [Y/N]: ";
    std::cin >> shouldBegin;

    if (shouldBegin == 'y' || shouldBegin == 'Y') {
        std::cout << "\nMake your first guess!\n";
        std::cout << "Attempt #1: ";
        std::cin >> currentGuess;

        while (currentGuess != randomNumber && previousAttempts.size() < MAXIMUM_ATTEMPTS - 1) {
            std::cout << "\n";
            generateHint(currentGuess, randomNumber, listOfAllResponses);
            previousAttempts.push_back(currentGuess);
            std::cout << "Previous Guesses: ";
            generatePreviousGuesses(previousAttempts, randomNumber, difficulties[selectedDifficulty]);
            std::cout << "\n\nAttempt #" << previousAttempts.size() + 1 << ": ";
            std::cin >> currentGuess;
        }

        if (currentGuess == randomNumber) {
            std::cout << "\n\nCongratulations!\n\n" ;
            std::cout << "It took you " << previousAttempts.size() + 1 << " tries!" << std::endl;
            std::cout << "See if you can do better!";
        } else {
            std::cout << "\n\nYou didn't guess the correct number this time. Try giving it another shot!\n\n ";
        }
    } else {
        std::cout << "Hope you try again soon!" << std::endl;
    }

    return 0;
}