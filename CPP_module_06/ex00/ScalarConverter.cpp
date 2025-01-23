#include "ScalarConverter.hpp"

// Default Constructor
ScalarConverter::ScalarConverter() {}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other; // No state to copy
}

// Copy Assignment Operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
        // No state to assign
    }
    return *this;
}

// Destructor
ScalarConverter::~ScalarConverter() {}

// Static Method: convert
void ScalarConverter::convert(const std::string& literal) {
    char* end;
    double value;

    // Handle single printable character
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        char singleChar = literal[0];
        value = static_cast<double>(singleChar);

        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    // Handle float literals with 'f' suffix
    if (literal[literal.length() - 1] == 'f' && literal.length() > 1) {
        std::string floatLiteral = literal.substr(0, literal.length() - 1);
        value = strtod(floatLiteral.c_str(), &end);
        if (*end != '\0') {
            std::cout << "Error: Input is not a valid numeric literal" << std::endl;
            return;
        }

        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    // General case: Parse numeric input
    value = strtod(literal.c_str(), &end);
    if (*end != '\0') {
        std::cout << "Error: Input is not a valid numeric literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}


// Private Method: printChar
void ScalarConverter::printChar(double value)
{
    if (std::isnan(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<int>(value)))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

// Private Method: printInt
void ScalarConverter::printInt(double value)
{
    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

// Private Method: printFloat
void ScalarConverter::printFloat(double value)
{
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "float: " << value << "f" << std::endl;
    }
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }
}

// Private Method: printDouble
void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "double: " << value << std::endl;
    }
    else
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    }
}
