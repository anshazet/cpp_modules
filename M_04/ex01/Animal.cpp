/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:11:01 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/25 09:05:29 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "\033[1;34m[Animal Constructor] An animal is born!\033[0m" << std::endl;
}

Animal::~Animal()
{
    std::cout << "\033[1;34m[Animal Destructor] An animal has died!\033[0m" << std::endl;
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
