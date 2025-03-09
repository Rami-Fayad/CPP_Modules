#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>  // For std::atoi
#include <cctype>   // For std::isdigit

class RPN {
private:
    std::stack<int> stack;

public:
    // Orthodox Canonical Form
    RPN();                          // Default constructor
    RPN(const RPN &other);           // Copy constructor
    RPN &operator=(const RPN &rhs);  // Copy assignment operator
    ~RPN();                          // Destructor

    void processExpression(const std::string &expression);
    void performOperation(char op);
};

#endif
