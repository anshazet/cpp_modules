/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:25 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/25 08:31:58 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
    	Brain *brain;
	
	public:
    	Dog();
		virtual ~Dog();
		
    	Dog(const Dog &src);
    	Dog &operator=(const Dog &rhs);

    	virtual void makeSound() const;
};

#endif
