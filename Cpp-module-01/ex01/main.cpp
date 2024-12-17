
#include "Zombie.hpp"
Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 5; // Number of zombies in the horde
    std::string name = "HordeZombie";

    // Create a horde of zombies
    Zombie* horde = zombieHorde(N, name);

    if (horde != NULL) {
       
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
        }

        // Clean up the dynamically allocated zombies
        delete[] horde;
    } else {
        std::cout << "Error: Could not create zombie horde!" << std::endl;
    }

    return 0;
}



