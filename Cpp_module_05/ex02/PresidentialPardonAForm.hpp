#ifndef PRESIDENTIALPARDONAForm_HPP
#define PRESIDENTIALPARDONAForm_HPP

#include "AForm.hpp"

class PresidentialPardonAForm : public AForm
{
private:
    const std::string target;

    PresidentialPardonAForm(void);

public:
    PresidentialPardonAForm(const std::string &target);
    PresidentialPardonAForm(const PresidentialPardonAForm &other);
    ~PresidentialPardonAForm(void);

   PresidentialPardonAForm &operator=(const PresidentialPardonAForm &other);
    const std::string &getTarget(void) const;
    void execute(const Bureaucrat &executor) const;
};

#endif