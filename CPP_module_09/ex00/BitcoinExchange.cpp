#include "BitcoinExchange.hpp"

// Constructor
BitcoinExchange::BitcoinExchange() {}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Load database from file
void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open database file.\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, priceStr;

        if (std::getline(iss, date, ',') && std::getline(iss, priceStr)) {
            try {
                double price = std::strtod(priceStr.c_str(), NULL);
                database[date] = price;
            } catch (const std::exception &e) {
                std::cerr << "Error: Invalid number format in database.\n";
            }
        }
    }
    file.close();
}

// Process input file and compute results
void BitcoinExchange::processInputFile(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open input file.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == "date | value") // Skip header
            continue;

        std::istringstream iss(line);
        std::string date, valueStr;

        if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
            valueStr.erase(0, valueStr.find_first_not_of(" ")); // Trim leading spaces

            try {
                double value = std::strtod(valueStr.c_str(), NULL);

                if (value < 0) {
                    std::cerr << "Error: Not a positive number.\n";
                    continue;
                } else if (value > 1000) {
                    std::cerr << "Error: Too large a number.\n";
                    continue;
                }

                std::map<std::string, double>::const_iterator it = database.lower_bound(date);
                if (it == database.end() || it->first != date) {
                    if (it != database.begin()) 
                        --it;
                    else {
                        std::cerr << "Error: No matching date found.\n";
                        continue;
                    }
                }

                std::cout << date << " => " << value << " = " << value * it->second << '\n';
            } catch (const std::exception &e) {
                std::cerr << "Error: Bad input => " << line << '\n';
            }
        } else {
            std::cerr << "Error: Malformed input line.\n";
        }
    }
    file.close();
}
