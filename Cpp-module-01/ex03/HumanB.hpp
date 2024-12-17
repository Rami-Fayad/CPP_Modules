#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Pointer to a Weapon (can be null)

public:
    // Constructor
    HumanB(std::string name);
    void setWeapon(Weapon &weapon);
    void attack() const;
};

#endif
