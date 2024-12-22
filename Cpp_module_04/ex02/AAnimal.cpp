#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal constructed\n";
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "AAnimal copy constructed\n";
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destroyed\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "AAnimal assigned\n";
    return *this;
}

std::string AAnimal::getType() const {
    return type;
}
