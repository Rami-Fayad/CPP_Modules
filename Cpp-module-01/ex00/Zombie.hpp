#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name; // The zombie's name

public:

    Zombie(std::string name);

    
    ~Zombie();

    // Member function for the zombie to announce itself
    void announce() const;
};

#endif
