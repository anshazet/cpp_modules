/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:50:49 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/03 14:27:10 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        // Create bureaucrats
        Bureaucrat chief("Chief", 1);               // High-ranked bureaucrat
        Bureaucrat internBureaucrat("Intern", 150); // Low-ranked bureaucrat

        // Create an intern
        Intern someRandomIntern;

        // Use the intern to create forms
        AForm *shrubForm = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm *robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *pardonForm = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

        // Check if forms were created successfully
        if (shrubForm && robotForm && pardonForm)
        {
            // Chief attempts to sign all forms
            chief.signForm(*shrubForm);
            chief.signForm(*robotForm);
            chief.signForm(*pardonForm);

            // Intern attempts to execute all forms (expected to fail)
            internBureaucrat.executeForm(*shrubForm);
            internBureaucrat.executeForm(*robotForm);
            internBureaucrat.executeForm(*pardonForm);

            // Chief attempts to execute all forms
            chief.executeForm(*shrubForm);
            chief.executeForm(*robotForm);
            chief.executeForm(*pardonForm);
        }
        else
        {
            std::cerr << "Error: One or more forms could not be created." << std::endl;
        }

        // Clean up dynamically allocated forms
        delete shrubForm;
        delete robotForm;
        delete pardonForm;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
