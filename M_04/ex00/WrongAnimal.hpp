/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:04:07 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/24 11:05:34 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
    	std::string type;

	public:
    	WrongAnimal(); // Default constructor
    	virtual ~WrongAnimal(); // Destructor
    	WrongAnimal(const WrongAnimal &src); // Copy constructor
    	WrongAnimal &operator=(const WrongAnimal &rhs); // Assignment operator

    	void makeSound() const;
    	std::string getType() const;
};

#endif