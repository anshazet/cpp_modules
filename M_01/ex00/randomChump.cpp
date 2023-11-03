/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:07:11 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/20 14:03:28 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to create a zombie on the stack, initialize it with a name,
// and make it announce itself
void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
