/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:37:40 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/10 08:13:09 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>  // for std::toupper

/*
operator() method that takes a char and returns its
uppercase equivalent using std::toupper.
*/
struct ToUpper
{
    char operator()(char ch) const
	{
        return std::toupper(static_cast<unsigned char>(ch));
    }
};

int main()
{
    Harl harl;
    std::string level;

    ToUpper toUpper;  // Function object to convert char to uppercase

    do
	{
        std::cout << "Enter a level: ";
        std::getline(std::cin, level);

		// When calling std::transform, an instance pass of the ToUpper struct (toUpper) as the
		// fourth argument. std::transform uses this functor to convert each character in level to uppercase.
        // Convert input to uppercase using std::transform and the ToUpper function object
        std::transform(level.begin(), level.end(), level.begin(), toUpper);

        // Check for non-empty input to avoid unnecessary output on exit
        if (!level.empty())
            harl.complain(level);

    } while (!level.empty());  // Exit loop on empty input

    return 0;
}


/*
int main()
{
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("INVALID_LEVEL"); // Testing invalid level
    return 0;
}
*/