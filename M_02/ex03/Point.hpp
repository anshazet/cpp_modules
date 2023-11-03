/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:51:41 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/31 12:57:44 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point( const float x, const float y );
    Point( const Point &src );
    ~Point();

    Point&  operator=( const Point &rhs );

    Fixed getX( void ) const ;
    Fixed getY( void ) const ;
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point );


#endif