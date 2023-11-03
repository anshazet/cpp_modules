/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:27:10 by ashalagi          #+#    #+#             */
/*   Updated: 2023/10/05 09:30:32 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN"; // string variable
    std::string* stringPTR = &str;        // pointer to the string
    std::string& stringREF = str;         // reference to the string

    // Print memory addresses
    std::cout << "Address of string variable: " << &str << std::endl;
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address held by stringREF: " << &stringREF << std::endl;

    // Print string values
    std::cout << "Value of string variable: " << str << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

    return 0;
}

/*
Memory Addresses Are Consistent: The addresses of the str variable,
the address held by stringPTR, and the address held by stringREF are
all the same, which is expected since they all point to the
same std::string object.

Values Are Correct: The values of the str variable, the value pointed
to by stringPTR, and the value pointed to by stringREF are all
"HI THIS IS BRAIN". This is also expected since they all refer to
the same underlying string data.

References and Pointers: This exercise helps you understand that both
pointers and references can be used to refer to and manipulate the
same underlying data (in this case, a std::string object).
*/