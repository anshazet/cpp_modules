/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:34:39 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 10:00:47 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        // Demonstrate HumanA
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    } // club goes out of scope here

    // Demonstrate HumanB
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();

    return 0;
}

/*
HumanA has a reference to a Weapon, which means it must be initialized
with a Weapon and cannot change its Weapon after construction.

HumanB has a pointer to a Weapon, allowing it to start without a Weapon
and set or change its Weapon later.

Both HumanA and HumanB can react to changes in their Weapon's type,
but they do so in different ways due to the use of reference in HumanA
and pointer in HumanB.

The use of a pointer in HumanB allows more flexibility but also requires
careful management to avoid dereferencing a null pointer.

Consider using smart pointers in a real application for safer memory management.

Remember to adjust your Makefile accordingly to compile these new source files.
Ensure each .cpp file is compiled and then linked together to create the final executable.

Key Takeaways and Explanation:

Understanding References and Pointers:
HumanA utilizes a reference to Weapon which must be initialized upon construction.
This reference is immutable, meaning it will always refer to the initial Weapon instance
it was assigned.
HumanB uses a pointer to Weapon. This allows HumanB to start without a Weapon
(the pointer can be nullptr initially) and have a Weapon assigned later.

Dynamic Behavior:
Both HumanA and HumanB classes dynamically respond to changes in their associated
Weapon instances. When the Weapon type is altered, subsequent attack() calls reflect this change.

Memory Management:
In this case, since you're not dynamically allocating memory (using new), you don't have
to worry about deleting any objects manually. The Weapon objects are being created on
the stack and will be automatically destroyed when they go out of scope.

Comparison between References and Pointers:
References are more restrictive as they must be initialized upon creation and cannot be
reseated to refer to different objects later. Pointers offer more flexibility but require
careful handling to avoid issues like null pointer dereferencing.

Reflection Question:
The exercise prompt asked you to reflect on when it might be better to use pointers
or references to Weapon. Now that you've completed the exercise:

Using Pointers: When you need optional or reassignable associations between objects,
pointers are useful. For instance, HumanB can exist without a Weapon and have a Weapon
assigned later.

Using References: When you want to establish a mandatory and immutable association
between objects upon creation, references are appropriate. For example, HumanA must have
a Weapon assigned upon construction, and this association cannot change thereafter.
*/