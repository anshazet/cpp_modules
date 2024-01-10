/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:45:01 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/10 09:37:49 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

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
	std::ifstream file(filename.c_str());
	std::string line, date;
	float price;

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, ',') && (iss >> price))
		{
			priceData[date] = price;
		}
	}
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = priceData.lower_bound(date);
	if (it != priceData.begin() && (it == priceData.end() || it->first != date))
	{
		--it; // Move to the previous date if the exact date is not found
	}
	return it->second;
}

void BitcoinExchange::processTransactions(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	std::string line, date;
	float value;

	while (std::getline(file, line))
	{
		std::replace(line.begin(), line.end(), '|', ' '); // Replace '|' with whitespace
		std::istringstream iss(line);
		if (std::getline(iss, date, ' ') && (iss >> value))
		{
			float rate = getExchangeRate(date);
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		}
	}
}
