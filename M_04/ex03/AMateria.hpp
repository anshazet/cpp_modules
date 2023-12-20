/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:26:29 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 11:28:21 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
protected:
    std::string _type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria const & src);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria*   clone() const = 0;
    virtual void        use(ICharacter& target);
};

#endif

/*
AMateria is an abstract class with a string attribute to store the type
of materia and two virtual functions that should be implemented by derived classes
*/