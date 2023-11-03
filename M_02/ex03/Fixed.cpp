/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:44:00 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/31 13:07:32 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
    //std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = integer << _fractionalBits;
}

Fixed::Fixed(const float floating)
{
    //std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = static_cast<int>(roundf(floating * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &source)
{
    //std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = source._fixedPointValue;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &source)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
    {
        _fixedPointValue = source._fixedPointValue;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &source)
{
    out << static_cast<float>(source._fixedPointValue) / (1 << Fixed::_fractionalBits); // Adjust this line to output the format you want
    return out;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}



// Comparison Operators
bool Fixed::operator>(const Fixed &other) const
{
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _fixedPointValue != other._fixedPointValue;
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    // Handle division by zero if necessary
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment/Decrement Operators
Fixed &Fixed::operator++()
{
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _fixedPointValue--;
    return temp;
}

// Min and Max Functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
