#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Unknown") {
    std::cout << "Animal constructor called!" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called!" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
