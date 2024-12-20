#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trappy");

    clap1.attack("Target1");
    clap2.takeDamage(5);
    clap2.beRepaired(3);
    clap2.attack("Target2");

    return 0;
}
