#include "Harl.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Please provide one level of complaint (DEBUG, INFO, WARNING, ERROR)." << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(argv[1]);

    return 0;
}
