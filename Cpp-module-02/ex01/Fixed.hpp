#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;                       // Fixed-point value
    static const int _fractionalBits = 8;       // Number of fractional bits

public:
    // Default constructor
    Fixed();

    // Int constructor
    Fixed(const int value);

    // Float constructor
    Fixed(const float value);

    // Copy constructor
    Fixed(const Fixed& other);

    // Destructor
    ~Fixed();

    // Copy assignment operator
    Fixed& operator=(const Fixed& other);

    // Getter and setter
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion functions
    float toFloat(void) const;
    int toInt(void) const;
};

// Overload of the insertion operator (<<)
std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif
