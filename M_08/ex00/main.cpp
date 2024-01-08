/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:51:46 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/06 15:29:06 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
	// Test with vector
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i);

	// Test with list
	std::list<int> lst;
	for (int i = 20; i < 30; ++i)
		lst.push_back(i);

	// Test with deque
	std::deque<int> deq;
	for (int i = 40; i < 50; ++i)
		deq.push_back(i);

	// Testing with vector
	try
	{
		int found = easyfind(vec, 5);
		std::cout << "Vector Test - Found: " << found << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector Test - Not found!" << std::endl;
	}
	try
	{
		int found = easyfind(vec, 11);
		std::cout << "Vector Test - Found: " << found << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector Test - Not found!" << std::endl;
	}

	// Testing with list
	try
	{
		int found = easyfind(lst, 25);
		std::cout << "List Test - Found: " << found << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "List Test - Not found!" << std::endl;
	}
	try
	{
		int found = easyfind(lst, -1);
		std::cout << "List Test - Found: " << found << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "List Test - Not found!" << std::endl;
	}

	// Testing with deque
	try
	{
		int found = easyfind(deq, 45);
		std::cout << "Deque Test - Found: " << found << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Deque Test - Not found!" << std::endl;
	}
	try
	{
		int found = easyfind(deq, 100);
		std::cout << "Deque Test - Found: " << found << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Deque Test - Not found!" << std::endl;
	}

	return 0;
}
