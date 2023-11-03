/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:08:06 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/24 12:11:11 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
    	Brain();
    	~Brain();
    	Brain(const Brain &src);
    	Brain &operator=(const Brain &rhs);
    
    	std::string ideas[100];
};

#endif
