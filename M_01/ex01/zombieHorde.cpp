/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:23:30 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:19:20 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N]; // This will now call the default constructor for each Zombie
    for (int i = 0; i < N; i++)
        horde[i].setName(name); // Set the name of each Zombie
    return horde;
}


/*
Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N]; // Allocate N Zombie objects in a single allocation

    for (int i = 0; i < N; ++i)
    {
        // Initialize each zombie in the horde with the provided name
        horde[i] = Zombie(name);
    }

    return horde; // Return a pointer to the first zombie in the horde
}
*/