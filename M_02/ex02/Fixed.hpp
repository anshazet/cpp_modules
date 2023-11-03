/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:28:35 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/10 14:17:39 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();                                  // Default constructor
    Fixed(const int integer);                 // Constructor that takes an integer
    Fixed(const float floating);              // Constructor that takes a float
    Fixed(const Fixed &source);               // Copy constructor
    ~Fixed();                                 // Destructor
    
    Fixed &operator=(const Fixed &source);    // Copy assignment operator
    friend std::ostream &operator<<(std::ostream &out, const Fixed &source); // Insertion operator overload
    
    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;                // Convert fixed-point value to float
    int toInt(void) const;                    // Convert fixed-point value to int

	bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++();     // Pre-increment
    Fixed operator++(int);   // Post-increment
    Fixed &operator--();     // Pre-decrement
    Fixed operator--(int);   // Post-decrement

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

private:
    int _fixedPointValue;                     // Fixed-point value
    static const int _fractionalBits = 8;     // Number of fractional bits
};

#endif
