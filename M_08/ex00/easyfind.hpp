/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:00:26 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/06 15:03:51 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// easyfind.hpp
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // For std::find
#include <exception> // For std::exception

template<typename T>
int easyfind(T& container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end())
	{
        throw std::exception(); // Or return a special value
    }
    return *it;
}

#endif // EASYFIND_HPP

/*
A template function accepts a type T. It takes two parameters: the first is of type T,
and the second is an integer.
Assuming T is a container of integers, this function must find the first occurrence
of the second parameter within the first parameter.
If no occurrence is found, you can either throw an exception or return an error value
of your choice. For inspiration, you may look at the behavior of standard containers.
*/