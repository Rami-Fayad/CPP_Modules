#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class Form {
private:
    const std::string name;       // Constant name
    bool isSigned;                // Boolean indicating signed status
    const int gradeToSign;        // Grade required to sign
    const int gradeToExecute;     // Grade required to execute

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
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    ~Form();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat& b);

    // Print function
    void print(std::ostream& os) const;
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
