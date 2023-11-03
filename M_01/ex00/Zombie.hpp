/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:06:02 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/27 14:24:55 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
#include <iostream>

class Zombie
{
public:
    // Constructor to initialize a zombie with a name
    Zombie(std::string name);
    //Zombie(std::string name) {std::cout << "constructor are called " << this << std::endl; }
     // Destructor for debugging purposes, prints a message when a zombie is destroyed
    ~Zombie();
     // Member function to make a zombie announce itself
    void announce() const;

private:
    std::string _name;
};

#endif
