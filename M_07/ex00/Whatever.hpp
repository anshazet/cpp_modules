/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:36:41 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 09:53:17 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return (b <= a) ? b : a;
}

template <typename T>
T const &max(T const &a, T const &b)
{
	return (a <= b) ? b : a;
}

#endif // WHATEVER_HPP

/*
Template
template: This keyword indicates that what follows is a template definition.
Templates are a way to write code that works with any data type.

Typename
<typename T>: This part is a template parameter. It tells the compiler that T
is a placeholder for a type that will be specified later.
typename: This keyword can be replaced with class in this context
(i.e., you can also write template <class T>). Both mean the same thing in this
context and tell the compiler that T is a type parameter.
T: This is just a name for the type parameter. You could use any valid
dentifier here. T is commonly used as shorthand for "Type".

template <typename T>
T add(T a, T b) {
	return a + b;
}

int main() {
	int result1 = add(1, 2);     // Here T is int
	double result2 = add(1.5, 2.5); // Here T is double

	std::cout << "Int addition: " << result1 << std::endl;
	std::cout << "Double addition: " << result2 << std::endl;
}

*/