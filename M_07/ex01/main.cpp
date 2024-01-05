/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:11:22 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 10:30:56 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(const T &element)
{
	std::cout << element << ' ';
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);
	std::cout << "Integer array: ";
	iter(intArray, intArraySize, printElement);
	std::cout << std::endl;

	std::string stringArray[] = {"Hello", "World", "Test"};
	size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);
	std::cout << "String array: ";
	iter(stringArray, stringArraySize, printElement);
	std::cout << std::endl;

	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	size_t floatArraySize = sizeof(floatArray) / sizeof(floatArray[0]);
	std::cout << "Float array: ";
	iter(floatArray, floatArraySize, printElement);
	std::cout << std::endl;

	double doubleArray[] = {1.111, 2.222, 3.333, 4.444, 5.555};
	size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
	std::cout << "Double array: ";
	iter(doubleArray, doubleArraySize, printElement);
	std::cout << std::endl;

	return 0;
}

/*
printElement is a template function that prints a single element of the array.
iter is used to iterate over an array of integers and an array of strings.

sizeof(intArray): This part of the expression uses the sizeof operator to
get the total size (in bytes) of the intArray. If intArray is an array of
integers, and each int occupies 4 bytes (this size can vary depending on
the system and compiler), then the size of intArray would be number
of elements * size of each element in bytes.

sizeof(intArray[0]): This part gets the size of the first element of
the array (in bytes). If our array is of integers and an int is 4 bytes,
sizeof(intArray[0]) would be 4.

Division (/): The total size of the array (in bytes) is divided by the
size of one element of the array (also in bytes). This division gives
the total number of elements in the array.
For example, if intArray has 5 integers and each integer is 4 bytes,
sizeof(intArray) would be 20 (5 * 4). Dividing this by the size of
one integer (4), we get 20 / 4 = 5, which is the number of elements in the array.

size_t: The result is stored in a variable of type size_t.
size_t is an unsigned integer type and is the type returned by
the sizeof operator. It is used here to represent the size/count of elements in the array.
*/
