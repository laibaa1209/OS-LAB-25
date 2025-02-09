#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"

int main() {
    std::string fileName = "sample.txt"; // Change the file name as needed

    // Create objects of each class
    LetterCount letterCounter;
    WordCount wordCounter;
    LineCount lineCounter;

    // Count letters, words, and lines
    letterCounter.countLetters(fileName);
    wordCounter.countWords(fileName);
    lineCounter.countLines(fileName);

    // Display the results
    std::cout << "Letters in the file: " << letterCounter.getLetterCount() << std::endl;
    std::cout << "Words in the file: " << wordCounter.getWordCount() << std::endl;
    std::cout << "Lines in the file: " << lineCounter.getLineCount() << std::endl;

    return 0;
}
