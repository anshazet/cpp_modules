/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:12:49 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/18 09:25:08 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath> // Required for roundf function

class Fixed
{
public:
    // Constructors and destructor
    Fixed();                                  // Default constructor
    Fixed(const int integer);                 // Constructor that takes an integer
    Fixed(const float floating);              // Constructor that takes a float
    Fixed(const Fixed &source);               // Copy constructor
    ~Fixed();                                 // Destructor

    // Overload operators
    Fixed &operator=(const Fixed &source);    // Copy assignment operator
    friend std::ostream &operator<<(std::ostream &out, const Fixed &source); // Insertion operator overload

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;                // Convert fixed-point value to float
    int toInt(void) const;                    // Convert fixed-point value to int

private:
    int _fixedPointValue;                     // Fixed-point value
    static const int _fractionalBits = 8;     // Number of fractional bits
};
