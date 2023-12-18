/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:52:06 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/18 13:57:05 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

	ClapTrap ();

public:
	ClapTrap(std::string name);
	virtual ~ClapTrap(); // Declare the destructor as virtual

	ClapTrap(const ClapTrap &);
    virtual ClapTrap &operator=(const ClapTrap& rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void displayStatus();
	unsigned int getAttackDamage() const;
};

#endif

/*
declaring the destructor as virtual in the ClapTrap class, could be beneficial
for ensuring that the derived class destructors (FragTrap and ScavTrap) are
calledcorrectly when an object of a derived class is deleted through a pointer
of the base class type.

Declaring the destructor as virtual ensures that when a derived class object
goes out of scope or is explicitly deleted, the destructors of both the derived
and base classes are invoked in the correct order, ensuring that all resources
are released properly.


*/