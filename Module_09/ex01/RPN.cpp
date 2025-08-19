/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

RPN::RPN()
{
	_expression = NULL;
}

RPN::RPN(const char *expression)
{
	_expression = expression;
}

RPN::RPN(const RPN &copy)
{
	_expression = copy._expression;
	*this = copy;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		_expression = src._expression;
		*this = src;
	}
	return (*this);
}

void RPN::treat_expression(void)
{
	int	number;
	int number2;

	if (!_expression)
		return ;
	int i = 0;
	while (_expression[i])
	{

		if (isdigit(_expression[i]))
		{
			number = _expression[i] - '0';
			_pile.push(number);
		}
		else if (i % 2 == 0)
		{
			number = _pile.top();
			_pile.pop();
			number2 = _pile.top();
			_pile.pop();
			if (_expression[i] == '+')
				_pile.push(number2 + number);
			if (_expression[i] == '-')
				_pile.push(number2 - number);
			if (_expression[i] == '*')
				_pile.push(number2 * number);
			if (_expression[i] == '/')
				_pile.push(number2 / number);
		}
		i++;
	}
	_result = _pile.top();
}

int	RPN::getResult(void) const
{
	return (_result);
}

RPN::~RPN()
{
}
