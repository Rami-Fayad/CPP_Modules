#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>

template <typename T>
T next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &pm);
    PmergeMe &operator=(const PmergeMe &pm);
    ~PmergeMe();

    void sort_vec(std::vector<int> &vec);
    void sort_deque(std::deque<int> &deque);

    static int nbr_of_comps;

private:
    template <typename T>
    void _merge_insertion_sort(T &container, int pair_level);

    template <typename T>
    void _swap_pair(T it, int pair_level)
    {
        T start = next(it, -pair_level + 1);
        T end = next(start, pair_level);
        while (start != end)
        {
            std::iter_swap(start, next(start, pair_level));
            start++;
        }
    }
};

long _jacobsthal_number(long n);

template <typename T>
bool _comp(T left, T right)
{
    PmergeMe::nbr_of_comps++;
    return *left < *right;
}

#endif