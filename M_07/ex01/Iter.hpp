/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:11:06 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 10:16:58 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*function)(const T &))
{
	for (size_t i = 0; i < length; ++i)
	{
		function(array[i]);
	}
}

#endif // ITER_HPP

/*
T* array: The first parameter is a pointer to the array,
with T being the type of the array elements.
size_t length: The second parameter is the length of the array.
void (*function)(const T&): The third parameter is a pointer
to a function that takes a reference to an element of type T and returns nothing.
*/
