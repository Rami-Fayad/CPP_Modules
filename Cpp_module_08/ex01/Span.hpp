#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int _N;
    std::vector<int> numbers;

public:
    Span(unsigned int N);
    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;

    // Template function defined in the header
    template <typename InputIterator>
    void addNumbers(InputIterator first, InputIterator last) {
        while (first != last) {
            addNumber(*first);
            ++first;
        }
    }
};

#endif
