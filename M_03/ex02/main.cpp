/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:59:55 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/20 17:10:52 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clap("Darth Vader");
    ClapTrap jedi("Jedi");
    ScavTrap scav("GuardBot"); // Create a ScavTrap
    
    FragTrap frag("Fragger"); // Create a FragTrap

    std::cout << "\n--- FragTrap High Fives ---" << std::endl;
    frag.highFivesGuys();
    
    std::cout << "\n--- FragTrap Status ---" << std::endl;
    frag.displayStatus();

    // more tests 

    return (EXIT_SUCCESS);
}
