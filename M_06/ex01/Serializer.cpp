/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:23:39 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 08:53:40 by ashalagi         ###   ########.fr       */
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

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

