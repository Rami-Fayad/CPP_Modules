
#include "Bureaucrat.hpp"

/* Exceptions */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is higher than the maximum!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is lower than the minimum!");
}

/* Constructors and Destructor */

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {}

/* public interface functions */

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->grade = other.grade;
    return (*this);
}

const std::string &Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade == Bureaucrat::maxGrade)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade == Bureaucrat::minGrade)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signAForm(AForm &AForm)
{
    try
    {
        AForm.beSigned(*this);
        std::cout << "Bureaucrat " << this->name << " successfully signed ";
        std::cout << "the AForm " << AForm.getName() << "!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << *this << ". ";
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::executeAForm(const AForm &AForm)
{
    try
    {
        AForm.execute(*this);
        std::cout << this->name << " executes AForm " << AForm.getName() << std::endl;
    }
    catch (AForm::InvalidAFormException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (out);
}
