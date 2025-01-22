
#include "RobotomyRequestAForm.hpp"

RobotomyRequestAForm::RobotomyRequestAForm(void)
	: AForm("RobotomyrequestAForm", 72, 45), target("") {}

RobotomyRequestAForm::RobotomyRequestAForm(const std::string &target)
	: AForm("RobotomyrequestAForm", 72, 45), target(target) {}

RobotomyRequestAForm::RobotomyRequestAForm(const RobotomyRequestAForm &other)
	: AForm("RobotomyrequestAForm", 72, 45), target(other.getTarget()) {}

RobotomyRequestAForm::~RobotomyRequestAForm(void) {}

RobotomyRequestAForm &RobotomyRequestAForm::operator=(const RobotomyRequestAForm &other)
{
	if (this != &other)
	{
		
	}
	return *this;
}

const std::string &RobotomyRequestAForm::getTarget(void) const
{
	return (this->target);
}

void RobotomyRequestAForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);

	std::cout << "* Unbearable drilling noises *" << std::endl;
	if (rand() % 2)
	{
		std::cout << "The victi... " << this->target;
		std::cout << " has been successfully robotomized!" << std::endl;
	}
	else
		std::cout << "The robotomization on " << this->target << " failed!" << std::endl;
}
