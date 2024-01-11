/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:55:51 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/10 13:17:53 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& /* other */) {}

RPN& RPN::operator=(const RPN& /* other */)
{
	return *this;
}

RPN::~RPN() {}

int RPN::evaluateExpression(const std::string &expression) const
{
	std::istringstream iss(expression);
	std::stack<int> stack;
	char token;
	int num;

	while (iss >> token)
	{
		if (isdigit(token))
		{
			iss.unget();
			iss >> num;
			stack.push(num);
		}
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Invalid expression");

			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result = performOperation(a, b, token);
			stack.push(result);
		}
		else
		{
			throw std::runtime_error("Error: Invalid token");
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
	return stack.top();
}

bool RPN::isOperator(const char &token) const
{
	return token == '+' || token == '-' || token == '*' || token == '/';
}

int RPN::performOperation(const int &a, const int &b, const char &op) const
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw std::runtime_error("Error: Division by zero");
		return a / b;
	default:
		throw std::runtime_error("Error: Unknown operator");
	}
}
