/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:04:58 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 10:10:11 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
    	WrongCat();
    	virtual ~WrongCat();
    	WrongCat(const WrongCat &src);
    	WrongCat &operator=(const WrongCat &rhs);

        void makeSound() const;

};

#endif
