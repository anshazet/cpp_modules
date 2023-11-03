/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:39:29 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/19 12:48:47 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clap("Darth Vader");
    ClapTrap jedi("Jedi");
    ScavTrap scav("GuardBot"); // Create a ScavTrap

    std::cout << "\n--- Initial Status ---" << std::endl;
    clap.displayStatus();
    std::cout << std::endl;
    jedi.displayStatus();
    std::cout << std::endl;
    scav.displayStatus();

    std::cout << "\n--- Darth Vader Attacking ---" << std::endl;
    clap.attack("GuardBot");
//    scav.takeDamage(clap.getAttackDamage()); //  a getter for _attackDamage
//    scav.displayStatus();
    scav.takeDamage(5); //  a getter for _attackDamage
    scav.displayStatus();
	clap.displayStatus();

    std::cout << "\n--- GuardBot Taking Damage ---" << std::endl;
    scav.takeDamage(3);
    scav.displayStatus();

    std::cout << "\n--- GuardBot Attacking ---" << std::endl;
    scav.attack("Darth Vader");
    clap.takeDamage(clap.getAttackDamage()); // Assuming you have a getter for _attackDamage
    scav.displayStatus();
	clap.displayStatus();


    std::cout << "\n--- Jedi Being Repaired ---" << std::endl;
    jedi.beRepaired(5);
    jedi.displayStatus();

    std::cout << "\n--- Jedi Attacking Back ---" << std::endl;
    jedi.attack("Darth Vader");
    clap.takeDamage(jedi.getAttackDamage());
    clap.displayStatus();

	std::cout << "\n--- Darth Vader Taking Damage ---" << std::endl;
    clap.takeDamage(8);
    clap.displayStatus();

	std::cout << "\n--- Trying to Attack while Dead ---" << std::endl;
    clap.attack("Jedi"); // Since ClapTrap is "dead", it shouldn't be able to attack

    std::cout << "\n--- Final Status ---" << std::endl;
    clap.displayStatus();
    jedi.displayStatus();

    std::cout << "\n--- ScavTrap Guarding Gate ---" << std::endl;
    scav.guardGate();

    return (EXIT_SUCCESS);
}
