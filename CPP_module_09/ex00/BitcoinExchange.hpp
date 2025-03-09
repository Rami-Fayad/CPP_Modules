#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, double> database;

public:
    // Default Constructor
    BitcoinExchange();

    // Copy Constructor
    BitcoinExchange(const BitcoinExchange& other);

    // Copy Assignment Operator
    BitcoinExchange& operator=(const BitcoinExchange& other);

    // Destructor
    ~BitcoinExchange();

    // Public Methods
    void loadDatabase(const std::string &filename);
    void processInputFile(const std::string &filename) const;

private:
    // Helper functions
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &value) const;
    double getExchangeRate(const std::string &date) const;
};

#endif
