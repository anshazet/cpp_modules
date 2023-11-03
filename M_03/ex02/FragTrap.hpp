/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:56:09 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/20 17:05:34 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
    	FragTrap();
    	FragTrap(std::string name);
    	~FragTrap();
    
    	FragTrap(const FragTrap &);
    	FragTrap &operator=(const FragTrap& rhs);

    	void highFivesGuys() const;

	    unsigned int    getHitPoints() const;
        void            setHitPoints(unsigned int hitPoints);
        unsigned int    getEnergyPoints() const;
        void            setEnergyPoints(unsigned int energyPoints);
        unsigned int    getAttackDamage() const;
        void            setAttackDamage(unsigned int attackDamage);
		std::string getName() const;
};

#endif
