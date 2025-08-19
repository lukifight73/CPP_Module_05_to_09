/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>

Intern::Intern()
{
	std::cout << "Intern : Default constructor called." << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern assignment operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}
	return (*this);
}

const char *Intern::FormNameProvidedNotExist::what(void)const throw()
{
	return ("Warning : Form name provided does not exist.");
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string form_to_create, std::string target_for_form)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i])
		{
			std::cout << "Intern creates " << form_to_create << " now" << std::endl;
			return (all_forms[i](target_for_form));
		}
	}

	std::cout << "\033[33mIntern can not create a form called " << form_to_create << "\033[0m" << std::endl;
	return (NULL);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called." << std::endl;
}
