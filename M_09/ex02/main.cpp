/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:16:51 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/11 08:20:43 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib> // For atoi
#include <chrono>  // For timing

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <list of positive integers>" << std::endl;
		return 1;
	}

	std::vector<int> numbersVector;
	std::list<int> numbersList;
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		if (num < 0)
		{
			std::cerr << "Error: Negative numbers are not allowed." << std::endl;
			return 1;
		}
		numbersVector.push_back(num);
		numbersList.push_back(num);
	}

	PmergeMe sorter;

	// Sort using vector
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::string sortedVector = sorter.sortWithVector(numbersVector);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vectorDuration = end - start;

	// Sort using list
	start = std::chrono::high_resolution_clock::now();
	std::string sortedList = sorter.sortWithList(numbersList);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> listDuration = end - start;

	// Output results
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = numbersVector.begin(); it != numbersVector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "After (Vector): " << sortedVector << std::endl;
	std::cout << "After (List): " << sortedList << std::endl;

	std::cout << "Time to process with std::vector: " << vectorDuration.count() << " us" << std::endl;
	std::cout << "Time to process with std::list: " << listDuration.count() << " us" << std::endl;

	return 0;
}
