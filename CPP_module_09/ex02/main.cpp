#include "PmergeMe.hpp"
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No numbers provided!" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        int num;
        std::stringstream ss(argv[i]);
        if (!(ss >> num) || num < 0) {
            std::cerr << "Error: Invalid input detected!" << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    PmergeMe sorter;

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    sorter.sortVector(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    sorter.sortDeque(deq);
    clock_t endDeq = clock();

    sorter.printSequence("After: ", vec);

    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector: " 
              << static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000 
              << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque: " 
              << static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000 
              << " us" << std::endl;

    return 0;
}
