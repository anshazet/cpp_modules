/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:34:28 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:41:48 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
public:
    // Constructor initializes name and sets a reference to the given Weapon
    HumanA(const std::string& name, Weapon& weapon);

    // Function to print attack message
    void attack() const;

private:
    std::string name; // Human's name
    Weapon& weapon; // Reference to a Weapon
};

#endif
