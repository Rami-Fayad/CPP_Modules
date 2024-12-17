#include "Harl.hpp"

int main() {
    Harl harl;

    // Test complaints for each level
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    return 0;
}
