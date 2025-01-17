#include "Form.hpp"

// Exception messages
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

// Be signed
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Print function
void Form::print(std::ostream& os) const {
    os << "Form " << name
       << ", signed: " << (isSigned ? "yes" : "no")
       << ", grade required to sign: " << gradeToSign
       << ", grade required to execute: " << gradeToExecute;
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Form& f) {
    f.print(os);
    return os;
}
