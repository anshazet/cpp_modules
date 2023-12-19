/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:17 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 12:48:35 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
    	Brain *brain;

	public:
    	Cat();
    	virtual ~Cat();

		Cat(const Cat &src); // Copy constructor
    	Cat &operator=(const Cat &rhs); // Copy assignment operator

    	virtual void makeSound() const;
};

#endif