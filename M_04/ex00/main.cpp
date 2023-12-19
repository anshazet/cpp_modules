/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:10:19 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/19 11:19:18 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // Will output the cat sound!
    j->makeSound(); // Will output the dog sound!
    meta->makeSound(); // Will output the generic animal sound!

    std::cout << wrongMeta->getType() << " " << std::endl;
    wrongMeta->makeSound(); // Will output the generic wrong animal sound!

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Will output the generic wrong animal sound because WrongCat doesn’t override it!

    // Additional tests for WrongCat
    std::cout << "---- WrongCat Specific Tests ----" << std::endl;

    // Directly create a WrongCat and make sound
    WrongCat directWrongCat;
    std::cout << "Direct WrongCat: ";
    directWrongCat.makeSound();

    // Pointing WrongAnimal pointer to WrongCat
    const WrongAnimal* wrongCatPointer = new WrongCat();
    std::cout << "WrongAnimal pointer to WrongCat: ";
    wrongCatPointer->makeSound();
    delete wrongCatPointer;

    // WrongAnimal for comparison
    WrongAnimal directWrongAnimal;
    std::cout << "Direct WrongAnimal: ";
    directWrongAnimal.makeSound();

    delete meta;
    delete j;
    delete i;

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
