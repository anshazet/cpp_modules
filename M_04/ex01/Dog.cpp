/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:29 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 12:44:18 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "\033[1;36m[Dog Constructor] A dog is born!\033[0m" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "\033[1;36m[Dog Destructor] A dog has died!\033[0m" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    brain = new Brain(*src.brain);      // Deep copy: creating a new Brain object
    std::cout << "A dog has been copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        delete brain;                   // First, delete the existing brain
        brain = new Brain(*rhs.brain);  // Then, create a new Brain object (deep copy)
    }
    std::cout << "Dog assignment operator called!" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "\033[1;36mWoof, woof!\033[0m" << std::endl;
}
