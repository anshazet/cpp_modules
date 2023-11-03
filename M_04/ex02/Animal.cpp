/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:11:01 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/27 11:00:23 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : type("Animal")
{
    std::cout << "\033[1;34m[Animal Constructor] An animal is born!\033[0m" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "\033[1;34m[Animal Destructor] An animal has died!\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
    *this = src;
    std::cout << "An animal has been copied!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
    if (this != &rhs)
	{
        type = rhs.type;
    }
    return *this;
}

/*
it won’t be callable, but it will be there as a default implementation
if a derived class doesn’t provide its own.
*/
void AAnimal::makeSound() const
{
    std::cout << "An animal make sound piu piu! " << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}
