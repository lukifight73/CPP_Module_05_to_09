/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/04 14:59:07 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include <cstdlib>  // Pour rand() et srand()
#include <ctime>    // Pour time()

Base * generate(void)
{
	std::srand(std::time(0));
	int randomNumber = (std::rand() % 3) + 1;
	if (randomNumber == 1)
	{
		Base *b = new A;
		return (b);
	}
	else if (randomNumber == 2)
	{
		Base *b = new B;
		return (b);
	}
	else
	{
		Base *b = new C;
		return (b);
	}
}

void identify(Base* p)
{
	B* b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	A* a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		try
		{
			A& a = dynamic_cast<A&>(p);
			(void)a;
			std::cout << "A" << std::endl;
			return ;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
				return ;
			}
			catch(const std::exception& e)
			{
				return ;
			}
		}
	}
}

int main(void)
{
	Base *a = generate();

	identify(a);
	identify(*a);
	delete a;
	return (0);
}
