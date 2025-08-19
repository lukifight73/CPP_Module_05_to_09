/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/15 09:53:39 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	isoperator(char c)
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return (1);
	return (0);
}

int parsing_expression(const char *expression)
{
	int i = 0;

	while (expression[i])
	{
		if (i % 2 == 0)
		{
			if (!(isdigit(expression[i])) && !isoperator(expression[i]))
			{
				std::cout << "Error: Wrong expression: " << expression[i] << std::endl;
				return (1);
			}
		}
		else if (expression[i] != ' ')
		{
			std::cout << "Error: Wrong expression: " << expression[i] << std::endl;
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Wrong number of parameters" << std::endl;
		return (1);
	}
	if (parsing_expression(av[1]))
		return (1);
	RPN yo(av[1]);
	yo.treat_expression();
	std::cout << yo.getResult() << std::endl;
	return (0);
}
