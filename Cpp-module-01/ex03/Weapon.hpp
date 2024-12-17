#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;  // Weapon type

public:
    // Constructor
    Weapon(std::string const &type);
    
    const std::string& getType() const;

    void setType(std::string const &type);
};

#endif
