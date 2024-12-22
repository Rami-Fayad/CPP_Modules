#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructed\n";
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructed\n";
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed\n";
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Cat assigned\n";
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!\n";
}
