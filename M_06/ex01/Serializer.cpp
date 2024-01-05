/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:23:39 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 14:03:37 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Private constructor
Serializer::Serializer() {}

// Copy constructor (also private)
Serializer::Serializer(const Serializer&) {}

// Assignment operator (also private)
Serializer& Serializer::operator=(const Serializer&)
{
    return *this;
}

// Destructor
Serializer::~Serializer() {}

void* Serializer::serialize(Data *ptr)
{
    return static_cast<void*>(ptr);
}

Data* Serializer::deserialize(void* raw)
{
    return static_cast<Data*>(raw);
}

