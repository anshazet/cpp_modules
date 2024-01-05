/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 07:01:44 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 07:02:37 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./convert [literal]" << std::endl;
        return 1;
    }

    std::string literal = av[1];
    ScalarConverter::convert(literal);

    return 0;
}
