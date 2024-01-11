/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 07:23:05 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/11 08:24:33 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>  // For std::sort

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & /* other */) {}

PmergeMe &PmergeMe::operator=(const PmergeMe & /* other */)
{
	return *this;
}

PmergeMe::~PmergeMe() {}

std::string PmergeMe::sortWithVector(const std::vector<int> &numbers) const
{
	std::vector<int> sorted = numbers;		 // Copy numbers to a new vector
	std::sort(sorted.begin(), sorted.end()); // Simple sort for demonstration

	std::stringstream ss;
	for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.end(); ++it)
	{
		ss << *it << " ";
	}
	return ss.str();
}

std::string PmergeMe::sortWithList(const std::list<int> &numbers) const
{
	std::list<int> sorted = numbers; // Copy numbers to a new list
	sorted.sort();					 // Using std::list's sort method

	std::stringstream ss;
	for (std::list<int>::const_iterator it = sorted.begin(); it != sorted.end(); ++it)
	{
		ss << *it << " ";
	}
	return ss.str();
}
