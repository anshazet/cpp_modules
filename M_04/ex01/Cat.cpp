/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:21 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 12:45:24 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "\033[1;35m[Cat Constructor] A cat is born!\033[0m" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "\033[1;35m[Cat Destructor] A cat has died!\033[0m" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    brain = new Brain(*src.brain);      // Deep copy: creating a new Brain object
    std::cout << "A cat has been copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        delete brain;                   // First, delete the existing brain
        brain = new Brain(*rhs.brain);  // Then, create a new Brain object (deep copy)
    }
    std::cout << "Cat assignment operator called!" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "\033[1;35mMeow, meow!\033[0" << std::endl;
}

/*
Deep copy is a concept in programming where an object is copied along
with all the objects to which it refers. This is in contrast to a shallow
copy, where only the object itself is copied, but its references
(like pointers) still point to the same objects as the original.
Deep copying is important in C++ when dealing with objects that manage
resources, like memory or file handles, to prevent issues like double
free errors or memory leaks.
*/