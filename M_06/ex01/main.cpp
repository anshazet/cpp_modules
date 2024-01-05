/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:23:35 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/05 08:30:48 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data myData = { "John Smith", 30 };
    Data* dataPtr = &myData;

    std::cout << "Original pointer: " << dataPtr << std::endl;

    // Serialize
    uintptr_t serializedData = Serializer::serialize(dataPtr);
    std::cout << "Serialized data: " << serializedData << std::endl;

    // Deserialize
    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized pointer: " << deserializedData << std::endl;

    // Compare
    if (dataPtr == deserializedData)
	{
        std::cout << "Success: Original and deserialized pointers are equal." << std::endl;
    }
	else
	{
        std::cout << "Error: Pointers are not equal." << std::endl;
    }

    return 0;
}
