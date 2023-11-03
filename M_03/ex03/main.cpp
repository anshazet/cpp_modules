/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:46:07 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/23 15:19:59 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // Creating a DiamondTrap object
    DiamondTrap dt1("DiamondBot");
    dt1.whoAmI();
    dt1.attack("target1");
    dt1.highFivesGuys();

    // Testing the copy constructor
    DiamondTrap dt2(dt1);
    dt2.whoAmI();
    dt2.attack("target2");

    // Testing the copy assignment operator
    DiamondTrap dt3;
    dt3 = dt2;
    dt3.whoAmI();
    dt3.attack("target3");

    // Testing other functionalities
    dt1.takeDamage(30);
    dt1.beRepaired(20);

    // Testing ScavTrap’s specific function
    dt1.guardGate();

    // Testing FragTrap’s specific function
    dt2.highFivesGuys();

    return 0;
}

