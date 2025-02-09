#ifndef LETTERCOUNT_H
#define LETTERCOUNT_H

#include <string>
#include <fstream>

class LetterCount {
private:
    int letterCount;
public:
    LetterCount();
    void countLetters(const std::string &fileName);
    int getLetterCount() const;
};

#endif
