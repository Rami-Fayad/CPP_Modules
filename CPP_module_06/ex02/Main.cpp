#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate();
void identify(Base *p);
void identify(Base &p);

int main()
{
    // Generate a random Base object
    Base *randomBase = generate();

    // Identify the type using a pointer
    std::cout << "Identifying with pointer: ";
    identify(randomBase);

    // Identify the type using a reference
    std::cout << "Identifying with reference: ";
    identify(*randomBase);

    // Clean up
    delete randomBase;

    return 0;
}
