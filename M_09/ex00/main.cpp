/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:45:30 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/10 09:48:00 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " <data.csv> <transactions.txt>" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.loadPriceData(argv[1]);
	exchange.processTransactions(argv[2]);

	return 0;
}
