#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();

    std::ofstream outFile((target + "_shrubbery").c_str());
    if (!outFile)
        throw std::ios_base::failure("Failed to open file!");

    outFile << "       _-_        " << std::endl;
    outFile << "    /~~   ~~\\    " << std::endl;
    outFile << " /~~         ~~\\ " << std::endl;
    outFile << "{               }" << std::endl;
    outFile << " \\  _-     -_  / " << std::endl;
    outFile << "   ~  \\\\ //  ~   " << std::endl;
    outFile << "        ||       " << std::endl;
    outFile << "        ||       " << std::endl;

    outFile.close();
}
