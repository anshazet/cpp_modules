/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:23:42 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 08:47:09 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer
{
public:
    static uintptr_t	serialize(Data* ptr);
    static				Data* deserialize(uintptr_t raw);

private:
    // Private constructor and assignment operator to prevent instantiation.
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();
};

#endif // SERIALIZER_HPP
