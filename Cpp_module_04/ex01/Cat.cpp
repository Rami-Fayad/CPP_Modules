#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called!" << std::endl;
}

Cat::Cat(const Cat& other) : brain(new Brain(*other.brain)) {
    type = other.type;
    std::cout << "Cat copy constructor called!" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called!" << std::endl;
    if (this != &other) {
        delete brain;
        brain = new Brain(*other.brain);
        type = other.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
