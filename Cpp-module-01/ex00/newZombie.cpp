#include "Zombie.hpp"

// Creates a zombie dynamically
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
