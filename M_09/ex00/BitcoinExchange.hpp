/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:45:16 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/10 09:26:20 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange &operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	
	void loadPriceData(const std::string &filename);
	float getExchangeRate(const std::string &date) const;
	void processTransactions(const std::string &filename) const;

private:
	std::map<std::string, float> priceData; // Using std::map to store date and price
};

#endif // BITCOINEXCHANGE_HPP

/*
BitcoinExchange class handles the loading of price data and processing of transaction files.
Price data is loaded into a std::map, where keys are dates and values are prices.
processTransactions reads the transaction file, retrieves the relevant exchange rate for
each transaction, and calculates the value.
*/
