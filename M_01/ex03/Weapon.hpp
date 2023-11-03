/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:34:35 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:40:21 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
    // Constructor initializes the type
    Weapon(const std::string& type);

    // Const reference return to prevent modification
    const std::string& getType() const;

    // Set a new type for the weapon
    void setType(const std::string& type);

private:
    std::string type; // String to hold the type of weapon
};

#endif
