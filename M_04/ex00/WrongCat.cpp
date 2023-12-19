/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:12:37 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 10:09:36 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "A wrong cat is born!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "A wrong cat has died!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    std::cout << "A wrong cat has been copied!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    WrongAnimal::operator=(rhs);
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Pshhh pshhh!" << std::endl;
}
