/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:15:46 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/02 15:04:39 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp" 

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
    {
        throw GradeTooHighException();
    }
    if (_gradeToSign > 150 || _gradeToExecute > 150)
    {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
        // Note: _name, _gradeToSign, and _gradeToExecute are constants and cannot be changed
    }
    return *this;
}

AForm::~AForm(){}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
    {
        _isSigned = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form::GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form: " << form.getName() << ", Status: " << (form.isSigned() ? "Signed" : "Unsigned") << ", Grade Required to Sign: " << form.getGradeToSign() << ", Grade Required to Execute: " << form.getGradeToExecute();
    return os;
}
