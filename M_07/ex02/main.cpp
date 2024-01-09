/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:37:13 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/09 11:29:19 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	try
	{
		//Creating and Initializing the Array:
		//This segment creates an array of integers with 5 elements and initializes
		//each element with its index squared. The values are then printed out.
		Array<int> intArray(5);
		for (unsigned int i = 0; i < intArray.size(); ++i)
		{
			intArray[i] = i * i;
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;


		//Testing Deep Copy
		// This part tests the deep copy feature. Modifying copyArray should not affect
		//intArray, demonstrating that a true copy of the array is made, not just a
		//shallow copy of pointers.
		Array<int> copyArray = intArray;
		copyArray[0] = 42; // This change should not affect intArray

		for (unsigned int i = 0; i < intArray.size(); ++i)
		{
            std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

		//the program attempts to access an element beyond the array's bounds
		std::cout << "Accessing out-of-bounds element: " << intArray[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
