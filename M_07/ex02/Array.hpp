/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:37:16 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/09 11:21:28 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>	 // for size_t
#include <stdexcept> // for std::exception

template <typename T>
class Array
{
public:
	Array();							  // Default constructor
	Array(unsigned int n);				  // Constructor with size
	Array(const Array &other);			  // Copy constructor
	Array &operator=(const Array &other); // Assignment operator
	~Array();							  // Destructor

	T &operator[](unsigned int index);			   // Subscript operator for non-const objects
	const T &operator[](unsigned int index) const; // Subscript operator for const objects

	size_t size() const; // Return the size of the array

private:
	T *_elements;
	size_t _size;
};

#include "Array.tpp"

#endif // ARRAY_HPP
