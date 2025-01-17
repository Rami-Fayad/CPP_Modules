#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        Bureaucrat jane("Jane", 150);

        std::cout << john << std::endl;
        std::cout << jane << std::endl;

        // Increment and decrement
        john.incrementGrade();
        jane.decrementGrade();

        std::cout << john << std::endl;
        std::cout << jane << std::endl;

        // Trigger exceptions
        john.incrementGrade(); // Too high
        jane.decrementGrade(); // Too low
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
