/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:55 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:39 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class Intern
{
	public:

	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &src);
	AForm *makeForm(std::string name, std::string target);
	~Intern();

	class FormNameProvidedNotExist : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream	&operator<<(std::ostream &o, Intern const &Intern);
