#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
   int _fixedPointValue; // Raw fixed-point value
   static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator = (const Fixed& other);
    ~Fixed();
    int getRawBits() const;

    // Setter for raw value
    void setRawBits(int const raw);
};



#endif