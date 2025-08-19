/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

AForm::AForm(): m_name("default AForm"), m_grade_exe(150), m_grade_sig(150), m_signed(false)
{
	std::cout << "AForm : Default constructor called." << std::endl;
}

AForm::AForm(std::string name): m_name(name), m_grade_exe(150), m_grade_sig(150), m_signed(false)
{
	std::cout << "AForm : Name constructor called." << std::endl;
}

AForm::AForm(int grade_exe, int grade_sig): m_name("default AForm"), m_grade_exe(grade_exe), m_grade_sig(grade_sig), m_signed(false)
{
	std::cout << "AForm : grade exe & grade sig constructor called." << std::endl;
	if (this->getGradeExe() < 1 || this->getGradeSig() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getGradeExe() > 150 || this->getGradeSig() > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int grade_exe, int grade_sig): m_name(name), m_grade_exe(grade_exe), m_grade_sig(grade_sig), m_signed(false)
{
	std::cout << "AForm : all constructor called." << std::endl;
	if (this->getGradeExe() < 1 || this->getGradeSig() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getGradeExe() > 150 || this->getGradeSig() > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy): m_name(copy.getName()), m_grade_exe(copy.getGradeExe()), m_grade_sig(copy.getGradeSig()), m_signed(false)
{
	std::cout << "AForm Copy Constructor called" << std::endl;
	*this = copy;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}
	return (*this);
}

const char *AForm::GradeTooHighException::what(void)const throw()
{
	return ("Warning : grade too high.");
}

const char *AForm::GradeTooLowException::what(void)const throw()
{
	return ("Warning : grade too low.");
}

const char *AForm::FormNotSignedException::what(void)const throw()
{
	return ("Warning : Form not signed.");
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSig())
	{
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
		m_signed = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &o, AForm const &AForm)
{
	o << "AForm :" << std::endl;
	o << AForm.getName() << " :" << std::endl;
	o << "Exec grade : " << AForm.getGradeSig() << std::endl;
	o << "Sign grade : " << AForm.getGradeExe() << std::endl;
	o << "Signed ? " << AForm.getisSigned() << std::endl << std::endl;
	return (o);
}

const std::string AForm::getName(void)const
{
	return (this->m_name);
}

int AForm::getGradeSig(void)const
{
	return (m_grade_sig);
}

bool AForm::getisSigned(void)const
{
	return (m_signed);
}

int AForm::getGradeExe(void)const
{
	return (m_grade_exe);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called." << std::endl;
}
