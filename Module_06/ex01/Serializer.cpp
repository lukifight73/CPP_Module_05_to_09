/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

Serializer::Serializer()
{
	std::cout << "Serializer Default constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = copy;
}

__intptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<__intptr_t>(ptr));
}

Data* Serializer::deserialize(__intptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{

	}
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor called." << std::endl;
}
