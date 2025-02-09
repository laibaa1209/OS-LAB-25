#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2> ... <numN>\n";
        return 1;
    }

    std::vector<int> numbers;

    for (int i = 1; i < argc; ++i) {
        numbers.push_back(std::atoi(argv[i]));
    }

    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
