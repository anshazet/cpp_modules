/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:03 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/18 08:20:10 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Constructor that takes an integer
Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = integer << _fractionalBits;
}

// Constructor that takes a float
Fixed::Fixed(const float floating)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(floating * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &source)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
        _fixedPointValue = source.getRawBits();
    return *this;
}

// Convert fixed-point value to float
float Fixed::toFloat(void) const
{
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

// Convert fixed-point value to int
int Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &source)
{
    out << source.toFloat();
    return out;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
