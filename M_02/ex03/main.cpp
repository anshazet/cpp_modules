/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:03:34 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/18 10:36:12 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include "Point.hpp"
#include <iostream>

int main(void)
{
    // Triangle vertices
    Point a(0, 0), b(10, 30), c(20, 0);

    // Points to check
    Point p1(10, 15), p2(0, 10.5), p3(30, 15);

    // Check for point p1
    if (bsp(a, b, c, p1))
    {
        std::cout << "Point " << p1 << " is in the triangle" << std::endl;
    }
    else
    {
        std::cout << "Point " << p1 << " is not in the triangle" << std::endl;
    }

    // Check for point p2
    if (bsp(a, b, c, p2))
    {
        std::cout << "Point " << p2 << " is in the triangle" << std::endl;
    }
    else
    {
        std::cout << "Point " << p2 << " is not in the triangle" << std::endl;
    }

    // Check for point p3
    if (bsp(a, b, c, p3))
    {
        std::cout << "Point " << p3 << " is in the triangle" << std::endl;
    }
    else
    {
        std::cout << "Point " << p3 << " is not in the triangle" << std::endl;
    }

    return 0;
}

/*

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
Output: Inside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0)

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
Output: Outside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(20,0)

Solution:
Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3). And coordinates of the given point P be (x, y)

Calculate area of the given triangle, i.e., area of the triangle ABC in the above diagram. 
Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2
Calculate area of the triangle PAB. We can use the same formula for this. Let this area be A1. 
Calculate area of the triangle PBC. Let this area be A2.
Calculate area of the triangle PAC. Let this area be A3.
If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.

*/