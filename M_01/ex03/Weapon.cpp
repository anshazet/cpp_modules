/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:34:31 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:41:05 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor that initializes type with the provided argument
Weapon::Weapon(const std::string& type): type(type) {}

// Getter for type; returns a const reference to type
const std::string& Weapon::getType() const
{
    return type;
}

// Setter for type; assigns a new value to type
void Weapon::setType(const std::string& newType)
{
    type = newType;
}
