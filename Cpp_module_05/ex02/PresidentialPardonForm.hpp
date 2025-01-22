#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    const std::string target;

    PresidentialPardonForm(void);

public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm(void);

  
    const std::string &getTarget(void) const;
    void execute(const Bureaucrat &executor) const;
};

#endif