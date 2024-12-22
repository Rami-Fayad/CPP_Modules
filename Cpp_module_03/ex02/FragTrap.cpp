#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed.\n";
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap " << _name << " copy constructed.\n";
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructed.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests a high five! 🙌\n";
}
