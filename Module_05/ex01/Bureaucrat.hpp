/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
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
#include "Form.hpp"

class Bureaucrat
{
	public:

	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(int i);
	Bureaucrat(std::string name, int i);
	Bureaucrat(int i, std::string name);
	Bureaucrat(const Bureaucrat &copy);
	void incrementGrade(void);
	void decrementGrade(void);
	Bureaucrat &operator=(const Bureaucrat &src);
	std::string getName(void)const;
	void signForm(Form m);

	int getGrade(void)const;
	~Bureaucrat();

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
	int	m_grade;
	void	setGrade(int grade);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &Bureaucrat);
