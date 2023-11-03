/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:06:52 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/20 14:06:49 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to create a new zombie on the heap, initialize it with a name, and return a pointer to it

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}
