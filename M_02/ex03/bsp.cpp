/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:54:03 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/18 10:41:46 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed   abs(Fixed x)
{
    if (x < 0)
        return x * -1;
    return x;
}

static Fixed   area( Point const a, Point const b, Point const c )
{
    return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
             ( b.getX() * ( c.getY() - a.getY() ) ) +
             ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   abcArea = abs(area( a, b, c ));
    Fixed   pabArea = abs(area( point, a, b ));
    Fixed   pbcArea = abs(area( point, b, c ));
    Fixed   pcaArea = abs(area( point, c, a ));

    return  ( abcArea == pabArea + pbcArea + pcaArea );
}

/*
The idea is to compare the area of the triangle formed by the vertices (a, b, c)
with the sum of areas of triangles formed by the point in question (point) and
the vertices of the original triangle.

abcArea is the area of the original triangle.
pabArea, pbcArea, and pcaArea are the areas of triangles formed by the point and
two of the triangle's vertices.
If the point lies inside the triangle, then the sum of pabArea, pbcArea, and pcaArea
should be equal to abcArea. This is because the point subdivides the original triangle
into three smaller triangles, whose total area must equal the area of the original
triangle if the point is inside.
*/
