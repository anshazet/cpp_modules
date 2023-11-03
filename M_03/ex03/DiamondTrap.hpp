/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:31 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/23 15:03:48 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
    	std::string _name;

	public:
    	DiamondTrap(); // Default constructor
    	DiamondTrap(std::string name); // Parameterized constructor
    	~DiamondTrap(); // Destructor
    
    	DiamondTrap(const DiamondTrap &src); // Copy constructor
    	DiamondTrap &operator=(const DiamondTrap &rhs); // Copy assignment operator

    	void	whoAmI();
		void	attack(const std::string& target);

    	// Additional getters and setters if needed
    	std::string getName() const;
    	void setName(const std::string &name);
};

#endif
