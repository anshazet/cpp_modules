/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:29:30 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 10:51:42 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &src);            // Copy constructor
    Cure &operator=(const Cure &rhs); // Copy assignment operator
    virtual ~Cure();                  // Destructor

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
