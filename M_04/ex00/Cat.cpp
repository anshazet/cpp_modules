/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:21 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/24 09:57:18 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "A cat is born!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "A cat has died!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "A cat has been copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    Animal::operator=(rhs);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow, meow!" << std::endl;
}
