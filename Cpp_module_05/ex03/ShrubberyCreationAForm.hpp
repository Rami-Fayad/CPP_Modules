#ifndef SHRUBBERYCREATIONAForm_HPP
#define SHRUBBERYCREATIONAForm_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationAForm : public AForm
{
private:
  const std::string target;

  ShrubberyCreationAForm(void);

public:
  ShrubberyCreationAForm(const std::string &target);
  ShrubberyCreationAForm(const ShrubberyCreationAForm &other);
  ~ShrubberyCreationAForm(void);

  ShrubberyCreationAForm &operator=(const ShrubberyCreationAForm &other);

  const std::string &getTarget(void) const;
  void execute(const Bureaucrat &executor) const;
};

#endif
