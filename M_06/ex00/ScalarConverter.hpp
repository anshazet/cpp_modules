/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:35:46 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 06:51:21 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:
    // The convert method is static, as it does not depend on any instance of ScalarConverter.
    static void convert(const std::string &literal);

private:
    // Private constructor and assignment operator to prevent instantiation.
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);

    // Helper methods for conversion and output.
    static void convertChar(const std::string &literal);
    static void convertInt(const std::string &literal);
    static void convertFloat(const std::string &literal);
    static void convertDouble(const std::string &literal);

    // Additional helper methods.
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);
    static bool isPrintable(char c);
    static void handleSpecialCases(double value, const std::string &type);
};

#endif // SCALARCONVERTER_HPP
