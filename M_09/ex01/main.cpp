/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:15:07 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/10 13:27:23 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;
		return 1;
	}

	RPN calculator;
	try
	{
		int result = calculator.evaluateExpression(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

/*
Example 1: "8 9 * 9 - 9 - 9 - 4 - 1 +"

Push 8 and 9 onto the stack.
Encounter *, so pop 8 and 9, multiply (8 * 9 = 72), and push the result (72) back.
Push 9 onto the stack.
Encounter -, so pop 72 and 9, subtract (72 - 9 = 63), and push the result (63) back.
Push 9 onto the stack.
Encounter -, so pop 63 and 9, subtract (63 - 9 = 54), and push the result (54) back.
Push 9 onto the stack.
Encounter -, so pop 54 and 9, subtract (54 - 9 = 45), and push the result (45) back.
Push 4 onto the stack.
Encounter -, so pop 45 and 4, subtract (45 - 4 = 41), and push the result (41) back.
Push 1 onto the stack.
Encounter +, so pop 41 and 1, add (41 + 1 = 42), and push the result (42) back.
End of expression, 42 is the result.
Example 2: "7 7 * 7 -"

Push 7 and 7 onto the stack.
Encounter *, so pop 7 and 7, multiply (7 * 7 = 49), and push the result (49) back.
Push 7 onto the stack.
Encounter -, so pop 49 and 7, subtract (49 - 7 = 42), and push the result (42) back.
End of expression, 42 is the result.


Example 1: 8 9 * 9 - 9 - 9 - 4 - 1 +
8 9 *: Multiply 8 and 9 → 72
72 9 -: Subtract 9 from 72 → 63
63 9 -: Subtract 9 from 63 → 54
54 9 -: Subtract 9 from 54 → 45
45 4 -: Subtract 4 from 45 → 41
41 1 +: Add 1 to 41 → 42
Final result: 42

Example 2: 7 7 * 7 -
7 7 *: Multiply 7 and 7 → 49
49 7 -: Subtract 7 from 49 → 42
Final result: 42

Example 3: 1 2 * 2 / 2 * 2 4 - +
1 2 *: Multiply 1 and 2 → 2
2 2 /: Divide 2 by 2 → 1
1 2 *: Multiply 1 and 2 → 2
2 2 4 -: Subtract 4 from 2 → -2
2 -2 +: Add -2 to 2 → 0
Final result: 0


*/