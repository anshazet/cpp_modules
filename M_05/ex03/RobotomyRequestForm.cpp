/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:55:48 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/03 13:01:03 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    AForm::operator=(other);
    _target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw std::runtime_error("RobotomyRequestForm is not signed yet.");
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "\033[1;33mBrrrrr! Drilling noises! Brrrr!\033[0m" << std::endl; // Yellow for the noise
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));
    // Simulate a 50% chance of successful robotomization
    if (std::rand() % 2 == 0)
    {
        std::cout << "\033[1;32m" << _target << " has been robotomized successfully.\033[0m" << std::endl; // Green for success
    }
    else
    {
        std::cout << "\033[1;31mFailed to robotomize " << _target << ".\033[0m" << std::endl; // Red for failure
    }
}