/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:15:46 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/02 13:21:00 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp" 

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
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

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
        // Note: _name, _gradeToSign, and _gradeToExecute are constants and cannot be changed
    }
    return *this;
}

Form::~Form(){}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
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

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form::GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() << ", Status: " << (form.isSigned() ? "Signed" : "Unsigned") << ", Grade Required to Sign: " << form.getGradeToSign() << ", Grade Required to Execute: " << form.getGradeToExecute();
    return os;
}
