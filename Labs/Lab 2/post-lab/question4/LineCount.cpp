#include "LineCount.h"
#include <iostream>
#include <fstream>

LineCount::LineCount() : lineCount(0) {}

void LineCount::countLines(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        lineCount++;
    }
}

int LineCount::getLineCount() const {
    return lineCount;
}
