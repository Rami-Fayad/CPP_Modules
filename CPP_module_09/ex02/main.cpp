#include "PmergeMe.hpp"
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        PmergeMe<std::vector<int> > sorter(argv);
        PmergeMe<std::deque<int> > sort(argv);
        std::cout << "Before: ";
        sorter.print_container();

        sorter.sort();
        sort.sort();
        std::cout << "After: for Vector ";
        sorter.print_container();
        
        std::cout << "After: for Deque ";
        sorter.print_container();
        
        sorter.print_time();
        sort.print_time();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}