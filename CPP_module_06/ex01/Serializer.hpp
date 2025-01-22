#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

// Data class to hold some simple data
class Data
{
public:
    // Default constructor
    Data();

    // Parameterized constructor
    Data(std::string s, int n);

    // Destructor
    ~Data();

    // Data members
    std::string str;
    int num;

private:
    // No need for private members for this simple class
};

// Serializer class
class Serializer
{
public:
    // Default constructor
    Serializer();

    // Copy constructor
    Serializer(const Serializer &other);

    // Copy assignment operator
    Serializer &operator=(const Serializer &other);

    // Destructor
    ~Serializer();

    // Static methods
    static unsigned long serialize(Data *ptr);   // Changed from uintptr_t to unsigned long
    static Data *deserialize(unsigned long raw); // Changed from uintptr_t to unsigned long
};

#endif
