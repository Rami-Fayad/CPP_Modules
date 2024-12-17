#include "Zombie.hpp"
Zombie ::Zombie() : name("Unnamed Zombie")  {} ;
Zombie :: Zombie (std::string name) : name(name) {};

Zombie::~Zombie () {
    std::cout << name << "has been destroyed " << std::endl; 
}

void ::Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name) {
    this->name = name;
}