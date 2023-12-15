/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:47:44 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/13 12:30:02 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    // Declare the number of zombies in the horde
    int numZombies = 3;

    // Create a horde of zombies
    Zombie* horde = zombieHorde(numZombies, "Brain Eater");

    // Make each zombie in the horde announce itself
    for (int i = 0; i < numZombies; i++)
        horde[i].announce();

    // Delete the horde of zombies to free the memory allocated on the heap
    delete[] horde;

    return 0;
}

/*
// Declaration of functions defined in newZombie.cpp and randomChump.cpp
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    // Create a zombie on the heap using newZombie function
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce(); // Make the heap zombie announce itself

    Zombie* fooZombie = newZombie("Foo");
    fooZombie->announce();

    // Create a zombie on the stack using randomChump function and make it announce itself
    randomChump("Stack Zombie");

    // Create a horde of zombies on the heap using zombieHorde function
    int hordeSize = 5;
    Zombie *horde = zombieHorde(hordeSize, "Horde Zombie");

    // Announce each zombie in the horde
    for (int i = 0; i < hordeSize; ++i)
    {
        horde[i].announce();
    }

    // Delete the heap zombies and the horde to free the memory allocated on the heap
    delete heapZombie;
    delete fooZombie;
    delete[] horde;

    return 0;
}
*/