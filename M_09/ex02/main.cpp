/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:16:51 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/16 13:46:06 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <list of positive integers>" << std::endl;
		return 1;
	}
	std::vector<int> data;
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		if (num < 0)
		{
			std::cerr << "Error: Negative numbers are not allowed." << std::endl;
			return 1;
		}
		data.push_back(num);
	}

	std::cout << std::endl;
	std::cout << "Before: ";
	size_t i = 0;
	while (i < data.size())
		std::cout << data[i++] << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::vector<int> data_copy = data;
	PmergeMe pmergeme;

	clock_t start = clock();
	pmergeme.mergeInsertSort(data);
	clock_t end = clock();
	double duration = static_cast<double>(end - start);

	std::cout << "After: ";
	i = 0;
	while (i < data.size())
		std::cout << data[i++] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Time to process with mergeInsertSort: " << duration << " us" << std::endl;

	start = clock();
	std::list<int> dataList(data_copy.begin(), data_copy.end());
	dataList.sort();
	data_copy.assign(dataList.begin(), dataList.end());
	end = clock();
	duration = static_cast<double>(end - start);

	std::cout << "Time to process with std::list:  " << duration << " us" << std::endl;

	return (0);
}