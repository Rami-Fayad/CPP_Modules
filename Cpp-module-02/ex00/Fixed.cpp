#include "Fixed.hpp"

Fixed::Fixed() :_fixedPointValue(0){
    std::cout << "default Constructor Called" << std::endl;
}

Fixed::Fixed (const Fixed& other) {
     std::cout << "Copy constructor called" << std::endl;
    *this = other; 
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) { // Self-assignment check
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Getter for raw value
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// Setter for raw value
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}