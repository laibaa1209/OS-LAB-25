#ifndef LINECOUNT_H
#define LINECOUNT_H

#include <string>
#include <fstream>

class LineCount {
private:
    int lineCount;
public:
    LineCount();
    void countLines(const std::string &fileName);
    int getLineCount() const;
};

#endif
