/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:35:42 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/04 09:30:45 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

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

void ScalarConverter::convertInt(const std::string &literal)
{
    // Implementation for int conversion
    // ...
}

void ScalarConverter::convertFloat(const std::string &literal)
{
    // Implementation for float conversion
    // ...
}

void ScalarConverter::convertDouble(const std::string &literal)
{
    // Implementation for double conversion
    // ...
}


bool ScalarConverter::isPrintable(char c)
{
    return std::isprint(static_cast<unsigned char>(c));
}

// Define isChar, isInt, isFloat, isDouble, isPrintable, etc.
// ...

// Additional helper methods implementation
// ...
