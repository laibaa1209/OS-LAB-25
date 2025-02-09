#include "WordCount.h"
#include <iostream>
#include <fstream>
#include <sstream>

WordCount::WordCount() : wordCount(0) {}

void WordCount::countWords(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::string word;
    while (file >> word) {
        wordCount++;
    }
}

int WordCount::getWordCount() const {
    return wordCount;
}
