#include "Zombie.hpp" 


Zombie::Zombie(std::string name) : name(name) {} ;

Zombie::~Zombie() {
    std::cout << name << ": has been destroyed!" << std::endl;
}

// Announce function
void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}