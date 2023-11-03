/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:10:19 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/27 11:39:00 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
    const AAnimal* animals[5];
    
    std::cout << "\033[1;32mCreating animals...\033[0m" << std::endl;
    for(int i = 0; i < 3; i++)  // loop iterates 3 times, creating 3 Dog objects 
    {
        animals[i] = new Dog();
        animals[i]->makeSound();
    }
        
    for(int i = 3; i < 5; i++)  //loop iterates 2 times, creating 2 Cat objects
    {
        animals[i] = new Cat();
        animals[i]->makeSound();
    }

    // Demonstrate the use of the copy constructor
    std::cout << "\033[1;32mDemonstrating the use of copy constructor...\033[0m" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);  // This will invoke the copy constructor

    // demonstrate it for the Cat class
    Cat originalCat;
    Cat copiedCat(originalCat);  // This will invoke the copy constructor

    std::cout << "\033[1;31mDeleting animals...\033[0m" << std::endl;
    for(int i = 0; i < 5; i++)
        delete animals[i];

    return 0;
}

