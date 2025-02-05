#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>\n";
        return 1;
    }

    RPN rpn;
    rpn.processExpression(argv[1]);

    return 0;
}
