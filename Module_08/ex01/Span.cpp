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

#include <iostream>
#include <string>
#include "Span.hpp"

Span::Span()
{
	_N = 0;
}

Span::Span(unsigned int N)
{
	_N = N;

}

Span::Span(const Span &src)
{
	_N = src._N;
	_array = src._array;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_N = src._N;
		_array = src._array;
		*this = src;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	int yo;

	yo = 0;
	for (std::vector<int>::iterator it = _array.begin() ; it != _array.end() ; it++)
		yo++;
	if (yo >= _N)
		throw Span::ArrayIsAlreadyFull();
	_array.push_back(number);
}

long int Span::shortestSpan()
{
	std::vector<int>::iterator it2;
	long int yo;
	long int yo2;

	yo = 0;
	for (std::vector<int>::iterator it = _array.begin() ; it != _array.end() ; it++)
		yo++;
	if (yo <= 1)
		throw Span::CannotFindSpan();
	yo = _array[0] - _array[1];
	if (yo < 0)
		yo = -yo;
	for (std::vector<int>::iterator it = _array.begin() ; it != _array.end() ; it++)
	{
		it2 = it + 1;
		while (it2 != _array.end())
		{
			yo2 = *it - *it2;
			if (yo2 < 0)
				yo2 = -yo2;
			if (yo > yo2)
				yo = yo2;
			it2++;
		}
	}
	return (yo);
}

long int Span::longestSpan()
{
	std::vector<int>::iterator it2;
	long int yo;
	long int yo2;

	yo = 0;
	for (std::vector<int>::iterator it = _array.begin() ; it != _array.end() ; it++)
		yo++;
	if (yo <= 1)
		throw Span::CannotFindSpan();
	yo = _array[0] - _array[1];
	if (yo < 0)
		yo = -yo;
	for (std::vector<int>::iterator it = _array.begin() ; it != _array.end() ; it++)
	{
		it2 = it + 1;
		while (it2 != _array.end())
		{
			yo2 = *it - *it2;
			if (yo2 < 0)
				yo2 = -yo2;
			if (yo < yo2)
				yo = yo2;
			it2++;
		}
	}
	return (yo);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_array.size() + std::distance(begin, end) > (unsigned long)this->_N)
		throw Span::ArrayIsAlreadyFull();
	this->_array.insert(this->_array.end(), begin, end);
}


Span::~Span()
{
}

const char *Span::ArrayIsAlreadyFull::what(void)const throw()
{
	return ("Warning : Array is already full.");
}

const char *Span::CannotFindSpan::what(void)const throw()
{
	return ("Warning : Too few elements in the array.");
}
