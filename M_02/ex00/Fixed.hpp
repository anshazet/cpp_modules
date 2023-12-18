/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:44:47 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/18 09:28:47 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int value;                              // integer to store fixed-point number value
    static const int fractional_bits = 8;   // static constant for number of fractional bits

public:
    Fixed();                                // Default constructor
    Fixed(const Fixed &other);              // Copy constructor
    Fixed &operator=(const Fixed &other);   // Copy assignment operator
    ~Fixed();                               // Destructor

    int getRawBits(void) const;             // Member function to get raw value
    void setRawBits(int const raw);         // Member function to set raw value
};

#endif
