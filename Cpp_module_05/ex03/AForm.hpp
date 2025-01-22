
#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

class Bureaucrat;

class AForm
{
private:
	static const int maxGrade = 1;
	static const int minGrade = 150;

	const std::string name;
	const int gradeToSign;
	const int gradeToExecute;
	bool _signed;

	AForm(void);

protected:
	void checkExecutability(const Bureaucrat &executor) const;

public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecutre);
	AForm(const AForm &other);
	virtual ~AForm(void);

	AForm &operator=(const AForm &other);
	const std::string &getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool isSigned(void) const;
	void beSigned(const Bureaucrat &b);
	virtual void execute(const Bureaucrat &executor) const = 0;

public:
	class GradeTooHighException : public std::exception
	{
	private:
		const char *msg;

	public:
		GradeTooHighException(void);
		GradeTooHighException(const char *msg);
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
		const char *msg;

	public:
		GradeTooLowException(void);
		GradeTooLowException(const char *msg);
		const char *what() const throw();
	};
	class InvalidAFormException : public std::exception
	{
	private:
		const char *msg;

	public:
		InvalidAFormException(void);
		InvalidAFormException(const char *msg);
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm &AForm);

#endif
