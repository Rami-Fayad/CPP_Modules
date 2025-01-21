#include "Form.hpp"

#include "Form.hpp"



Form::GradeTooHighException::GradeTooHighException(void)
{
    this->msg = "The grade is higher than the maximum!";
}

Form::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg) {}

const char *Form::GradeTooHighException::what() const throw()
{
    return (this->msg);
}

Form::GradeTooLowException::GradeTooLowException(void)
{
    this->msg = "The grade is lower than the minimum!";
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg) {}

const char *Form::GradeTooLowException::what() const throw()
{
    return (this->msg);
}

/* Constructors and the destructor of the Form */

Form::Form() : name(), gradeToSign(1), gradeToExecute(1), _signed(false) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();

    this->_signed = false;
}

Form::Form(const Form &copy) : name(copy.name), gradeToSign(copy.gradeToSign),
                               gradeToExecute(copy.gradeToExecute), _signed(copy._signed) {}

Form::~Form() {}

// Here I applied the othodoxx form 

Form &Form::operator=(const Form &other)
{
    this->_signed = other._signed;
    return (*this);
}

const std::string &Form::getName(void) const
{
    return (this->name);
}

int Form::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute(void) const
{
    return (this->gradeToExecute);
}

bool Form::isSigned(void) const
{
    return (this->_signed);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException("Bureaucrat is not authorized to sign the form!");
    this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
    out << "Form: " << form.getName() << " Signed: " << (form.isSigned() ? "true" : "false");
    out << " GradeToSign: " << form.getGradeToSign();
    out << " GradeToExecute: " << form.getGradeToExecute();

    return (out);
}
