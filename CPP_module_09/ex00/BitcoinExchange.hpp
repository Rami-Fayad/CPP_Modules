#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>   // for std::strtod (string to double conversion)
#include <stdexcept> // for exception handling

class BitcoinExchange {
private:
    std::map<std::string, double> database;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void processInputFile(const std::string &filename) const;

    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &value) const;
    double getExchangeRate(const std::string &date) const;
};

#endif
