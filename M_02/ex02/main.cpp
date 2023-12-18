/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:28:15 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/18 09:55:16 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed			a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

/*
The comparison operators are implemented by directly comparing the _fixedPointValue of the two Fixed objects.
Arithmetic operators convert the fixed-point value to float, perform the arithmetic operation, and then convert back to a Fixed object.
The increment and decrement operators respectively increase and decrease the _fixedPointValue by 1 (the smallest representable epsilon).
The min and max functions return references to the minimum or maximum of the two Fixed objects passed as parameters.
*/