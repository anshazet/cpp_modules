/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:35:42 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/04 15:05:27 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <sstream>
#include <cctype>

ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	// Detect and convert the type
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
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;

	// Convert to double
	std::cout << "double: " << static_cast<double>(c) << std::endl;
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
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

	// Convert to double
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal)
{
	// Convert the literal to a float
	std::istringstream iss(literal);
	float value;
	if (!(iss >> value))
	{
		std::cerr << "Error: Invalid float literal" << std::endl;
		return;
	}

	// Check for special float values (nan, inf)
	if (std::isnan(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << std::endl;
		std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << std::endl;
		return;
	}

	// Convert to char
	std::cout << "char: ";
	if (isPrintable(static_cast<char>(value)))
	{
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}

	// Convert to int
	std::cout << "int: " << static_cast<int>(value) << std::endl;

	// Print as float
	std::cout << "float: " << value << "f" << std::endl;

	// Convert to double
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertDouble(const std::string &literal)
{
	// Convert the literal to a double
	std::istringstream iss(literal);
	double value;
	if (!(iss >> value))
	{
		std::cerr << "Error: Invalid double literal" << std::endl;
		return;
	}

	// Check for special double values (nan, inf)
	if (std::isnan(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << std::endl;
		std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << std::endl;
		return;
	}

	// Convert to char
	std::cout << "char: ";
	char charValue = static_cast<char>(value);
	if (ScalarConverter::isPrintable(charValue))
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

	// Convert to float
	std::cout << "float: ";
	float floatValue = static_cast<float>(value);
	if (std::isinf(floatValue) || std::isnan(floatValue))
	{
		std::cout << (std::isinf(floatValue) ? (floatValue < 0 ? "-inff" : "+inff") : "nanf") << std::endl;
	}
	else
	{
		std::cout << floatValue << "f" << std::endl;
	}

	// Print as double
	std::cout << "double: " << value << std::endl;
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
    std::istringstream iss(literal);
    float value;
    char leftover;
    if ((iss >> value) && !(iss >> leftover))
	{
        // Check if the last character is 'f' or 'F'
        return literal.find('.') != std::string::npos && 
               (literal.back() == 'f' || literal.back() == 'F');
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    std::istringstream iss(literal);
    double value;
    char leftover;
    if ((iss >> value) && !(iss >> leftover))
	{
        // Successfully read a double and no leftover characters
        return literal.find('.') != std::string::npos;
    }
    return false;
}

/*
#include <stdexcept> // Include for std::invalid_argument

bool ScalarConverter::isInt(const std::string &literal)
{
    std::istringstream iss(literal);
    int value;
    char leftover;
    if ((iss >> value) && !(iss >> leftover)) {
        return true;
    }
    throw std::invalid_argument("Invalid integer literal: " + literal);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    std::istringstream iss(literal);
    float value;
    char leftover;
    if ((iss >> value) && !(iss >> leftover) && literal.find('.') != std::string::npos && 
        (literal.back() == 'f' || literal.back() == 'F')) {
        return true;
    }
    throw std::invalid_argument("Invalid float literal: " + literal);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    std::istringstream iss(literal);
    double value;
    char leftover;
    if ((iss >> value) && !(iss >> leftover) && literal.find('.') != std::string::npos) {
        return true;
    }
    throw std::invalid_argument("Invalid double literal: " + literal);
}


*/