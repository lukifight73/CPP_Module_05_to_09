/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 137, 145), m_target("default Target")
{
	std::cout << "ShrubberyCreationForm : Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 137, 145), m_target(target)
{
	std::cout << "ShrubberyCreationForm : Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm("PresidentialPardonForm", 137, 145), m_target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &ShrubberyCreationForm)
{
	o << "ShrubberyCreationForm :" << std::endl << "Target : ";
	o << ShrubberyCreationForm.getTarget() << " :" << std::endl;
	o << "Exec grade : " << ShrubberyCreationForm.getGradeSig() << std::endl;
	o << "Sign grade : " << ShrubberyCreationForm.getGradeExe() << std::endl;
	o << "Signed ? " << ShrubberyCreationForm.getisSigned() << std::endl << std::endl;
	return (o);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getisSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() <= 137)
	{
		std::cout << executor.getName() << " executed " << "ShrubberyCreationForm." << std::endl;
		std::ofstream outfile ((this->getTarget() + "_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}


const std::string ShrubberyCreationForm::getTarget(void)const
{
	return (this->m_target);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}
