
#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationAForm.hpp"
#include "RobotomyRequestAForm.hpp"
#include "PresidentialPardonAForm.hpp"

class Intern
{
private:
    typedef struct s_AForm
    {
        std::string type;
        AForm *form;
    } t_AForm;

public:
    Intern(void);
    Intern(const Intern &other);
    ~Intern(void);

    Intern &operator=(const Intern &other);
    AForm *makeAForm(const std::string &AFormName, const std::string &target) const;
};

#endif