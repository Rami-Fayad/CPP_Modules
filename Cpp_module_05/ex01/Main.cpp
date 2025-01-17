#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        Form taxForm("Tax Form", 3, 5);

        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;

        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat jane("Jane", 150);
        jane.signForm(taxForm);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
