/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:44:47 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/10 07:41:22 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &src) : std::stack<T>(src) {}
	MutantStack &operator=(const MutantStack &rhs)
	{
		std::stack<T>::operator=(rhs);
		return *this;
	}
	~MutantStack() {}

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
	const_iterator begin() const
	{
		return this->c.begin();
	}
	const_iterator end() const
	{
		return this->c.end();
	}
};

#endif // MUTANTSTACK_HPP
/*
The MutantStack class inherits from std::stack<T>.
We define iterator and const_iterator types based on the iterator types
of the underlying container (std::stack<T>::container_type).
The class includes a default constructor, a copy constructor,
an assignment operator, and a destructor.
The begin() and end() methods return iterators to the beginning and
end of the underlying container.

This MutantStack can be used much like a regular stack but also allows 
iteration over its elements. It's important to remember that the order
of elements in the stack (LIFO - last in, first out) is the reverse of
their order in the underlying container. So when you iterate over a
MutantStack, the first element you get is the bottom of the stack, not the top.
*/