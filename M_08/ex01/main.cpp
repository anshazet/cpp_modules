/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:41:00 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/06 16:03:27 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// More tests, especially with large Span and many numbers
	// ...

	return 0;
}
