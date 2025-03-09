#include "RPN.hpp"
RPN::RPN() {}

// Copy constructor
RPN::RPN(const RPN &other) {
    this->stack = other.stack;  
}

RPN &RPN::operator=(const RPN &rhs) {
    if (this != &rhs) {
        this->stack = rhs.stack;  // Copy stack
    }
    return *this;
}

// Destructor
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
            // Validate the token as a single-digit number
            if (token.size() == 1 && std::isdigit(token[0])) {
                int number = token[0] - '0';  // Convert char to int
                stack.push(number);
            } else {
                std::cerr << "Error: Invalid token or number too large\n";
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
