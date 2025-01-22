

#include "ShrubberyCreationAForm.hpp"

ShrubberyCreationAForm::ShrubberyCreationAForm(void)
    : AForm("ShrubberyCreationAForm", 145, 137), target("") {}

ShrubberyCreationAForm::ShrubberyCreationAForm(const std::string &target)
    : AForm("ShrubberyCreationAForm", 145, 137), target(target) {}

ShrubberyCreationAForm::ShrubberyCreationAForm(const ShrubberyCreationAForm &other)
    : AForm("ShrubberyCreationAForm", 145, 137), target(other.getTarget()) {}

ShrubberyCreationAForm::~ShrubberyCreationAForm(void) {}

ShrubberyCreationAForm &ShrubberyCreationAForm::operator=(const ShrubberyCreationAForm &other)
{
    if (this != &other)
    {
    }
    return *this;
}

const std::string &ShrubberyCreationAForm::getTarget(void) const
{
    return (this->target);
}

void ShrubberyCreationAForm::execute(const Bureaucrat &executor) const
{
    std::ofstream file;
    std::string name;

    this->checkExecutability(executor);
    name = target + "_shrubbery";
    file.open(name.c_str(), std::ofstream::out);

    file << "       _-_        " << std::endl;
    file << "    /~~   ~~\\    " << std::endl;
    file << " /~~         ~~\\ " << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  / " << std::endl;
    file << "   ~  \\\\ //  ~   " << std::endl;
    file << "        ||       " << std::endl;
    file << "        ||       " << std::endl;
    file.close();
}
