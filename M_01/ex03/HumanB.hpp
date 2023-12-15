/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:34:19 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/15 10:15:22 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
public:
    // Constructor initializes name; weapon is set to nullptr initially
    explicit HumanB(const std::string& name);

    // Set the Weapon pointer to a given Weapon
    void setWeapon(Weapon& weapon);

    // Function to print attack message
    void attack() const;

private:
    std::string name; // Human's name
    Weapon* weapon; // Pointer to a Weapon
};

#endif
