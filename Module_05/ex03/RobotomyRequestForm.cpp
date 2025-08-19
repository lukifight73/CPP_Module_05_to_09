/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>

static int robot_fail = 0;

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 45, 72), m_target("default Target")
{
	std::cout << "RobotomyRequestForm : Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 45, 72), m_target(target)
{
	std::cout << "RobotomyRequestForm : Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm("PresidentialPardonForm", 45, 72), m_target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getisSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() <= 45)
	{
		std::cout << executor.getName() << " executed " << "RobotomyRequestForm." << std::endl;
		std::cout << "Makes some drilling noises." << std::endl;
		if (robot_fail++ % 2)
			std::cout << this->getTarget() << " has been robotomized." << std::endl;
		else
			std::cout << "Robotomy failed." << std::endl;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &RobotomyRequestForm)
{
	o << "RobotomyRequestForm :" << std::endl << "Target : ";
	o << RobotomyRequestForm.getTarget() << " :" << std::endl;
	o << "Exec grade : " << RobotomyRequestForm.getGradeSig() << std::endl;
	o << "Sign grade : " << RobotomyRequestForm.getGradeExe() << std::endl;
	o << "Signed ? " << RobotomyRequestForm.getisSigned() << std::endl << std::endl;
	return (o);
}

const std::string RobotomyRequestForm::getTarget(void)const
{
	return (this->m_target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}
