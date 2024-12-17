#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;  // Convert integer to fixed-point
}

// Float constructor
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));  // Convert float to fixed-point
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

// Getter for raw bits
int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

// Setter for raw bits
void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

// Convert fixed-point to float
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// Convert fixed-point to integer
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;  // Right shift to remove fractional part
}

// Overload insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}
