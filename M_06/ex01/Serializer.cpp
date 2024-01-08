/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:23:39 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/08 14:46:20 by ashalagi         ###   ########.fr       */
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

std::size_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<std::size_t>(ptr);
}

Data *Serializer::deserialize(std::size_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
