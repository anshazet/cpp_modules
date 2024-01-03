/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:41:45 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/03 14:06:33 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target) const;

private:
    typedef AForm *(Intern::*FormCreator)(const std::string &target) const;
    AForm *createShrubberyCreationForm(const std::string &target) const;
    AForm *createRobotomyRequestForm(const std::string &target) const;
    AForm *createPresidentialPardonForm(const std::string &target) const;
};

#endif // INTERN_HPP
