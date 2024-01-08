/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:41:16 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/06 16:06:26 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
private:
    std::vector<int> numbers;
    unsigned int max_size;


public:
    Span(unsigned int N);
	Span(const Span& other);
	Span &operator=(const Span& other);
	~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

};

#endif