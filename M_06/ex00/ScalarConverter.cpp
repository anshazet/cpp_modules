/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:35:42 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/08 11:53:59 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <sstream>
#include <cctype>

ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
    if (isInt(literal))
    {
        convertInt(literal);
    }
    else if (isChar(literal))
    {
        convertChar(literal);
    }
    else if (isDouble(literal))
    {
        convertDouble(literal);
    }
        else if (isFloat(literal))
    {
        convertFloat(literal);
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}

void ScalarConverter::convertChar(const std::string &literal)
{
    char c;
    if (literal.length() == 1)
    {
        c = literal[0];  // Single character without quotes
    }
    else if (literal.length() == 3 || literal[0] == '\'' || literal[2] == '\'')
    {
        c = literal[1]; // Character enclosed in single quotes
    }
    else
    {
        throw std::runtime_error("Invalid character literal format.");
    }

    // Convert to char
    std::cout << "char: ";
    if (isPrintable(c))
    {
        std::cout << "'" << c << "'" << std::endl;
    }
    else
    {
        std::cout << "Non displayable" << std::endl;
    }

    // Convert to int
    std::cout << "int: " << static_cast<int>(c) << std::endl;

    // Convert to float
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;

    // Convert to double
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

/*
An std::istringstream object named iss is created with the string literal.
The >> operator is then used to try and extract an integer value from this string.
If the extraction fails (for example, if the string does not contain a valid integer),
the if condition becomes true, and an error message is printed.
*/
void ScalarConverter::convertInt(const std::string &literal)
{
    // Convert the literal to an integer
    std::istringstream iss(literal);
    long int value;
    if (!(iss >> value))
    {
        std::cerr << "Error: Invalid integer literal" << std::endl;
        return;
    }

    // Check for overflow or underflow
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int intValue = static_cast<int>(value);

        // Convert to char
        std::cout << "char: ";
        if (isPrintable(static_cast<char>(intValue)))
        {
            std::cout << "'" << static_cast<char>(intValue) << "'" << std::endl;
        }
        else
        {
            std::cout << "Non displayable" << std::endl;
        }

        // Print as int
        std::cout << "int: " << intValue << std::endl;
    }

    // Convert to float
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

    // Convert to double
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal)
{
    if (literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return;
    }
    if (literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    else if (literal == "nanf")
    {
        handleSpecialCases(std::numeric_limits<float>::quiet_NaN(), "float");
        return;
    }

    std::string number = literal;
    char lastChar = literal[literal.length() - 1];
    if (lastChar == 'f' || lastChar == 'F')
    {
        // Remove the 'f' or 'F' suffix for parsing
        number = literal.substr(0, literal.size() - 1);
    }

    std::istringstream iss(number);
    float value;
    if (!(iss >> value))
    {
        std::cerr << "Error: Invalid float literal" << std::endl;
        return;
    }

    // Display conversion results
    displayConversions(static_cast<double>(value));
}

void ScalarConverter::convertDouble(const std::string &literal)
{
    if (literal == "inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return;
    }
    if (literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    if (literal == "nan")
    {
        handleSpecialCases(std::numeric_limits<double>::quiet_NaN(), "double");
        return;
    }

    else
    {
        std::istringstream iss(literal);
        double value;
        if (!(iss >> value))
        {
            std::cerr << "Error: Invalid double literal" << std::endl;
            return;
        }

        // Display conversion results
        displayConversions(value);
    }
}

// Common method for displaying conversions
void ScalarConverter::displayConversions(double value)
{
    // Convert to char
    std::cout << "char: ";
    char charValue = static_cast<char>(value);
    if (isPrintable(charValue))
    {
        std::cout << "'" << charValue << "'" << std::endl;
    }
    else
    {
        std::cout << "Non displayable" << std::endl;
    }

    // Convert to int
    std::cout << "int: ";
    if (value > static_cast<double>(std::numeric_limits<int>::max()) || value < static_cast<double>(std::numeric_limits<int>::min()))
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(value) << std::endl;
    }

    // Print as float and double
    std::cout << "float: ";
    if (std::isnan(value))
    {
        std::cout << "nanf" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }

    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

bool ScalarConverter::isPrintable(char c)
{
    return std::isprint(static_cast<unsigned char>(c)) != 0;
}

bool ScalarConverter::isChar(const std::string &literal)
{
    // Check for the standard C++ char literal format: 'c'
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        return true;
    }

    // Check for a single character, but not a digit.
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        return true;
    }

    return false;
}


bool ScalarConverter::isInt(const std::string &literal)
{
    std::istringstream iss(literal);
    int value;
    char leftover;
    if ((iss >> value) && !(iss >> leftover))
    {
        // Successfully read an int and no leftover characters
        return true;
    }
    return false;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    if (literal == "nanf" || literal == "inff" || literal == "-inff")
    {
        return true;
    }

    if (!literal.empty())
    {
        char lastChar = literal[literal.length() - 1];
        if (lastChar == 'f' || lastChar == 'F')
        {
            return true;
        }
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    // Special literals that are treated as doubles
    if (literal == "nan" || literal == "inf" || literal == "-inf")
    {
        return true;
    }

    // Exclude float literals
    if (!literal.empty())
    {
        char lastChar = literal[literal.length() - 1];
        if (lastChar == 'f' || lastChar == 'F')
        {
            return false; // It's a float, not a double
        }
    }

    // Double literals typically have a decimal point or are special cases like inf/nan
    return literal.find('.') != std::string::npos;
}

void ScalarConverter::handleSpecialCases(double value, const std::string &type)
{
    (void)value;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (type == "float")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (type == "double")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}
