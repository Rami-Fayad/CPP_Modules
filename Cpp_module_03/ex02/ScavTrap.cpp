#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap " << _name << " copy constructed.\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructed.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode.\n";
}
