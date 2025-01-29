#include "Span.hpp"

int main() {
    try {
        // Create a Span with a max capacity of 10
        Span sp(10);

        // Add individual numbers
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Add multiple numbers using addNumbers
        int arr[] = {1, 5, 8, 4};
        sp.addNumbers(arr, arr + 4);

        std::cout << "Shortest Span after adding more numbers: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span after adding more numbers: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
