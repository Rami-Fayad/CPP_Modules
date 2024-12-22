#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // ScavTrap tests
    ScavTrap scav("Scavy");
    scav.attack("enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n";

    // FragTrap tests
    FragTrap frag("Fraggy");
    frag.attack("another enemy");
    frag.takeDamage(40);
    frag.beRepaired(30);
    frag.highFivesGuys();

    return 0;
}
