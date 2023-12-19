/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:45:38 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 13:46:17 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <array>

class Character : public ICharacter
{
private:
    std::string name;
    std::array<AMateria*, 4> inventory;

public:
    Character(std::string const & name) : name(name) {
        inventory.fill(nullptr);
    }

    std::string const & getName() const override {
        return name;
    }

    void equip(AMateria* m) override {
        for (auto & materia : inventory) {
            if (!materia) {
                materia = m;
                break;
            }
        }
    }

    void unequip(int idx) override {
        if (idx >= 0 && idx < 4) {
            inventory[idx] = nullptr;
        }
    }

    void use(int idx, ICharacter& target) override {
        if (idx >= 0 && idx < 4 && inventory[idx]) {
            inventory[idx]->use(target);
        }
    }
};

#endif