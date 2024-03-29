/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:41:05 by ashalagi          #+#    #+#             */
/*   Updated: 2023/11/15 15:05:22 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}
/*
Function to prompt the user for input, read and validate it.
It's intended to keep asking for input until a valid input (non-empty and no input errors)
std::cin.good() checks if the input operation was successful without any errors.
!input.empty() checks if the input string is not empty.
*/
std::string Contact::_getInput(std::string str) const
{
    std::string input = ""; //"" initialize input to an empty string and to store the user's input
    bool        valid = false;
    do
    {
        std::cout << str << std::flush; //prints the prompt passed as an argument to the function (str), ensuring that it's immediately displayed with std::flush
        std::getline(std::cin, input);  //reads a line of text from the standard input (std::cin) and stores it in the input variable
        if (std::cin.good() && !input.empty()) //checks if the input is valid
            valid = true;   //If the input is valid, valid is set to true
        else
        {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    }
    while (!valid); // The loop continues (while (!valid);) until a valid input is provided.
    return (input);
}

void    Contact::init(void)
{
    this->_firstName = this->_getInput("Please enter you first name: ");
    this->_lastName = this->_getInput("Please enter your last name: ");
    this->_nickname = this->_getInput("Please enter your nickname: ");
    this->_phoneNumber = this->_getInput("Please enter your phone number: ");
    this->_darkestSecret = this->_getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}

std::string Contact::_printLen(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::setIndex(int i)
{
    this->_index = i;
}

void    Contact::view(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
    std::cout << "First Name:\t" << this->_firstName << std::endl;
    std::cout << "Last Name:\t" << this->_lastName << std::endl;
    std::cout << "Nickname:\t" << this->_nickname << std::endl;
    std::cout << std::endl;
}