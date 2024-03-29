/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:25 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 12:48:42 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
