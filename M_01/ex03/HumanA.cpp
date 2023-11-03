/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:34:23 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:41:40 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

// Constructor that initializes name and weapon with provided arguments
HumanA::HumanA(const std::string& name, Weapon& weapon): name(name), weapon(weapon) {}

// Function to print attack message with name and weapon type
void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
