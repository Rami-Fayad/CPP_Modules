
#include "Intern.hpp"

int main()
{
    Intern intern;
    AForm *f;

    f = intern.makeAForm("shrubbery creation", "28C");
    std::cout << *f << std::endl;
    std::cout << std::endl;
    delete f;

    f = intern.makeAForm("robotomy request", "28B");
    std::cout << *f << std::endl;
    std::cout << std::endl;
    delete f;
    f = intern.makeAForm("presidential pardon", "28A");
    std::cout << *f << std::endl;
    std::cout << std::endl;
    delete f;

    f = intern.makeAForm("undefined", "0U");
    delete f;

    return 0;
}
