/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:54:33 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/20 16:54:53 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default Constructor
// Initializes the ScavTrap with predefined values if no arguments are passed.
ScavTrap::ScavTrap() : ClapTrap("Default_Scav")
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "Default ScavTrap is ready!" << std::endl;
}

// Parameterized Constructor
// Initializes the ScavTrap with the provided name and predefined attributes.
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " is coming!" << std::endl;
}

// Destructor
// Cleans up the ScavTrap object when it goes out of scope or is deleted.
ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

// Copy Constructor
// Initializes a new ScavTrap as a copy of an existing one.
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Assignment Operator
// Allows assigning the values of one ScavTrap to another.
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if (this == &rhs) // prevent self-assignment
        return *this;

    ClapTrap::operator=(rhs); // call the base class's assignment operator
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}

unsigned int ScavTrap::getHitPoints() const
{
    return _hitPoints;
}

void ScavTrap::setHitPoints(unsigned int hitPoints)
{
    _hitPoints = hitPoints;
}

unsigned int ScavTrap::getEnergyPoints() const
{
    return _energyPoints;
}

void ScavTrap::setEnergyPoints(unsigned int energyPoints)
{
    _energyPoints = energyPoints;
}

unsigned int ScavTrap::getAttackDamage() const
{
    return _attackDamage;
}

void ScavTrap::setAttackDamage(unsigned int attackDamage)
{
    _attackDamage = attackDamage;
}

std::string ScavTrap::getName() const
{
    return _name;
}
