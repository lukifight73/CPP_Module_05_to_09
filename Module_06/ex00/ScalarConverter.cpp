/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter Copy Constructor called" << std::endl;
	*this = copy;
}

void	ScalarConverter::convert(const std::string& str)
{
	int	int_value = 0;;
	char char_value = 0;
	double double_value;
	int	indice = 0;
	float float_value;
	char	*yo;

	if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
	{
		double_value = strtod(str.c_str(), NULL);
		float_value = static_cast<double>(double_value);
	}
	else if (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff")
	{
		float_value = strtof(str.c_str(), NULL);
		double_value = static_cast<double>(float_value);
	}
	else if (str.length() < 1 || (!isdigit(str[0]) && str[0] != '+' && str[0] != '-' && str.length() > 1))
	{
		std::cout << "Conversion impossible." << std::endl;
		return;
	}
	else
	{
		if (str.length() == 1 && !isdigit(str[0]))
		{
			int_value = static_cast<int>(str[0]);
			char_value = str[0];
			double_value = static_cast<double>(int_value);
			float_value = static_cast<double>(double_value);
			indice = 1;
			std::cout << "char: " << char_value << std::endl;
			std::cout << "int: " << int_value << std::endl;
		}
		else
		{
			double_value = strtod(str.c_str(), &yo);
			if (*yo == 'f' && yo[1] == '\0')
			{
				float_value = strtof(str.c_str(), &yo);
			}
			else if (*yo == '\0')
			{
				float_value = static_cast<float>(double_value);
			}
			else
			{
				std::cout << "Conversion impossible." << std::endl;
				return;
			}
		}
	}
	//print
	if (double_value > 2147483647.0f || double_value < -2147483648.0f || str == "nanf" || str == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else if (indice == 0)
	{
		int_value = static_cast<int>(float_value);
		char_value = static_cast<char>(int_value);
		if (!isprint(char_value))
			std::cout << "char: impossible" << std::endl;
		else
		{
			std::cout << "char: " << char_value << std::endl;
		}
		std::cout << "int: " << int_value << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << float_value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << double_value << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{

	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called." << std::endl;
}
