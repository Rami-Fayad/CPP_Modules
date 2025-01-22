
#include "AForm.hpp"

/* Exceptions */

AForm::GradeTooHighException::GradeTooHighException(void)
{
	this->msg = "The grade is higher than the maximum!";
}

AForm::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg) {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (this->msg);
}

AForm::GradeTooLowException::GradeTooLowException(void)
{
	this->msg = "The grade is lower than the minimum!";
}

AForm::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg) {}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (this->msg);
}

AForm::InvalidAFormException::InvalidAFormException(void)
{
	this->msg = "The AForm cannot be executed!";
}

AForm::InvalidAFormException::InvalidAFormException(const char *msg) : msg(msg) {}

const char *AForm::InvalidAFormException::what() const throw()
{
	return (this->msg);
}

/* Constructors and the destructor of the AForm */

AForm::AForm() : name(), gradeToSign(1), gradeToExecute(1), _signed(false) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();

	this->_signed = false;
}

AForm::AForm(const AForm &copy) : name(copy.name), gradeToSign(copy.gradeToSign),
							   gradeToExecute(copy.gradeToExecute), _signed(copy._signed) {}

AForm::~AForm() {}

/* Public Interface functions */

AForm &AForm::operator=(const AForm &other)
{
	this->_signed = other._signed;
	return (*this);
}

const std::string &AForm::getName(void) const
{
	return (this->name);
}

int AForm::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

bool AForm::isSigned(void) const
{
	return (this->_signed);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException("Bureaucrat is not authorized to sign the AForm!");
	this->_signed = true;
}

void AForm::checkExecutability(const Bureaucrat &executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException("Bureaucrat is not authorized to execute the AForm!");
	if (!this->_signed)
		throw InvalidAFormException("Not signed AForms cannot be executed!");
}

std::ostream &operator<<(std::ostream &out, AForm &AForm)
{
	out << "AForm: " << AForm.getName() << ", Signed: " << (AForm.isSigned() ? "true" : "false");
	out << ", GradeToSign: " << AForm.getGradeToSign();
	out << ", GradeToExecute: " << AForm.getGradeToExecute();

	return (out);
}
