/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:03:04 by ashalagi          #+#    #+#             */
/*   Updated: 2023/11/27 08:57:57 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): currentContactCount(0)
{
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::welcome(void) const
{
    std::cout << std::endl;
    std::cout << "\033[1;34m📞 Welcome to Your Awesome PhoneBook 📖\033[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::usage(void) const
{
    std::cout << std::endl;
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void)
{
    static int  i; //retain its value between function calls

    //init()is presumably responsible for initializing the contact with default values or prompting the user to enter contact information.
    this->_contacts[i % 8].init(); //this-> is a pointer that refers to the current instance (object) of a class within a member function. used to access a member of the current object
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void    PhoneBook::printContacts(void) const
{
    std::cout << "-------- PHONBOOK CONTACTS -------" << std::endl;
    for (size_t i = 0; i < 8; i++)
    {
        this->_contacts[i].view(i);
    }
    std::cout << std::endl;
}

int PhoneBook::_readInput() const
{
    int input = -1; // Initialize input with -1
    bool valid = false; // Initialize a boolean flag as false to indicate invalid input

    do {
        std::cout << "Please enter the contact index: " << std::flush; // Prompt the user for input
        std::cin >> input; // Read an integer from the user

        // Check if the input is valid
        if (std::cin.good() && (input >= 0 && input <= 8))
        {
            // If the input is an integer and within the range [0, 8]
            valid = true; // Set the flag to true to exit the loop
        }
        else
        {
            // If the input is invalid
            std::cin.clear(); // Clear the error flags on the input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input until a newline character
            std::cout << "Invalid index; please re-enter." << std::endl; // Display an error message
        }
    } while (!valid); // Continue the loop until valid input is provided

    return input; // Return the valid input
}

void    PhoneBook::search(void) const
{
    int index = this->_readInput();

    // Check if the index is within the range of the current contacts count
    if (index >= 0 && index < this->currentContactCount)
    {
        this->_contacts[index].display(index);
    }
    else
    {
        std::cout << "Error, contact with index " << index << " does not exist." << std::endl;
    }
    this->_contacts[index].display(index);
}


/*
It initializes input to -1 and valid to false. input will store the user's input,
and valid is a flag to indicate whether the input is valid or not.

It enters a do-while loop, which means it will always execute at least once.
Inside the loop, it prompts the user to enter a contact index using std::cout.

It reads an integer from the user and stores it in the input variable using std::cin >> input.

It checks whether the input is valid by using std::cin.good(), which checks if the input stream
is in a good state (i.e., it's an integer). Additionally, it checks if the input is within
the range [0, 8].

If the input is valid, it sets the valid flag to true, and the loop will exit.

If the input is not valid, it does the following:

Clears any error flags that may have been set on the input stream using std::cin.clear().

Ignores any remaining input until a newline character is encountered using std::cin.ignore().
This step is necessary to clear the invalid input from the input stream.

Displays an error message asking the user to re-enter a valid input.

The loop continues until valid becomes true, indicating that the user has provided valid input.

Finally, it returns the valid input value to the caller.
This function ensures that the user provides a valid integer input within the specified range
before proceeding further in the program. If the user provides invalid input, they are prompted
to re-enter it until it's valid.
*/