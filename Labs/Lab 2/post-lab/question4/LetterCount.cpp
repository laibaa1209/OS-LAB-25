#include "LetterCount.h"
#include <iostream>
#include <fstream>
#include <cctype>

LetterCount::LetterCount() : letterCount(0) {}

void LetterCount::countLetters(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            letterCount++;
        }
    }
}

int LetterCount::getLetterCount() const {
    return letterCount;
}
