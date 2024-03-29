/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:16:02 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/03 09:47:06 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // Forward declaration

class AForm
{
protected:
    const       std::string _name;
    bool        _isSigned;
    const int   _gradeToSign;
    const int   _gradeToExecute;

private:
    AForm();

public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    const   std::string &getName() const;
    bool    isSigned() const;
    int     getGradeToSign() const;
    int     getGradeToExecute() const;

    void            beSigned(const Bureaucrat &bureaucrat);
    virtual void    execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif