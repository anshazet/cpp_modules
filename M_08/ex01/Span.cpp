/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:41:28 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/06 16:09:00 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>

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

void Span::addNumber(int number)
{
	if (numbers.size() >= max_size)
	{
		throw std::length_error("Span is full");
	}
	numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to find a span");
	}
	// Compute shortest span
	// ...
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to find a span");
	}
	// Compute longest span
	// ...
}

// Optional: Implement addNumber for range of iterators
// ...
