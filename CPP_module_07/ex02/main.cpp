#include <iostream>
#include "Array.hpp"

int main()
{
    // Test 1: Default constructor
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    // Test 2: Parameterized constructor
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    // Test 3: Modify array elements
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i * 10;
    }
    std::cout << "Modified intArray:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    // Test 4: Copy constructor
    Array<int> copiedArray(intArray);
    std::cout << "Copied array:" << std::endl;
    for (unsigned int i = 0; i < copiedArray.size(); i++)
    {
        std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
    }

    // Test 5: Assignment operator
    Array<int> assignedArray = intArray;
    std::cout << "Assigned array:" << std::endl;
    for (unsigned int i = 0; i < assignedArray.size(); i++)
    {
        std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
    }

    // Test 6: Out-of-bounds access
    try
    {
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
