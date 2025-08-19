/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/14 11:35:09 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

std::cout << std::endl << "-----------------------------------------------------" << std::endl << std::endl;

int i = 0;
Span yoho = Span(12000);
while (i < 12000)
{
	yoho.addNumber(i * 1.3597);
	i++;
}
std::cout << yoho.shortestSpan() << std::endl;
std::cout << yoho.longestSpan() << std::endl;

std::cout << std::endl << "-----------------------------------------------------" << std::endl << std::endl;


Span yohohi = Span(0);
try
{
	yohohi.addNumber(3);
}
catch(Span::ArrayIsAlreadyFull &e)
{
	std::cerr << e.what() << std::endl;
}
try
{
	std::cout << yohohi.shortestSpan() << std::endl;
}
catch(Span::CannotFindSpan &e)
{
	std::cerr << e.what() << std::endl;
}
try
{
	std::cout << yohohi.longestSpan() << std::endl;
}
catch(Span::CannotFindSpan &e)
{
	std::cerr << e.what() << std::endl;
}

std::cout << std::endl << "-----------------------------------------------------" << std::endl << std::endl;

Span yohoho = Span(0);
try
{
	yohoho.addNumber(3);
}
catch(Span::ArrayIsAlreadyFull &e)
{
	std::cerr << e.what() << std::endl;
}
try
{
	yohoho.addNumber(4);
}
catch(Span::ArrayIsAlreadyFull &e)
{
	std::cerr << e.what() << std::endl;
}
try
{
	std::cout << yohoho.shortestSpan() << std::endl;
}
catch(Span::CannotFindSpan &e)
{
	std::cerr << e.what() << std::endl;
}
try
{
	std::cout << yohoho.longestSpan() << std::endl;
}
catch(Span::CannotFindSpan &e)
{
	std::cerr << e.what() << std::endl;
}

std::cout << std::endl << "-----------------------------------------------------" << std::endl << std::endl;

std::vector<int> uuu;
uuu.push_back(5);
uuu.push_back(5);
uuu.push_back(5);
uuu.push_back(5);
uuu.push_back(5);
Span yohoha = Span(7);
try
{
	yohoha.addNumbers(uuu.begin(), uuu.end());
}
catch(Span::ArrayIsAlreadyFull &e)
{
	std::cerr << e.what() << std::endl;
}
std::cout << std::endl << "-----------------------------------------------------" << std::endl << std::endl;

Span yohohu = Span(3);
try
{
	yohohu.addNumbers(uuu.begin(), uuu.end());
}
catch(Span::ArrayIsAlreadyFull &e)
{
	std::cerr << e.what() << std::endl;
}
return 0;
}
