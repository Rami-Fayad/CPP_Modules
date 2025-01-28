#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        // Vector initialization in C++98
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

        std::cout << "Searching in vector...\n";
        std::vector<int>::iterator vec_it = easyfind(vec, 3);
        std::cout << "Found value in vector at index: "
                  << std::distance(vec.begin(), vec_it) << "\n";

        // List initialization in C++98
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::cout << "Searching in list...\n";
        std::list<int>::iterator lst_it = easyfind(lst, 40);
        std::cout << "Found value in list at position: "
                  << std::distance(lst.begin(), lst_it) << "\n";

        // Test case: Value not found
        std::cout << "Searching for a value not in the container...\n";
        easyfind(vec, 100);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
