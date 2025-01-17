#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
private:
    const std::string name; // Constant name
    int grade;              // Grade ranges from 1 to 150

public:
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // Constructor and destructor
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Member functions
    void incrementGrade();
    void decrementGrade();

    void print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
