#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
    const std::string target;

    ShrubberyCreationForm(void);

public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm(void);

    
    const std::string &getTarget(void) const;
    void execute(const Bureaucrat &executor) const;
};

#endif