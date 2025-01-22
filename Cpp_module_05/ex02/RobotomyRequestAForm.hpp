
#ifndef ROBOTOMYREQUESTAForm_HPP
#define ROBOTOMYREQUESTAForm_HPP

#include "AForm.hpp"

class RobotomyRequestAForm : public AForm
{
private:
    const std::string target;

    RobotomyRequestAForm(void);

public:
    RobotomyRequestAForm(const std::string &target);
    RobotomyRequestAForm(const RobotomyRequestAForm &other);
    ~RobotomyRequestAForm(void);

    RobotomyRequestAForm &operator=(const RobotomyRequestAForm &other);
    const std::string &getTarget(void) const;
    virtual void execute(const Bureaucrat &executor) const;
};

#endif