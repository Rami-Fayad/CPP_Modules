#include "BitcoinExchange.hpp"

// Default Constructor
BitcoinExchange::BitcoinExchange() = default;

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {

    database = other.database;
}

// Copy Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) { // Prevent self-assignment
        database = other.database;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {
    // No dynamic memory allocation to free, so destructor is empty
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (line.empty() && std::getline(file, line));

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;

        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            double rate = std::strtod(rateStr.c_str(), nullptr);
            database[date] = rate;
        }
    }

    file.close();
}

void BitcoinExchange::processInputFile(const std::string &filename) const {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find_first_not_of(" \t\r\n") != std::string::npos) {
            break;
        }
    }

    std::stringstream ss(line);
    std::string firstWord, separator, secondWord;
    ss >> firstWord >> separator >> secondWord;

    if (firstWord != "date" || separator != "|" || secondWord != "value") {
        std::cerr << "Error: missing or invalid header. Expected: 'date | value'" << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;

        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date.erase(date.find_last_not_of(" \t\r\n") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));

        if (!isValidDate(date)) {
            std::cerr << "Error: Invalid date format => " << date << std::endl;
            continue;
        }

        if (!isValidValue(valueStr)) {
            std::cerr << "Error: Invalid value => " << valueStr << std::endl;
            continue;
        }

        double value = std::strtod(valueStr.c_str(), nullptr);
        double rate = getExchangeRate(date);

        if (rate != -1) {
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
    }

    file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false;

    if (year < 2000 || year > 2099 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 28 + leapYear)
            return false;
    } else if (day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) const {
    try {
        double num = std::strtod(value.c_str(), nullptr);
        return (num >= 0 && num <= 1000);
    } catch (const std::invalid_argument &) {
        return false;
    } catch (const std::out_of_range &) {
        return false;
    }
}

double BitcoinExchange::getExchangeRate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = database.lower_bound(date);

    if (it == database.end() || it->first != date) {
        if (it == database.begin()) {
            std::cerr << "Error: No valid exchange rate found for date " << date << std::endl;
            return -1;
        }
        --it; // Use the latest available exchange rate
    }

    return it->second;
}
