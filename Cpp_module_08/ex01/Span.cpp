#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

void Span::addNumber(int num) {
    if (numbers.size() >= _N)
        throw std::overflow_error("Span is full, cannot add more numbers.");
    numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers for a span.");

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int diff = sortedNumbers[i] - sortedNumbers[i - 1];
        if (diff < shortest)
            shortest = diff;
    }

    return shortest;
}

int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers for a span.");

    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal = *std::max_element(numbers.begin(), numbers.end());

    return maxVal - minVal;
}
