#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sortVector(std::vector<int> &vec);
    void sortDeque(std::deque<int> &deq);

    static void printSequence(const std::string &label, const std::vector<int> &vec);
    static void printSequence(const std::string &label, const std::deque<int> &deq);
};

#endif
