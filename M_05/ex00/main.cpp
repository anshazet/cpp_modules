/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:50:49 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/23 10:25:11 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		// Creates a Bureaucrat object named 'high' with a grade of 1.
		Bureaucrat high("Alice", 1);
		// Outputs the details of 'high' to the console.
		std::cout << high << std::endl;

		// Creates another Bureaucrat object named 'low' with a grade of 150.
		Bureaucrat low("Bob", 150);
		std::cout << low << std::endl;

		// Attempts to create a Bureaucrat object named 'tooHigh' with an invalid grade of 0.
        // This is expected to throw an exception since 0 is outside the valid range.
		// an exception
		Bureaucrat tooHigh("Charlie", 0);
	}
	catch (std::exception &e)
	{
        // Catches any standard exceptions thrown within the above try block.
        // This will catch the exception thrown by trying to create 'tooHigh' with a grade of 0.
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
       // Attempts to create a Bureaucrat object named 'tooLow' with an invalid grade of 151.
        // This is expected to throw an exception since 151 is outside the valid range.
		Bureaucrat tooLow("Dave", 151);
	}
	catch (std::exception &e)
	{
		// Catches any standard exceptions thrown within the above try block.
        // This will catch the exception thrown by trying to create 'tooLow' with a grade of 151.
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		// Creates a Bureaucrat object named 'normal' with a grade of 75.
		Bureaucrat normal("Eve", 75);
		// Outputs the details of 'normal' to the console.
		std::cout << normal << std::endl;

		// Increments the grade of 'normal' by 1.
		normal.incrementGrade();
		// Outputs the details of 'normal' after incrementing the grade.
		std::cout << "After increment: " << normal << std::endl;

		// Decrements the grade of 'normal' by 1.
		normal.decrementGrade();
		// Outputs the details of 'normal' after decrementing the grade.
		std::cout << "After decrement: " << normal << std::endl;
	}
	catch (std::exception &e)
	{
        // Catches any standard exceptions thrown within the above try block.
        // This block will catch exceptions if incrementing or decrementing the grade
        // of 'normal' results in a grade outside the valid range.
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
