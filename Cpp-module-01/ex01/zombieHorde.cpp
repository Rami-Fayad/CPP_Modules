#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
     if (N <= 0) {
        std::cout << "Error: Number of zombies must be greater than 0!" << std::endl;
        return NULL; // Handle invalid input
    }

    Zombie* horde = new Zombie[N];

    // Initialize each Zombie's name
    for (int i = 0; i < N; ++i) {
        horde[i].setName(name);
    }

    return horde;
}