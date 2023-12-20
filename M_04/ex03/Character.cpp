/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:47:15 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 11:19:41 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

// Constructor
Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; ++i)
    {
        inventory[i] = NULL;
    }
}


// Copy constructor
Character::Character(const Character &src) : name(src.name)
{
    for (int i = 0; i < 4; ++i)
    {
        inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : NULL;
    }
}

// Copy assignment operator
Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

// Destructor
Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        delete inventory[i];
    }
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        inventory[idx] = NULL; // Just set to NULL, do not delete the materia
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
    {
        inventory[idx]->use(target);
    }
}