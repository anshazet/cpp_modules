/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:55:27 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/04 10:24:55 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    AForm::operator=(other);
    _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
    {
        throw std::runtime_error("Form is not signed yet.");
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file((_target + "_shrubbery.txt").c_str());
    if (file)
    {
        file << "            &&  & " << std::endl;
        file << "         &&& &&  & &&" << std::endl;
        file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
        file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
        file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
        file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
        file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
        file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
        file << "     &&     \\|||" << std::endl;
        file << "             |||" << std::endl;
        file << "             |||" << std::endl;
        file << "             |||" << std::endl;
        file << "       , -=-~  .-^- _" << std::endl;
        
        file.close();
        std::cout << "Created a file with ASCII trees: " << _target << "_shrubbery.txt" << std::endl;
    }
    else
    {
        throw std::runtime_error("Could not open file for writing.");
    }
}


