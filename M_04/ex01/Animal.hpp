/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:10:54 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/24 10:35:27 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
    	std::string type;

	public:
    	Animal(); // Default constructor
    	virtual ~Animal();	// Virtual destructor ensures that the appropriate destructor
							//is called when an object is deleted through a pointer of the base class type.	
		Animal(const Animal &src); // Copy constructor
    	Animal &operator=(const Animal &rhs); // Assignment operator

    	virtual void makeSound() const;
    	std::string getType() const;
};

#endif
