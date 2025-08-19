/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/01 11:27:51 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"


int main( void )
{
	Bureaucrat i;
	Bureaucrat v("mark");
	try
	{
		Bureaucrat j(0, "ju");
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat l("philippe", 151);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat d(149, "le K");
	Bureaucrat u("le L", 2);

	std::cout << v << i << d << u << std::endl;
	d.decrementGrade();
	std::cout << d << std::endl;
	u.incrementGrade();
	std::cout << u << std::endl;
	try
	{
		u.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		d.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
}
