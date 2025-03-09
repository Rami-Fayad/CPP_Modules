#include "PmergeMe.hpp"
#include <algorithm>  // Include this for std::merge

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

// Merge function for vector
void merge(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right) {
    size_t i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }
    while (i < left.size())
        vec[k++] = left[i++];
    while (j < right.size())
        vec[k++] = right[j++];
}

// Merge Sort for vector
void PmergeMe::sortVector(std::vector<int> &vec) {
    if (vec.size() <= 1) return;

    std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());

    sortVector(left);
    sortVector(right);

    merge(vec, left, right);
}

// Merge function for deque
void merge(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right) {
    size_t i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            deq[k++] = left[i++];
        else
            deq[k++] = right[j++];
    }
    while (i < left.size())
        deq[k++] = left[i++];
    while (j < right.size())
        deq[k++] = right[j++];
}

// Merge Sort for deque
void PmergeMe::sortDeque(std::deque<int> &deq) {
    if (deq.size() <= 1) return;

    std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
    std::deque<int> right(deq.begin() + deq.size() / 2, deq.end());

    sortDeque(left);
    sortDeque(right);

    merge(deq, left, right);
}

// Print sequence for vector
void PmergeMe::printSequence(const std::string &label, const std::vector<int> &vec) {
    std::cout << label;
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

// Print sequence for deque
void PmergeMe::printSequence(const std::string &label, const std::deque<int> &deq) {
    std::cout << label;
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << std::endl;
}
