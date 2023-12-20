/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:28:53 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 10:51:27 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &src);            // Copy constructor
    Ice &operator=(const Ice &rhs); // Copy assignment operator
    virtual ~Ice();                 // Destructor

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
