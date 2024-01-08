/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:34:08 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/08 13:55:24 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;
    std::cout << "value a = " << a << ", value b = " << b << std::endl;
	::swap(a, b);
    std::cout << "after swap" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;

    std::string c = "chaine1";
	std::string d = "chaine2";
    std::cout << "value c = " << c << ", value d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    std::cout << std::endl;

    float x = 24.0f;
    float y = 42.0f;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "value x = " << x << ", value y = " << y << std::endl;
    ::swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min(x, y) << std::endl;
	std::cout << "max( x, y ) = " << ::max(x, y) << std::endl;

	return 0;
}