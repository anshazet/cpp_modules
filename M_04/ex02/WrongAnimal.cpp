/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:04:04 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/24 11:05:25 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "A wrong animal is born!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "A wrong animal has died!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    *this = src;
    std::cout << "A wrong animal has been copied!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if (this != &rhs)
	{
        type = rhs.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some sound of wrong animal grrr grrr" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}