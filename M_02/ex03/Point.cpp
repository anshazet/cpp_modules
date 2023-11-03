/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:52:28 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/31 13:06:29 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	//std::cout << "Point default constructor calle" << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
    //std::cout << "Point float constructor called" << std::endl;
}

Point::Point( const Point &src ) : _x(src._x), _y(src._y)
{
    //std::cout << "Point copy constructor called" << std::endl;
}

Point::~Point()
{
    //std::cout << "Point destructor called" << std::endl;
}

Point&  Point::operator=( const Point &rhs )
{
    if ( this != &rhs )
	{
        // const_cast< Fixed& >(this->_x) = rhs.getX();
        // const_cast< Fixed& >(this->_y) = rhs.getY();
        ( Fixed ) this->_x = rhs.getX();
        ( Fixed ) this->_y = rhs.getY();
    }
    return *this;
}

Fixed Point::getX( void ) const
{
    return this->_x;
}

Fixed Point::getY( void ) const
{
    return this->_y;
}
