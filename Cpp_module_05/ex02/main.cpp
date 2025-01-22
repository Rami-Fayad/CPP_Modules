#include "Bureaucrat.hpp"
#include "ShrubberyCreationAForm.hpp"
#include "RobotomyRequestAForm.hpp"
#include "PresidentialPardonAForm.hpp"

int main() {
    srand(time(0));
    try {
        Bureaucrat john("John", 137);
        ShrubberyCreationAForm AForm1("Home");
        RobotomyRequestAForm AForm2("Target1");
        PresidentialPardonAForm AForm3("Target2");

        john.signAForm(AForm1);
        john.signAForm(AForm2);
        john.signAForm(AForm3);

        john.executeAForm(AForm1);
        john.executeAForm(AForm2);
        john.executeAForm(AForm3);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}