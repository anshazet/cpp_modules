/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:39:58 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/20 15:51:09 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		ClapTrap ();

	public:
		ClapTrap(std::string name); //constructor to instantiate a ClapTrap object with a specific name and initializes other attributes.
		~ClapTrap();

		ClapTrap(const ClapTrap &); //Copy Constructor
    	ClapTrap &operator=(const ClapTrap& rhs); //Assignment Operator

		/* These are used for copying objects. The copy constructor is used when an object
		is initialized using another object, and the assignment operator is used when
		an already initialized object is assigned the values of another object.
		*/

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		displayStatus();
		unsigned int getAttackDamage() const;
};

#endif