/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:05:35 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/03 07:55:35 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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

    // Delete the heap zombie to free the memory allocated on the heap
    delete heapZombie;

    delete fooZombie; // Don't forget to delete the heap-allocated zombie

    return 0;
}

