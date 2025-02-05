#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>  // For atoi

class RPN {
private:
    std::stack<int> stack;

public:
    RPN();
    ~RPN();

    void processExpression(const std::string &expression);
    void performOperation(char op);
};

#endif
