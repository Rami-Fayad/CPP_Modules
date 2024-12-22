#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : brain(new Brain(*other.brain)) {
    type = other.type;
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called!" << std::endl;
    if (this != &other) {
        delete brain;
        brain = new Brain(*other.brain);
        type = other.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
