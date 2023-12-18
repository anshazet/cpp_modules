/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:12:33 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/18 08:20:08 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

/*
Added constructors that take integer and float arguments. The integer constructor
shifts the integer value left by the number of fractional bits (_fractionalBits),
while the float constructor converts the float to a fixed-point number by multiplying
it by 2 to the power of _fractionalBits and rounding the result.

Added toFloat() and toInt() member functions to convert the fixed-point number back to
a float or integer respectively.

Overloaded the insertion operator to output a Fixed object as a float to an ostream object.
*/