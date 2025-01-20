

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : Form("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form("ShrubberyCreationForm", 145, 137), target(other.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
    return (this->target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
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
