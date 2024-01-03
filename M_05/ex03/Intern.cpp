/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:41:55 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/03 14:30:33 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubberyCreationForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    // Define a structure to associate a form name with a member function that creates the form.
    struct FormTypes
    {
        std::string name;      // Name of the form.
        FormCreator creator;   // Pointer to member function that creates the form.
    };

    // Initialize an array of FormTypes. Each entry maps a form name to the corresponding creator function.
    FormTypes formTypes[] = {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };

    // Calculate the number of form types in the array.
    const int numForms = sizeof(formTypes) / sizeof(FormTypes);

    // Iterate through the array of form types.
    for (int i = 0; i < numForms; ++i)
    {
        // Check if the requested form name matches the current form type in the array.
        if (formName == formTypes[i].name)
        {
            // If a match is found, print a message indicating the intern creates this form.
            std::cout << "Intern creates " << formName << std::endl;
            
            // Call the creator function associated with this form type and return the new form.
            return (this->*formTypes[i].creator)(target);
        }
    }

    // If the form name is not found in the array, print an error message.
    std::cerr << "Error: Form name '" << formName << "' is not recognized." << std::endl;

    // Return NULL to indicate that no form was created.
    return NULL;
}
