/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:55:54 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/23 12:00:41 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

// Default Constructor
FragTrap::FragTrap() : ClapTrap("Default_Frag")
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "Default FragTrap is ready!" << std::endl;
}

// Parameterized Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " is coming!" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " destructor called" << std::endl;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    if (this == &rhs) // prevent self-assignment
        return *this;

    ClapTrap::operator=(rhs); // call the base class's assignment operator
    std::cout << "FragTrap assignment operator called" << std::endl;
    return *this;
}

// Special Capacity
void FragTrap::highFivesGuys() const
{
    std::cout << "FragTrap " << getName() << " is requesting high fives!" << std::endl;
}

unsigned int FragTrap::getHitPoints() const
{
    return _hitPoints;
}

void FragTrap::setHitPoints(unsigned int hitPoints)
{
    _hitPoints = hitPoints;
}

unsigned int FragTrap::getEnergyPoints() const
{
    return _energyPoints;
}

void FragTrap::setEnergyPoints(unsigned int energyPoints)
{
    _energyPoints = energyPoints;
}

unsigned int FragTrap::getAttackDamage() const
{
    return _attackDamage;
}

void FragTrap::setAttackDamage(unsigned int attackDamage)
{
    _attackDamage = attackDamage;
}

std::string FragTrap::getName() const
{
    return _name;
}
