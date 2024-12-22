#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal* animals[6];

    // Creating Dog and Cat objects
    for (int i = 0; i < 3; ++i) {
        animals[i] = new Dog();
        animals[i + 3] = new Cat();
    }

    // Printing sound
    for (int i = 0; i < 6; ++i) {
        animals[i]->makeSound();
    }

    // Deleting objects
    for (int i = 0; i < 6; ++i) {
        delete animals[i];
    }

    return 0;
}
