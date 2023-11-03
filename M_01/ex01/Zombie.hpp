/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:22:16 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:17:58 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie(); // Default constructor
    Zombie(std::string name); // Parameterized constructor
    ~Zombie(); // Destructor
    void announce() const; // Announce function
    void setName(std::string name); // Setter for name

private:
    std::string _name; // Name of the zombie
};

#endif
