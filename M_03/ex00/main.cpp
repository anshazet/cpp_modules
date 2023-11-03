/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:39:29 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/12 10:52:02 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("Darth Vader");
    ClapTrap jedi("Jedi");

    std::cout << "\n--- Initial Status ---" << std::endl;
    clap.displayStatus();
    jedi.displayStatus();

    std::cout << "\n--- Darth Vader Attacking ---" << std::endl;
    clap.attack("Jedi");
    jedi.takeDamage(clap.getAttackDamage()); // Assuming you have a getter for _attackDamage
    jedi.displayStatus();
	clap.displayStatus();

    std::cout << "\n--- Jedi Taking Damage ---" << std::endl;
    jedi.takeDamage(3);
    jedi.displayStatus();

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

    return (EXIT_SUCCESS);
}


/*
int main(void)
{
    ClapTrap clap("Darth Vader");

	std::cout << "\n--- Initial Status ---" << std::endl;
	clap.displayStatus();

    std::cout << "\n--- Attacking ---" << std::endl;
    clap.attack("Jedi");
    clap.attack("Jedi");
	clap.displayStatus();

    std::cout << "\n--- Taking Damage ---" << std::endl;
    clap.takeDamage(3);
    clap.takeDamage(4);
    clap.takeDamage(5); // should output that ClapTrap is dead
	clap.displayStatus();

    std::cout << "\n--- Trying to Attack while Dead ---" << std::endl;
    clap.attack("Jedi"); // Since ClapTrap is "dead", it shouldn't be able to attack

    std::cout << "\n--- Being Repaired ---" << std::endl;
    clap.beRepaired(5); // Testing repair while having zero hit points
    clap.beRepaired(10); // Testing repair with enough hit points
	clap.displayStatus();

    std::cout << "\n--- Attacking Again ---" << std::endl;
    clap.attack("Jedi"); // Testing attack after being repaired
	clap.displayStatus();

    std::cout << "\n--- Taking Damage Again ---" << std::endl;
    clap.takeDamage(15); // Taking damage more than current hit points
	clap.displayStatus();

    std::cout << "\n--- Being Repaired Again ---" << std::endl;
    clap.beRepaired(5); // Trying to repair again after taking damage
	clap.displayStatus();
	
	std::cout << "\n--- Final Status ---" << std::endl;
	clap.displayStatus();

    return (EXIT_SUCCESS);
}
*/