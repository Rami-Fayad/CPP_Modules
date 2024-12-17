#include "PhoneBook.hpp"
#include <iostream> // For standard I/O operations (e.g., std::cin, std::cout)
#include <iomanip>  // For formatting output (e.g., std::setw)
#include <string>   // For the std::string class and its functions
#include <sstream>  // For string stream manipulation (e.g., std::istringstream)
#include <cctype> // For std::isdigit

PhoneBook::PhoneBook() : nextIndex(0) {}

void PhoneBook::addContact() {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

    contacts[nextIndex].setDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
nextIndex = (nextIndex + 1) % 8; 

}

void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    // Display the contacts in the array
    for (int i = 0; i < 8; ++i) {
        if (!contacts[i].isEmpty()) {  // Only show non-empty contacts
            contacts[i].displaySummary(i + 1);  // Display the summary of each contact
        }
    }

    std::cout << "Enter the index of the contact to view details: ";
    std::string input;
    std::getline(std::cin, input);

    // Validate input is numeric (C++98 alternative to std::all_of)
    bool isNumeric = true;
    for (size_t i = 0; i < input.length(); ++i) {
        if (!std::isdigit(input[i])) {
            isNumeric = false;
            break;
        }
    }

    if (!isNumeric) {
        std::cout << "Error: Invalid input. Returning to main menu..." << std::endl;
        return;
    }

    // Convert input to integer (C++98 alternative to std::stoi)
    std::istringstream iss(input);
    int index = 0;
    iss >> index;

    if (index < 1 || index > 8 || contacts[index - 1].isEmpty()) {
        std::cout << "Error: Invalid index. Returning to main menu..." << std::endl;
        return;
    }
    contacts[index - 1].displayDetails();
}
