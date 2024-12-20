#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string name;       // Name of the ClapTrap
    int hitPoints;          // Health of the ClapTrap
    int energyPoints;       // Energy of the ClapTrap
    int attackDamage;       // Attack damage of the ClapTrap

public:
    // Constructors
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);

    // Destructor
    ~ClapTrap();

    // Assignment operator
    ClapTrap& operator=(const ClapTrap& other);

    // Public member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
