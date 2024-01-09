/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:44:48 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/09 09:09:40 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

// Constructor with size
template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &other) : _elements(new T[other._size]()), _size(other._size)
{
	for (size_t i = 0; i < _size; ++i)
	{
		_elements[i] = other._elements[i];
	}
}

// Assignment operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _elements;
		_size = other._size;
		_elements = new T[_size]();
		for (size_t i = 0; i < _size; ++i)
		{
			_elements[i] = other._elements[i];
		}
	}
	return *this;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

// Subscript operator for non-const objects
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return _elements[index];
}

// Subscript operator for const objects
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return _elements[index];
}

// Return the size of the array
template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

#endif // ARRAY_TPP
