/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:15:34 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/02 13:07:42 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <exception>

class Bureaucrat
{
private:
    Bureaucrat();
    const std::string _name;
    int _grade;

    static const int highestGrade = 1;
    static const int lowestGrade = 150;

public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other); // Copy constructor
    Bureaucrat &operator=(const Bureaucrat &other);  // Assignment operator overload
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);

    // Nested class for handling exceptions when the grade is too high.
    class GradeTooHighException : public std::exception
    {
    public:
        // Override of the 'what' method to provide a custom error message.
        virtual const char *what() const throw();
    };
    // Nested class for handling exceptions when the grade is too low.
    class GradeTooLowException : public std::exception
    {
    public:
        // Override of the 'what' method to provide a custom error message.
        virtual const char *what() const throw();
    };
// private:
// 	Bureaucrat();
};

// Overload of the insertion (<<) operator for the Bureaucrat class.
// This allows Bureaucrat objects to be outputted to standard streams like std::cout.
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP

/*
class Bureaucrat
{
public:
    // Constructor that takes a name and a grade. It initializes a Bureaucrat with these values.
    Bureaucrat(const std::string &name, int grade);

    // Copy constructor that creates a new Bureaucrat as a copy of another Bureaucrat.
    Bureaucrat(const Bureaucrat &other);

    // Assignment operator overload. Allows one Bureaucrat to be assigned to another.
    Bureaucrat &operator=(const Bureaucrat &other);

    // Destructor for the Bureaucrat class.
    ~Bureaucrat();

    // Getter for the Bureaucrat's name. Returns a constant reference to the name string.
    const std::string &getName() const;

    // Getter for the Bureaucrat's grade. Returns the grade as an integer.
    int getGrade() const;

    // Function to increment the Bureaucrat's grade. Decreases the grade number by 1.
    void incrementGrade();

    // Function to decrement the Bureaucrat's grade. Increases the grade number by 1.
    void decrementGrade();

    // Nested class for handling exceptions when the grade is too high.
    class GradeTooHighException : public std::exception
    {
    public:
        // Override of the 'what' method to provide a custom error message.
        virtual const char *what() const throw();
    };

    // Nested class for handling exceptions when the grade is too low.
    class GradeTooLowException : public std::exception
    {
    public:
        // Override of the 'what' method to provide a custom error message.
        virtual const char *what() const throw();
    };

private:
    // Private member variable to store the name of the Bureaucrat. It is constant.
    const std::string _name;

    // Private member variable to store the grade of the Bureaucrat.
    int _grade;

    // Static constant representing the highest possible grade.
    static const int highestGrade = 1;

    // Static constant representing the lowest possible grade.
    static const int lowestGrade = 150;
};

// Overload of the insertion (<<) operator for the Bureaucrat class.
// This allows Bureaucrat objects to be outputted to standard streams like std::cout.
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
*/