/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:52:18 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 10:54:03 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *materias[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);            // Copy constructor
    MateriaSource &operator=(const MateriaSource &rhs); // Copy assignment operator
    virtual ~MateriaSource();                           // Destructor

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};

#endif
