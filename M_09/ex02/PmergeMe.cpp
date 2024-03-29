/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 07:23:05 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/16 12:10:03 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & /* other */) {}

PmergeMe &PmergeMe::operator=(const PmergeMe & /* other */)
{
	return *this;
}

PmergeMe::~PmergeMe() {}

void    PmergeMe::mergeInsertSort(std::vector<int> &vector)
{
    if (vector.size() <= 1)
    {
        return ;
    }

    size_t  middle = vector.size() / 2; //Dividing the Vector
    std::vector<int>    left(vector.begin(), vector.begin() + middle);
    std::vector<int>    right(vector.begin() + middle, vector.end());
    mergeInsertSort(left);
    mergeInsertSort(right);
	//After the recursive calls return (i.e., when the smaller vectors are sorted),
	//the two sorted halves (left and right) are merged back together into the original
	//vector. The std::merge function from the C++ Standard Library is used here.
	//It takes the beginning and end iterators of both sorted halves and merges these
	//ranges into the range starting at vector.begin(). The result is that the original
	//vector now contains a fully sorted sequence of its elements.
    std::merge(left.begin(), left.end(), right.begin(), right.end(), vector.begin());
}
