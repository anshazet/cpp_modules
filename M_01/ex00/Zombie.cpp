/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:06:27 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/27 14:23:00 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor to initialize the zombie with a name
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << _name << " constructor are called" << std::endl;
}

// Destructor for debugging purposes, prints a message when a zombie is destroyed
Zombie::~Zombie()
{
    std::cout << _name << " is destroyed!" << std::endl;
}

// Member function to make the zombie announce itself
void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}