#include <iostream>
#include <string>
#include "iter.hpp"
void increment(int &n)
{
    n += 1;
}

// A function to print strings
void printString(std::string &str)
{
    std::cout << str << std::endl;
}

// A function to print integers
void printInt(int &n)
{
    std::cout << n << " ";
}
int main()
{
    // Test 1: Array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intSize, printInt);
    std::cout << "\nIncrementing intArray..." << std::endl;
    iter(intArray, intSize, increment);

    std::cout << "Modified intArray: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;

    // Test 2: Array of strings
    std::string strArray[] = {"Hello", "World", "C++", "Templates"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String Array:" << std::endl;
    iter(strArray, strSize, printString);

    return 0;
}
