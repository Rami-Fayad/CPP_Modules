#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    srand(time(0));
    try {
        Bureaucrat john("John", 137);
        ShrubberyCreationForm form1("Home");
        RobotomyRequestForm form2("Target1");
        PresidentialPardonForm form3("Target2");

        john.signForm(form1);
        john.signForm(form2);
        john.signForm(form3);

        john.executeForm(form1);
        john.executeForm(form2);
        john.executeForm(form3);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}