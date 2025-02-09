# Define the compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Define the object files
OBJS = main.o LetterCount.o WordCount.o LineCount.o

# Define the target executable
TARGET = count_text

# Default target
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile main.o
main.o: main.cpp LetterCount.h WordCount.h LineCount.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile LetterCount.o
LetterCount.o: LetterCount.cpp LetterCount.h
	$(CXX) $(CXXFLAGS) -c LetterCount.cpp

# Rule to compile WordCount.o
WordCount.o: WordCount.cpp WordCount.h
	$(CXX) $(CXXFLAGS) -c WordCount.cpp

# Rule to compile LineCount.o
LineCount.o: LineCount.cpp LineCount.h
	$(CXX) $(CXXFLAGS) -c LineCount.cpp

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJS) $(TARGET)
