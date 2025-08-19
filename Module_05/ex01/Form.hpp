/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:55 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:39 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:

	Form();
	Form(std::string name);
	Form(int i, int j);
	Form(std::string name, int i, int j);
	Form(const Form &copy);
	Form &operator=(const Form &src);
	const std::string getName(void)const;
	int getGradeSig(void)const;
	int getGradeExe(void)const;
	bool getisSigned(void)const;
	void beSigned(Bureaucrat &b);
	~Form();

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	private:

	const std::string m_name;
	const int	m_grade_exe;
	const int	m_grade_sig;
	bool m_signed;
};

std::ostream	&operator<<(std::ostream &o, Form const &Form);
