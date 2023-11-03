/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:12:01 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/13 14:01:01 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main (void)
{
    //is a class that contains functions and data members for managing contacts in a phone book.
    PhoneBook book;

    //variable initializes it with an empty strin to store user input
    std::string input = "";

    //is calling the welcome() function on the book object, which is an instance of the PhoneBook class
    book.welcome();

    //compare the contents of the input variable (which is a std::string) with the string literal "EXIT"
    while (input.compare("EXIT")) 
    {
        if (input.compare("ADD") == 0)
            book.addContact();
        else if (input.compare("SEARCH") == 0)
        {
            book.printContacts();
            book.search();
        }
        std::cout << "> " << std::flush;
        std::cin >> input;
    }

    return (0);
}
/*
int main(void): This is the main function of the C++ program, where the program execution begins.

PhoneBook book;: This line declares a variable named book of type PhoneBook. Presumably,
PhoneBook is a class that contains functions and data members for managing contacts in a phone book.

std::string input = "";: This line declares a variable named input of type std::string and
initializes it with an empty string. This variable will be used to store user input.

book.welcome();: This line calls a function welcome() on the book object. This function likely
displays a welcome message or instructions to the user.

while (input.compare("EXIT")) {: This line starts a while loop that continues as long
as the user's input string does not match the string "EXIT". It uses the compare method
of std::string to compare the input string with "EXIT".

Inside the while loop, there are two main conditions checked:
if (input.compare("ADD") == 0): If the user input is "ADD," it calls the addContact() function
on the book object. This function is presumably used to add a new contact to the phone book.
else if (input.compare("SEARCH") == 0): If the user input is "SEARCH," it first calls the
printContacts() function to display the list of contacts and then calls the search() function,
which likely allows the user to search for a contact in the phone book.

std::cout << "> " << std::flush;: This line displays a prompt "> " to the user, indicating
that they should enter a command.

std::cin >> input;: This line reads a line of input from the user and stores it in the input variable.

The loop continues, and the program repeats the steps until the user enters "EXIT,"
at which point the loop exits.

Finally, return 0; is used to indicate that the program has completed successfully
and exits with a status code of 0.
*/