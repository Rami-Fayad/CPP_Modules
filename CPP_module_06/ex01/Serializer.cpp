#include "Serializer.hpp"
#include <cstring> // for reinterpret_cast

// Data class constructors and destructor
Data::Data() : str(""), num(0) {}

Data::Data(std::string s, int n) : str(s), num(n) {}

Data::~Data() {}

// Serializer class static methods
unsigned long Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<unsigned long>(ptr);
}

Data *Serializer::deserialize(unsigned long raw)
{
    // Cast the unsigned long back to a pointer
    return reinterpret_cast<Data *>(raw);
}

// Serializer class constructors and destructor
Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {
    (void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    if (this != &other)
    {
        // No state to assign
    }
    return *this;
}

Serializer::~Serializer() {}
