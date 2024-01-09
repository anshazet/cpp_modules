/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:41:28 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/09 14:32:04 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

/*
The constructor initializes the container with a maximum size.
However, it doesn't allocate space for the elements upfront;
it just sets a limit on how many elements can be added.
*/
Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
	{
        numbers = other.numbers;
        max_size = other.max_size;
    }
    return *this;
}

Span::~Span() {}

/*
This method adds a single integer to the container. Before adding,
it checks whether there is enough space left in the container.
*/
void Span::addNumber(int number)
{
    if (numbers.size() >= max_size)
    {
        throw std::length_error("Span is already full");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
    {
        throw std::length_error("Not enough elements in Span");
    }

    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());

    int min_span = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < min_span)
        {
            min_span = span;
        }
    }

    return min_span;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
    {
        throw std::length_error("Not enough elements in Span");
    }

    int min_elem = *std::min_element(numbers.begin(), numbers.end());
    int max_elem = *std::max_element(numbers.begin(), numbers.end());

    return max_elem - min_elem;
}

/*
shortestSpan() and longestSpan()
These methods compute the shortest and longest spans (differences)
between the elements in the container. They work with the data
stored in the container to calculate these values.

For shortestSpan(), a copy of the container is sorted to find the
minimum difference between consecutive elements:

For longestSpan(), the method finds the maximum and minimum
elements in the container:
*/