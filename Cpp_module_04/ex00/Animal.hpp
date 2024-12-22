#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type; // Protected so derived classes can access it

public:
    // Constructors and destructor
    Animal();
    virtual ~Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);

    // Public member functions
    virtual void makeSound() const; // Virtual function for polymorphism
    std::string getType() const;
};

#endif
