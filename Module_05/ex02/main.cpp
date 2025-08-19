/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/02 15:08:45 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		AForm *b = new PresidentialPardonForm("default");
		std::cout << std::endl;

		std::cout << "Testing" << std::endl;
		std::cout << *a;
		std::cout << *b;

		try
		{
			b->beSigned(*a);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << *b;
		std::cout << std::endl;

		std::cout << "Deconstructing" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new PresidentialPardonForm("some dude");
		std::cout << std::endl;

		std::cout << "Testing" << std::endl;
		std::cout << *a;
		std::cout << *b;
		std::cout << *c;
		std::cout << std::endl;

		try
		{
			c->execute(*b);
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cerr << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->beSigned(*a);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << *c;
		std::cout << std::endl;
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << *c;
		std::cout << std::endl;

		std::cout << std::endl;
		b->signForm(*c);
		std::cout << std::endl;

		try
		{
			c->execute(*a);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;

		try
		{
			c->execute(*b);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Deconstructing" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << std::endl;

		std::cout << "Testing" << std::endl;
		std::cout << *a;
		std::cout << *b;
		std::cout << *c;
		b->beSigned(*a);
		std::cout << *b;
		b->execute(*a);

		std::cout << "YOOO" << std::endl;
		a->signForm(*c);
		std::cout << *c;
		a->executeForm(*c);
		std::cout << std::endl;

		std::cout << "Deconstructing" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("yoyoyoyo");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("Yo");
		std::cout << std::endl;

		std::cout << "Testing" << std::endl;
		std::cout << *a;
		std::cout << *b;
		std::cout << *c;
		b->beSigned(*a);
		a->signForm(*c);
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		c->execute(*a);
		std::cout << std::endl;

		std::cout << "Deconstructing" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	return (0);
}
