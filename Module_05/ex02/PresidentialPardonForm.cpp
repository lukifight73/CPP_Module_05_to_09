/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 5, 25), m_target("default Target")
{
	std::cout << "PresidentialPardonForm : Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 5, 25), m_target(target)
{
	std::cout << "PresidentialPardonForm : Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm("PresidentialPardonForm", 5, 25), m_target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &PresidentialPardonForm)
{
	o << "PresidentialPardonForm :" << std::endl << "Target : ";
	o << PresidentialPardonForm.getTarget() << " :" << std::endl;
	o << "Exec grade : " << PresidentialPardonForm.getGradeSig() << std::endl;
	o << "Sign grade : " << PresidentialPardonForm.getGradeExe() << std::endl;
	o << "Signed ? " << PresidentialPardonForm.getisSigned() << std::endl << std::endl;
	return (o);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getisSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() <= 5)
	{
		std::cout << executor.getName() << " executed " << "PresidentialPardonForm." << std::endl;
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

const std::string PresidentialPardonForm::getTarget(void)const
{
	return (this->m_target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}
