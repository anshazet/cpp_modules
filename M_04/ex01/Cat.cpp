/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:21 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/25 09:34:33 by ashalagi         ###   ########.fr       */
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
    brain = new Brain(*src.brain);
    std::cout << "A cat has been copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    std::cout << "Cat assignment operator called!" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "\033[1;35mMeow, meow!\033[0" << std::endl;
}
