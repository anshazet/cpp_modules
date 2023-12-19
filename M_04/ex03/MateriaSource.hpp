/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:52:18 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 13:39:45 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <array>

class MateriaSource : public IMateriaSource
{
private:
    std::array<AMateria*, 4> materias;

public:
    MateriaSource()
	{
        materias.fill(nullptr);
    }

    void learnMateria(AMateria* m) override
	{
        for (auto & materia : materias)
		{
            if (!materia)
			{
                materia = m->clone();
                break;
            }
        }
    }

    AMateria* createMateria(std::string const & type) override
	{
        for (auto & materia : materias)
		{
            if (materia && materia->getType() == type)
			{
                return materia->clone();
            }
        }
        return nullptr;
    }
};

#endif