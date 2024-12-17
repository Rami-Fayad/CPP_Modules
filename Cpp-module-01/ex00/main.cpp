#include "Zombie.hpp"

// Function prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    // Create a zombie dynamically (on the heap)
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie; // Remember to delete it when no longer needed

    randomChump("StackZombie");

    return 0;
}
