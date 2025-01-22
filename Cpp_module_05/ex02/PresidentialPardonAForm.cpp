
#include "PresidentialPardonAForm.hpp"

PresidentialPardonAForm::PresidentialPardonAForm(void)
    : AForm("PresidentialPardonAForm", 25, 5), target("") {}

PresidentialPardonAForm::PresidentialPardonAForm(const std::string &target)
    : AForm("PresidentialPardonAForm", 25, 5), target(target) {}

PresidentialPardonAForm::PresidentialPardonAForm(const PresidentialPardonAForm &other)
    : AForm("PresidentialPardonAForm", 25, 5), target(other.getTarget())
{
}

PresidentialPardonAForm::~PresidentialPardonAForm(void) {}

PresidentialPardonAForm &PresidentialPardonAForm::operator=(const PresidentialPardonAForm &other)
{
    if (this != &other)
    {
        // If necessary, add code to perform deep copying here.
        // But since target is const, no assignment is needed for it.
      
    }
    return *this;
}

const std::string &PresidentialPardonAForm::getTarget(void) const
{
    return (this->target);
}

void PresidentialPardonAForm::execute(const Bureaucrat &executor) const
{
    this->checkExecutability(executor);
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
