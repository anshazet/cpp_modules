/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:11:01 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/24 10:32:40 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "An animal is born!" << std::endl;
}

Animal::~Animal()
{
    std::cout << "An animal has died!" << std::endl;
}

Animal::Animal(const Animal &src)
{
    *this = src;
    std::cout << "An animal has been copied!" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
	{
        type = rhs.type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "An animal make sound piu piu! " << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
