/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:22:55 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:18:49 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie()
{
    // You might want to initialize _name with some default value
}

// Parameterized constructor
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << _name << " constructor are called" << std::endl;
}

// Destructor
Zombie::~Zombie()
{
    std::cout << _name << " is destroyed!" << std::endl;
}

// Announce method
void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Setter for name
void Zombie::setName(std::string name)
{
    _name = name;
}

/*
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << _name << " constructor are called" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " is destroyed!" << std::endl;
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
*/