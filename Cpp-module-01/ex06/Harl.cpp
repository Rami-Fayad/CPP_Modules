#include "Harl.hpp"

// Define private member functions for each level

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

// Public member function to filter the complaints
void Harl::complain(std::string level) {
    // Use a switch statement to filter based on the level
    if (level == "DEBUG") {
        this->debug();
        this->info();
        this->warning();
        this->error();
    } else if (level == "INFO") {
        this->info();
        this->warning();
        this->error();
    } else if (level == "WARNING") {
        this->warning();
        this->error();
    } else if (level == "ERROR") {
        this->error();
    } else {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        std::cout << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off." << std::endl;
    }
}
