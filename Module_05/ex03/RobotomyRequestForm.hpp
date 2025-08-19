/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:55 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:39 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include <string>

class Bureaucrat;

class AForm;

class RobotomyRequestForm: public AForm
{
	public:

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);

	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	void execute(Bureaucrat const & executor) const;
	const std::string getTarget(void)const;
	~RobotomyRequestForm();

	private:

	const std::string m_target;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &RobotomyRequestForm);
