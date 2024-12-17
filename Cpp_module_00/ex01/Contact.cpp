#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), 
                     phoneNumber(""), darkestSecret("") {}

void Contact::setDetails(const std::string& firstName, const std::string& lastName, 
                         const std::string& nickname, const std::string& phoneNumber, 
                         const std::string& darkestSecret) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

void Contact::displaySummary(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
              << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
              << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}

void Contact::displayDetails() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
    return firstName.empty();
}
