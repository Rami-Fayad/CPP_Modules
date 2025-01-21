#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
private:
    static const int maxGrade = 1;
    static const int minGrade = 150;
    const std::string name;
    int grade;

    Bureaucrat(void);

public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat(void);

    Bureaucrat &operator=(const Bureaucrat &other);
    const std::string &getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);

private:
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &b);

#endif
