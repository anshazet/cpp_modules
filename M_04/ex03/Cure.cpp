/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:33:19 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 11:35:01 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") {}

// Copy constructor
Cure::Cure(const Cure &src) : AMateria(src) {}

// Copy assignment operator
Cure &Cure::operator=(const Cure &rhs)
{
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
    }
    return *this;
}

// Destructor
Cure::~Cure() {}

// Clone method
AMateria *Cure::clone() const
{
    return new Cure(*this);
}

// Use method
void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
