#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <utility>
#include <limits>
template<typename Container>
class PmergeMe {
public:
    typedef std::vector<std::pair<int, int> > pair_vector;

    PmergeMe();
    ~PmergeMe();
    PmergeMe(char **data);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void sort();
    void print_container() const;
    void print_time() const;

private:
    Container _data;
    double time;
    pair_vector generate_pairs(Container &data);
    void mergeSort(pair_vector &pairs);
    int binary_search(int target, int max);
    std::vector<int> generate_indexes(size_t size);
    int ft_stoa(const char *str);
    void insert_elements(pair_vector& pairs, std::vector<int>& insertionIndexes, int lastElement);
};

#endif