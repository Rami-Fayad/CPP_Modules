
#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other) { *this = other; }

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

AForm *Intern::makeAForm(const std::string &AFormName, const std::string &target) const
{
    AForm *result;

    t_AForm data[] =
        {
            {"presidential pardon", new PresidentialPardonAForm(target)},
            {"robotomy request", new RobotomyRequestAForm(target)},
            {"shrubbery creation", new ShrubberyCreationAForm(target)},
            {"", NULL}};

    result = NULL;
    for (int i = 0; data[i].form != NULL; i++)
    {
        if (data[i].type == AFormName)
            result = data[i].form;
        else
            delete data[i].form;
    }

    if (result == NULL)
        std::cout << "Intern could not find the AForm " << AFormName << std::endl;
    else
        std::cout << "Intern creates " << AFormName << std::endl;
    return result;
}
