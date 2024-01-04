/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:50:49 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/04 11:01:18 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Create bureaucrats
        Bureaucrat chief("Chief", 1); // High-ranked bureaucrat
        Bureaucrat intern("Intern", 150); // Low-ranked bureaucrat

        // Create forms
        ShrubberyCreationForm shrubForm("Shrubby");
        RobotomyRequestForm robotForm("Robot");
        PresidentialPardonForm pardonForm("President");

        // Chief attempts to sign all forms
        chief.signForm(shrubForm);
        chief.signForm(robotForm);
        chief.signForm(pardonForm);

        // Intern attempts to execute all forms (expected to fail)
        intern.executeForm(shrubForm);
        intern.executeForm(robotForm);
        intern.executeForm(pardonForm);

        // Chief attempts to execute all forms
        chief.executeForm(shrubForm);
        chief.executeForm(robotForm);
        chief.executeForm(pardonForm);



    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

