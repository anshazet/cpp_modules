/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:35:42 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/06 14:41:43 by ashalagi         ###   ########.fr       */
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
    // Handle "nan" and "nanf" as special cases
    if (literal == "nan") // || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;  // Corrected output
        std::cout << "double: nan" << std::endl;
        return;
    }

    // Continue with type detection for other cases
    if (isChar(literal))
    {
        convertChar(literal);
    }
    else if (isInt(literal))
    {
        convertInt(literal);
    }
    else if (isFloat(literal))
    {
        convertFloat(literal);
    }
    else if (isDouble(literal))
    {
        convertDouble(literal);
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}

void ScalarConverter::convertChar(const std::string &literal)
{
    if (literal.length() != 3 || literal[0] != '\'' || literal[2] != '\'')
    {
        throw std::runtime_error("Invalid character literal format.");
    }
    char c = literal[1];

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
    if (literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
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
    if (literal == "nan") // || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;  // Corrected output
        std::cout << "double: nan" << std::endl;
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
    // A valid char literal in C++ has exactly 3 characters: opening quote, the character, closing quote
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        // Further checks can be added here if necessary
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
    if (literal.empty())
    {
        return false;
    }

    // Check if the last character is 'f' or 'F'
    char lastChar = literal[literal.length() - 1];
    if (lastChar == 'f' || lastChar == 'F')
    {
        // Further validation can be added here if necessary
        return true;
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    if (literal.empty())
    {
        return false;
    }

    // Special literals that are treated as doubles
    if (literal == "nan" || literal == "-inf" || literal == "+inf")
    {
        return true;
    }

    // Exclude float literals
    char lastChar = literal[literal.length() - 1];
    if (lastChar == 'f' || lastChar == 'F')
    {
        return false; // It's a float, not a double
    }

    // Double literals typically have a decimal point
    return literal.find('.') != std::string::npos;
}


void ScalarConverter::handleSpecialCases(double value, const std::string &type)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (type == "float")
    {
        std::cout << "float: " << (std::isinf(value) ? (value < 0 ? "-inff" : "+inff") : "nanf") << std::endl;
        std::cout << "double: " << (std::isinf(static_cast<double>(value)) ? (value < 0 ? "-inf" : "+inf") : "nan") << std::endl;
    }
    else if (type == "double")
    {
        std::cout << "float: " << (std::isinf(static_cast<float>(value)) ? (value < 0 ? "-inff" : "+inff") : "nanf") << std::endl;
        std::cout << "double: " << (std::isinf(value) ? (value < 0 ? "-inf" : "+inf") : "nan") << std::endl;
    }
}

/*
void ScalarConverter::convertFloat(const std::string &literal)
{
    std::istringstream iss(literal);
    float value;

    if (literal == "nanf")
    {
        value = std::numeric_limits<float>::quiet_NaN();
    }
    else if (!(iss >> value))
    {
        std::cerr << "Error: Invalid float literal" << std::endl;
        return;
    }

    // Display conversion results
    displayConversions(static_cast<double>(value));
}

void ScalarConverter::convertDouble(const std::string &literal)
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
*/