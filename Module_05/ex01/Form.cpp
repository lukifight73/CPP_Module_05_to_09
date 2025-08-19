/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

Form::Form(): m_name("default Form"), m_grade_exe(150), m_grade_sig(150), m_signed(false)
{
	std::cout << "Form : Default constructor called." << std::endl;
}

Form::Form(std::string name): m_name(name), m_grade_exe(150), m_grade_sig(150), m_signed(false)
{
	std::cout << "Form : Name constructor called." << std::endl;
}

Form::Form(int grade_exe, int grade_sig): m_name("default Form"), m_grade_exe(grade_exe), m_grade_sig(grade_sig), m_signed(false)
{
	std::cout << "Form : grade exe & grade sig constructor called." << std::endl;
	if (this->getGradeExe() < 1 || this->getGradeSig() < 1)
		throw Form::GradeTooHighException();
	else if (this->getGradeExe() > 150 || this->getGradeSig() > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int grade_exe, int grade_sig): m_name(name), m_grade_exe(grade_exe), m_grade_sig(grade_sig), m_signed(false)
{
	std::cout << "Form : all constructor called." << std::endl;
	if (this->getGradeExe() < 1 || this->getGradeSig() < 1)
		throw Form::GradeTooHighException();
	else if (this->getGradeExe() > 150 || this->getGradeSig() > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy): m_name(copy.getName()), m_grade_exe(copy.getGradeExe()), m_grade_sig(copy.getGradeSig()), m_signed(false)
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = copy;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}
	return (*this);
}

const char *Form::GradeTooHighException::what(void)const throw()
{
	return ("Warning : grade too high.");
}

const char *Form::GradeTooLowException::what(void)const throw()
{
	return ("Warning : grade too low.");
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSig())
	{
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
		m_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &o, Form const &Form)
{
	o << "Form :" << std::endl;
	o << Form.getName() << " :" << std::endl;
	o << "Exec grade : " << Form.getGradeSig() << std::endl;
	o << "Sign grade : " << Form.getGradeExe() << std::endl;
	o << "Signed ? " << Form.getisSigned() << std::endl << std::endl;
	return (o);
}

const std::string Form::getName(void)const
{
	return (this->m_name);
}

int Form::getGradeSig(void)const
{
	return (m_grade_sig);
}

bool Form::getisSigned(void)const
{
	return (m_signed);
}

int Form::getGradeExe(void)const
{
	return (m_grade_exe);
}

Form::~Form()
{
	std::cout << "Form Destructor called." << std::endl;
}
