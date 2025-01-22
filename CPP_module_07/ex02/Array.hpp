#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // For std::out_of_range

template <typename T>
class Array
{
private:
    T *elements;
    unsigned int _size;

public:
    // Default constructor: Creates an empty array
    Array() : elements(NULL), _size(0) {}

    // Constructor: Creates an array of n elements, initialized to default
    Array(unsigned int n) : elements(new T[n]()), _size(n) {}

    // Copy constructor: Ensures deep copy
    Array(const Array &other) : elements(NULL), _size(0)
    {
        *this = other;
    }

    // Destructor: Cleans up allocated memory
    ~Array()
    {
        delete[] elements;
    }

    // Assignment operator: Deep copy to avoid shared ownership
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] elements; // Free current memory
            _size = other._size;
            elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
            {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Subscript operator for non-const objects
    T &operator[](unsigned int index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Subscript operator for const objects
    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Returns the size of the array
    unsigned int size() const
    {
        return _size;
    }
};

#endif // ARRAY_HPP
