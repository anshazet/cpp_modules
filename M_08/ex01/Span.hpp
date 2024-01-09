/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:41:16 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/09 14:30:00 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
private:
    std::vector<int> numbers; //container
    unsigned int max_size;


public:
    Span(unsigned int N);
	Span(const Span& other);
	Span &operator=(const Span& other);
	~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

/*
This template method is designed to add multiple numbers
from any iterable container. It iterates over the range
defined by begin and end, adding each element to the
Span's internal container.
*/
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            addNumber(*begin);
            ++begin;
        }
    }

};

#endif