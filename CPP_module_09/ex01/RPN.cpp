#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

// This function processes the given RPN expression
void RPN::processExpression(const std::string &expression) {
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Operator found, perform the operation
            if (stack.size() < 2) {
                std::cerr << "Error: Too few operands\n";
                return;
            }
            performOperation(token[0]);
        } else {
            // Try converting token to an integer
            int number = atoi(token.c_str());  // Using atoi here
            if (number < 10) {
                stack.push(number);
            } else {
                std::cerr << "Error: Numbers must be less than 10\n";
                return;
            }
        }
    }

    // At the end of processing, there should be exactly one value in the stack
    if (stack.size() == 1) {
        std::cout << stack.top() << std::endl;
    } else {
        std::cerr << "Error: Invalid RPN expression\n";
    }
}

// Perform an operation on the top two elements of the stack
void RPN::performOperation(char op) {
    int b = stack.top(); stack.pop();
    int a = stack.top(); stack.pop();
    int result;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                std::cerr << "Error: Division by zero\n";
                return;
            }
            result = a / b;
            break;
        default:
            std::cerr << "Error: Unknown operator\n";
            return;
    }
    stack.push(result);
}
