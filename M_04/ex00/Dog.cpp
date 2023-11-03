/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:29 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/24 09:55:58 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "A dog is born!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "A dog has died!" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "A dog has been copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    Animal::operator=(rhs);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof, woof!" << std::endl;
}
