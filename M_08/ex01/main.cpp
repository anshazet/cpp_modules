/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:41:00 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/10 08:37:37 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "Span.hpp"
#include <iostream>

int main()
{
    try
    {
        Span sp = Span(5); //creates an instance of the Span class named sp with a maximum capacity of 5 integers

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        /*
        Example of adding a range of numbers
        std::vector<int> named moreNumbers is created and filled with 10,000 integers,
        each being double its index (0, 2, 4, ..., 19998).
        */
        std::vector<int> moreNumbers;
        // Fill moreNumbers with some numbers
        for (int i = 0; i < 10000; ++i)
        {
            moreNumbers.push_back(i * 2);
        }

        Span largeSpan(10000);
        largeSpan.addNumber(moreNumbers.begin(), moreNumbers.end());

        std::cout << "Shortest Span of largeSpan: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span of largeSpan: " << largeSpan.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
/*
shortest and longest spans between the numbers added to sp. The shortest span
is the smallest difference between any two numbers, and the longest span
is the difference between the minimum and maximum numbers in the Span.

First Span (sp):

Shortest Span: 2 (This is the smallest difference between any two of
the numbers 6, 3, 17, 9, 11. In this case, between 9 and 11.)
Longest Span: 14 (This is the difference between the smallest and largest
numbers in the set: 3 and 17.)
Second Span (largeSpan):

Shortest Span of largeSpan: 2 (This is the smallest difference in your
sequence 0, 2, 4, ..., 19998, which is consistently 2 between any two
consecutive numbers.)
Longest Span of largeSpan: 19998 (This is the difference between
the smallest (0) and largest (19998) numbers in the set.)
*/
/*
#include "Span.hpp"
#include <iostream>

int main()
{
    try
    {
        Span sp(3); // Reduced size for testing

        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);

        // Attempting to add more numbers than max_size
        std::cout << "Attempting to add another number beyond max_size:" << std::endl;
        sp.addNumber(20); // Should throw an exception
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Span spSingleElement(1);
        spSingleElement.addNumber(5);

        // Attempting to find spans with only one element
        std::cout << "Attempting to find spans with only one element:" << std::endl;
        std::cout << "Shortest Span: " << spSingleElement.shortestSpan() << std::endl; // Should throw an exception
        std::cout << "Longest Span: " << spSingleElement.longestSpan() << std::endl;   // Should throw an exception
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Span spEmpty(10);

        // Attempting to find spans with no elements
        std::cout << "Attempting to find spans with no elements:" << std::endl;
        std::cout << "Shortest Span: " << spEmpty.shortestSpan() << std::endl; // Should throw an exception
        std::cout << "Longest Span: " << spEmpty.longestSpan() << std::endl;   // Should throw an exception
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
*/

/*
First, we create a Span with a small size (3) and try to add a fourth number.
This should trigger an exception since we're exceeding the max_size.
Next, we create a Span with one element and attempt to find the shortest and
longest spans. This should also trigger an exception as we need at least two
elements to find a span.
Finally, we test with an empty Span where no elements are added, and we attempt
to find spans. This will also result in an exception.
These tests will help ensure that your Span class correctly handles scenarios
where operations are performed outside of its defined constraints. It's good
practice to include such edge case tests to validate the reliability and
correctness of your code.
*/