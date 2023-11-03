/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:29:30 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/31 10:35:05 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure() : AMateria("cure") {}

    AMateria* clone() const override
	{
        return new Cure(*this);
    }

    void use(ICharacter& target) override
	{
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    }
};

#endif