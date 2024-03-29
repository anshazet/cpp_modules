/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:15:39 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/04 10:58:14 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < highestGrade)
	{
		throw GradeTooHighException();
	}
	else if (grade > lowestGrade)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= highestGrade)
	{
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= lowestGrade)
	{
		throw GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    bool wasAlreadySigned = form.isSigned();

    try
    {
        form.beSigned(*this);
        if (!wasAlreadySigned)
        {
            std::cout << this->getName() << " signed " << form.getName() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this); // Attempt to execute the form
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
