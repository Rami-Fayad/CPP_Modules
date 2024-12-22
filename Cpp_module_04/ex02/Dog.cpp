#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructed\n";
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructed\n";
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Dog assigned\n";
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!\n";
}
