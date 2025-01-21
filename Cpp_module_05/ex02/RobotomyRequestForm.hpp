
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
    const std::string target;

    RobotomyRequestForm(void);

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    const std::string &getTarget(void) const;
    virtual void execute(const Bureaucrat &executor) const;
};

#endif