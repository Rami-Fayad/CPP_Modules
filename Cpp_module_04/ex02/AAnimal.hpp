#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();                              // Constructor
    virtual ~AAnimal();                     // Virtual destructor
    AAnimal(const AAnimal& other);          // Copy constructor
    AAnimal& operator=(const AAnimal& other); // Assignment operator

    virtual void makeSound() const = 0;     // Pure virtual function
    std::string getType() const;            // Getter for type
};

#endif // AANIMAL_HPP
