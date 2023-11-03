/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:08:59 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/25 09:05:38 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "\033[1;33m[Brain Constructor] Brain is created!\033[0m" << std::endl;
}

Brain::~Brain()
{
    std::cout << "\033[1;33m[Brain Destructor] Brain is destroyed!\033[0m" << std::endl;
}

Brain::Brain(const Brain &src)
{
    *this = src;
}

Brain &Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
	{
        for (int i = 0; i < 100; i++)
		{
            ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}
