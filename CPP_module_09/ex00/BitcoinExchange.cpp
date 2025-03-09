#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (line.empty() && getline(file, line));

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rateStr;

        if (getline(ss, date, ',') && getline(ss, rateStr))
        {
            double rate = std::strtod(rateStr.c_str(), nullptr); // Safely convert string to double
            database[date] = rate;
        }
    }

    file.close();
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    // Skip empty lines at the beginning
    while (getline(file, line))
    {
        if (line.find_first_not_of(" \t\r\n") != std::string::npos) // Non-empty line found
            break;
    }

    // Ensure the first meaningful line is "date | value"
    std::stringstream ss(line);
    std::string firstWord, separator, secondWord;
    ss >> firstWord >> separator >> secondWord;

    if (firstWord != "date" || separator != "|" || secondWord != "value")
    {
        std::cerr << "Error: missing or invalid header. Expected: 'date | value'" << std::endl;
        return;
    }

    // Process the rest of the file
    while (getline(file, line))
    {
        // Trim spaces and ignore empty lines
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;

        std::stringstream ss(line);
        std::string date, valueStr;

        if (!getline(ss, date, '|') || !getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim spaces
        date.erase(date.find_last_not_of(" \t\r\n") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));

        // Check if the date is valid
        if (!isValidDate(date))
        {
            std::cerr << "Error: Invalid date format => " << date << std::endl;
            continue;
        }

        // Check if the value is valid
        if (!isValidValue(valueStr))
        {
            std::cerr << "Error: Invalid value => " << valueStr << std::endl;
            continue;
        }

        double value = std::strtod(valueStr.c_str(), nullptr); // Safe string to double conversion
        double rate = getExchangeRate(date);

        if (rate != -1)
        {
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
    }

    file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false;

    if (year < 2000 || year > 2099 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2)
    {
        bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 28 + leapYear)
            return false;
    }
    else if (day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
    try
    {
        double num = std::strtod(value.c_str(), nullptr);
        return (num >= 0 && num <= 1000);
    }
    catch (const std::invalid_argument &)
    {
        return false;
    }
    catch (const std::out_of_range &)
    {
        return false;
    }
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    auto it = database.lower_bound(date);

    if (it == database.end() || it->first != date)
    {
        if (it == database.begin())
        {
            std::cerr << "Error: No valid exchange rate found for date " << date << std::endl;
            return -1;
        }
        --it; // Use the latest available exchange rate
    }

    return it->second;
}
