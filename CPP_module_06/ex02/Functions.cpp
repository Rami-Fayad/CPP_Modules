#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Generate a random instance of A, B, or C
Base *generate()
{
    std::srand((unsigned int)std::time(0)); // Seed random number generator
    int randNum = std::rand() % 3;          // Generate a random number between 0 and 2

    switch (randNum)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    default:
        return new C();
    }
}

// Identify type using a Base pointer
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}

// Identify type using a Base reference
void identify(Base &p)
{
    // Try dynamic_cast for each derived type and handle accordingly
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (...)
    {
        try
        {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (...)
        {
            try
            {
                (void)dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            }
            catch (...)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}
