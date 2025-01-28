#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // For std::find
#include <iterator>  // For iterator types
#include <exception> // For exceptions

// Template function to find an element in a container
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::runtime_error("Value not found in container");
    }
    return it; // Return the iterator to the found element
}

#endif
