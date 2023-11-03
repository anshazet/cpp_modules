/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:53:28 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/20 16:15:55 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
	    ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();

	    ScavTrap(const ScavTrap &);
        ScavTrap &operator=(const ScavTrap& rhs);

        void guardGate();
    
        // Forward declarations for functions to access private attributes
        unsigned int    getHitPoints() const;
        void            setHitPoints(unsigned int hitPoints);
        unsigned int    getEnergyPoints() const;
        void            setEnergyPoints(unsigned int energyPoints);
        unsigned int    getAttackDamage() const;
        void            setAttackDamage(unsigned int attackDamage);
        std::string getName() const;
};

#endif
