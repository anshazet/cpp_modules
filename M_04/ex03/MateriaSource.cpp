/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:38:21 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 11:12:11 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        materias[i] = NULL;
    }
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &src)
{
    for (int i = 0; i < 4; ++i)
    {
        materias[i] = src.materias[i] ? src.materias[i]->clone() : NULL;
    }
}

// Copy assignment operator
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete materias[i];
            materias[i] = rhs.materias[i] ? rhs.materias[i]->clone() : NULL;
        }
    }
    return *this;
}

// Destructor
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!materias[i])
        {
            materias[i] = m->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i] && materias[i]->getType() == type)
        {
            return materias[i]->clone();
        }
    }
    return NULL;
}


