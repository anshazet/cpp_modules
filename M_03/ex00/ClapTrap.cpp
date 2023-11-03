/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:39:52 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/12 10:37:17 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name (name), _hitPoints(10), _energyPoints(10), _attackDamage(2)
{
	std::cout << "ClapTrap " << _name << " is coming!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

/*
The parameter rhs is a reference to a constant ClapTrap object.
The const qualifier indicates that the function should not modify
the rhs object. rhs stands for "right-hand side", which is conventional
in the context of assignment operations, where the left-hand side (lhs)
is the object being assigned to, and the right-hand side (rhs) is the
object whose values are being copied.
*/

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	return;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& rhs )
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void	ClapTrap::attack(std::string const& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " cannot attack due to low energy or health" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage" << std::endl;
    _energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " cannot take more damage" << std::endl;
        return;
    }
    _hitPoints = (_hitPoints > amount) ? _hitPoints - amount : 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage" << std::endl;
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead..." << std::endl;
    }
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " cannot be repaired due to low energy" << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " recovering " << amount << " health points" << std::endl;
}

void	ClapTrap::displayStatus()
{
    std::cout << "ClapTrap Status: " << std::endl;
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Hit Points: " << _hitPoints << std::endl;
    std::cout << "Energy Points: " << _energyPoints << std::endl;
}

unsigned int	ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}
