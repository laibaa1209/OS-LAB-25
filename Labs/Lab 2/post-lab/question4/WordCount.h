#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <string>
#include <fstream>

class WordCount {
private:
    int wordCount;
public:
    WordCount();
    void countWords(const std::string &fileName);
    int getWordCount() const;
};

#endif
