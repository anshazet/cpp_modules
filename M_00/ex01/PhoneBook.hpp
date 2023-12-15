/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:00:38 by ashalagi          #+#    #+#             */
/*   Updated: 2023/11/27 08:32:54 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <vector>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
    void    welcome(void) const;
    void    usage(void) const;
    void    addContact(void);
    void    printContacts(void) const;
    void    search(void) const;

    private:
        Contact     _contacts[8];
    int         _readInput(void) const;
    int         currentContactCount;

};

#endif