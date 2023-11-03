/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:29 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/27 11:38:06 by ashalagi         ###   ########.fr       */
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

Dog::Dog(const Dog &src) : AAnimal(src)
{
    brain = new Brain(*src.brain);
    std::cout << "A dog has been copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    std::cout << "Dog assignment operator called!" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "\033[1;36mWoof, woof!\033[0m" << std::endl;
}
