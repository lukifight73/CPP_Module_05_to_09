/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat(): m_name("default"), m_grade(150)
{
	std::cout << "Bureaucrat Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): m_name(name), m_grade(75)
{
	std::cout << "Bureaucrat Name constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(int i): m_name("default")
{
	std::cout << "Bureaucrat grade constructor called." << std::endl;
	this->setGrade(i);
}

Bureaucrat::Bureaucrat(std::string name, int i): m_name(name)
{
	std::cout << "Bureaucrat Name & grade constructor called." << std::endl;
	this->setGrade(i);
}

Bureaucrat::Bureaucrat(int i, std::string name): m_name(name)
{
	std::cout << "Bureaucrat Name & grade constructor called." << std::endl;
	this->setGrade(i);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->m_grade = src.getGrade();
	}
	return (*this);
}

void Bureaucrat::incrementGrade(void)
{
	this->setGrade(m_grade - 1);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade = grade;
}

void Bureaucrat::decrementGrade(void)
{
	this->setGrade(m_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what(void)const throw()
{
	return ("Warning : grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what(void)const throw()
{
	return ("Warning : grade too low.");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &Bureaucrat)
{
	o << Bureaucrat.getName() << ", bureaucrat grade : " << Bureaucrat.getGrade() << std::endl;
	return (o);
}

std::string Bureaucrat::getName(void)const
{
	return (m_name);
}

int Bureaucrat::getGrade(void)const
{
	return (m_grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called." << std::endl;
}
