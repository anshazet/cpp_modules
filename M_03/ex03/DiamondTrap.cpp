/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:42 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/23 15:59:06 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), _name(name)
{
    this->ScavTrap::_name = name + "_clap_name";
    this->FragTrap::setHitPoints(FragTrap::getHitPoints());
    this->ScavTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
    this->FragTrap::setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap " << _name << " is born!" << std::endl;
}

// For the attack function, you may want to use ScavTrap’s implementation
void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}


// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " is destroyed!" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ScavTrap(src), FragTrap(src)
{
    *this = src;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    if (this != &rhs)
	{
        this->_name = rhs._name;
        this->ScavTrap::operator=(rhs);
        this->FragTrap::operator=(rhs);
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap Name: " << _name << std::endl;
    std::cout << "ClapTrap Name: " << this->ScavTrap::_name << std::endl;
}

// Additional getters and setters
std::string DiamondTrap::getName() const
{
    return _name;
}

void DiamondTrap::setName(const std::string &name)
{
    this->_name = name;
}

