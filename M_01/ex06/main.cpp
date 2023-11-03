/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:15:56 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/10 08:25:09 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <map>
#include <cctype>  // for std::toupper

struct ToUpper
{
    char operator()(char ch) const
	{
        return std::toupper(static_cast<unsigned char>(ch));
    }
};

int main(int argc, char* argv[])
{
    if (argc != 2)
	{
        std::cerr << "Usage: " << argv[0] << " <LEVEL>" << std::endl;
        return 1;
    }

    Harl harl;
    std::string level(argv[1]);

    ToUpper toUpper;
    std::transform(level.begin(), level.end(), level.begin(), toUpper);

    std::map<std::string, int> levelMap;
    levelMap["DEBUG"] = 1;
    levelMap["INFO"] = 2;
    levelMap["WARNING"] = 3;
    levelMap["ERROR"] = 4;

    if (levelMap.find(level) == levelMap.end()) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }

    switch (levelMap[level]) {
        case 1:
            harl.complain("DEBUG");
        case 2:
            harl.complain("INFO");
        case 3:
            harl.complain("WARNING");
        case 4:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }

    return 0;
}

/*
Check for the correct number of command line arguments.
Convert the entered level to uppercase to allow case-insensitive comparison.
Create a map to associate string level names with integer values.
Check if the entered level is valid; if not, output a default message.
Use a switch statement to call the complain function with the appropriate levels based on the entered level.
*/