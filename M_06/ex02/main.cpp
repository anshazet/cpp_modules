/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:04:47 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 14:12:36 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

/*
The generate function creates an instance of A, B, or C
randomly and returns it as a Base pointer.
*/
Base *generate(void)
{
	srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
	switch (rand() % 3)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

/*
The identify functions use dynamic_cast to determine
the actual type of the object and print it out.
*/
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &)
		{
			std::cout << "C" << std::endl;
		}
	}
}

int main()
{
	Base *base = generate();

	identify(base);	 // Identify by pointer
	identify(*base); // Identify by reference

	delete base; // Clean up
	return 0;
}
