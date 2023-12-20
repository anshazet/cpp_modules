/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:23:07 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 11:35:40 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice &src) : AMateria(src) {}

// Copy assignment operator
Ice &Ice::operator=(const Ice &rhs)
{
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
    }
    return *this;
}

// Destructor
Ice::~Ice() {}

// Clone method
AMateria *Ice::clone() const
{
    return new Ice(*this);
}

// Use method
void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
