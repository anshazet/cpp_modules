/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:50:49 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/02 14:52:46 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat highRankBureaucrat("Alice", 10); // High rank
        Bureaucrat lowRankBureaucrat("Bob", 60); // Low rank

        Form highRankForm("TopSecret", 5, 1); // Requires high rank to sign
        Form lowRankForm("Standard", 50, 30); // Requires lower rank to sign

        std::cout << highRankBureaucrat << std::endl;
        std::cout << lowRankBureaucrat << std::endl;
        std::cout << highRankForm << std::endl;
        std::cout << lowRankForm << std::endl;

        // High rank bureaucrat attempts to sign low rank form
        highRankBureaucrat.signForm(lowRankForm);

        // Low rank bureaucrat attempts to sign high rank form
        lowRankBureaucrat.signForm(highRankForm);

        std::cout << "After signing attempts:" << std::endl;
        std::cout << highRankForm << std::endl;
        std::cout << lowRankForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        // Trying to create a form with invalid grades
        Form invalidForm("Invalid", 0, 160);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
