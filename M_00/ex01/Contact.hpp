/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:00:28 by ashalagi          #+#    #+#             */
/*   Updated: 2023/11/15 13:40:59 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
    public:
        Contact();
        ~Contact();
        void    init(void);
        void    view(int index) const;
        void    display(int index) const;
        void    setIndex(int i);

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        int         _index;

        std::string _printLen(std::string str) const;
        std::string _getInput(std::string str) const;

};

#endif