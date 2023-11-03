/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:25:17 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/24 09:56:25 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
    	Cat();
    	virtual ~Cat();
    	Cat(const Cat &src);
    	Cat &operator=(const Cat &rhs);

    	virtual void makeSound() const;
};

#endif
