/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:34:13 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:42:34 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

// Constructor initializes name and sets weapon to nullptr
HumanB::HumanB(const std::string& name): name(name), weapon(nullptr) {}

// Set the weapon to the provided Weapon reference
void HumanB::setWeapon(Weapon& newWeapon)
{
    weapon = &newWeapon;
}

// Function to print attack message with name and weapon type
void HumanB::attack() const
{
    if (weapon)
	{
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
	else
	{
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}
