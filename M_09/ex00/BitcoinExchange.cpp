/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:45:01 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/10 12:38:30 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Default Constructor
BitcoinExchange::BitcoinExchange() {}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
    : priceData(other.priceData) {}

// Copy Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
	{
        priceData = other.priceData;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadPriceData(const std::string &filename)
{
    // Open the file using the provided filename.
    std::ifstream file(filename.c_str());

    // Declare variables to hold each line read from the file, the date, and the price.
    std::string line, date;
    float price;

    // Read the file line by line.
    while (std::getline(file, line))
    {
        // Create a string stream from the line for easy parsing.
        std::istringstream iss(line);

        // Extract the date and price from the line.
        // The date and price are expected to be separated by a comma.
        // 'std::getline(iss, date, ',')' reads the string stream until the comma
        // and stores the result in the 'date' variable.
        // '(iss >> price)' attempts to read the next part of the stream as a float.
        if (std::getline(iss, date, ',') && (iss >> price))
        {
            // If both the date and price are successfully read, store them in the priceData map.
            // The date is used as the key, and the price is the associated value.
            priceData[date] = price;
        }
        // If the line is not properly formatted (doesn't contain a date and a price),
        // the loop continues to the next line.
    }
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	// Search for the lower bound of the given date in the priceData map.
    // lower_bound returns an iterator pointing to the first element that is not less than 'date'.
    // If 'date' is found, it points to the element with 'date';
    // if 'date' is not found, it points to the next element.
    std::map<std::string, float>::const_iterator it = priceData.lower_bound(date);
	// Check if the iterator points to the end of the map or to a different date than the one requested.
    // If so, this means the exact date was not found in the map.
    if (it != priceData.begin() && (it == priceData.end() || it->first != date))
	{
        // Since the exact date is not found, move the iterator back to get the closest previous date.
        // This finds the rate of the most recent date before the requested date.
		--it; // Move to the previous date if the exact date is not found
	}
    // Return the price associated with the found date.
    // If the exact date was found, it returns the price of that date;
    // if not, it returns the price of the closest previous date.
	return it->second;
}

void BitcoinExchange::processTransactions(const std::string &filename) const
{
    // Attempt to open the file containing transaction data.
    std::ifstream file(filename.c_str());

    // Check if the file was successfully opened.
    if (!file)
    {
        // If the file could not be opened, print an error message and exit the function.
        std::cerr << "Error: could not open file " << filename << "." << std::endl;
        return;
    }

    std::string line, date;
    float value;

    // Read the file line by line.
    while (std::getline(file, line))
    {
        // Replace all '|' characters in the line with whitespace.
        // This is necessary to correctly parse the line into a date and a value.
        std::replace(line.begin(), line.end(), '|', ' ');

        // Create a string stream from the line for easy parsing.
        std::istringstream iss(line);

        // Attempt to parse the date and value from the line.
        // The expected format is "date value", with a space between them.
        if (!(std::getline(iss, date, ' ') && (iss >> value)))
        {
            // If the line is not in the correct format, print an error message and continue to the next line.
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Check if the parsed value is a valid positive number.
        if (value < 0)
        {
            // If the value is negative, print an error message and continue to the next line.
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        // Check if the parsed value is within the acceptable range (not too large).
        if (value > 1000)
        {
            // If the value is larger than 1000, print an error message and continue to the next line.
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        try
        {
            // Retrieve the exchange rate for the given date.
            float rate = getExchangeRate(date);
            // Print the date, original value, and calculated result (value multiplied by the rate).
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        catch (const std::exception &e)
        {
            // Catch and print any exceptions that occur during the retrieval of the exchange rate.
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

/*
Functionality: loadPriceData reads a CSV file where each line contains a date
and a price, separated by a comma.
Data Storage: The extracted date and price are stored in a std::map named priceData,
with dates as keys and prices as values.
Error Handling: The function does not include explicit error handling for malformed
lines or file opening errors. Depending on the requirements, you may want to add
such handling to make the function more robust.

Functionality: getExchangeRate retrieves the exchange rate for a given date.
If the exact date isn't available, it finds the closest date before the given date.
Search Mechanism: It uses std::map::lower_bound to efficiently search for the given
date or the next closest date in the priceData map.
Iterator Adjustment: If the exact date isn't found, the iterator is decremented to
point to the closest date before the given date.
Return Value: The function returns the exchange rate associated with the date found
by the iterator.

*/