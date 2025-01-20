
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : Form("PresidentialPardonForm", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : Form("PresidentialPardonForm", 25, 5), target(other.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

const std::string &PresidentialPardonForm::getTarget(void) const
{
    return (this->target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    this->checkExecutability(executor);
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
