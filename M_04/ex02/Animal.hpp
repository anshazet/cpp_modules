/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:10:54 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/21 09:57:22 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal(); // Default constructor
        virtual ~AAnimal();    // Virtual destructor

        AAnimal(const AAnimal &src); // Copy constructor
        AAnimal &operator=(const AAnimal &rhs); // Assignment operator

        virtual void makeSound() const = 0; // Pure virtual function
        std::string getType() const;
};

#endif
/*
An abstract class is a class that cannot be instantiated on its own.
It serves as a blueprint for other classes to be derived from.
Abstract classes are used for the following reasons:

Defining a Common Interface:
Abstract classes allow you to define a common interface for derived classes.
This ensures that derived classes have certain methods with the same method
signatures, promoting consistency.

Encapsulating Common Functionality:
Abstract classes can encapsulate common functionality that can be shared across
multiple derived classes, promoting code reuse. Derived classes can inherit
members and methods of the abstract class and add or override functionality as needed.

Preventing Direct Instantiation:
Since abstract classes are meant to be blueprints, it doesn’t make sense to instantiate
them. Making a class abstract prevents direct instantiation, ensuring that only derived
classes can be instantiated.

Promoting Polymorphism:
Abstract classes allow for polymorphism, where a base class reference or pointer can point
to objects of any of its derived classes. This allows for dynamic method binding, enabling
you to write more flexible and reusable code.
Defining Pure Virtual Functions:
An abstract class can contain pure virtual functions. A pure virtual function is a function
that has no body in the abstract class and must be overridden by any non-abstract derived
class. This forces derived classes to provide an implementation for these functions, ensuring
a consistent interface.

*/
