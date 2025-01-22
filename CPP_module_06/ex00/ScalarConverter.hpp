#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter {
public:
    // Orthodox Canonical Form
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    // Static method to convert the input
    static void convert(const std::string& literal);

private:
    // Helper methods to handle specific types
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
};

#endif
