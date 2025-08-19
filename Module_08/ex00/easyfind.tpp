/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "easyfind.hpp"

template < typename T >

int easyfind(T &container, int number)
{
	typename T::iterator it;
	int rang;

	rang = 0;
	if (container.empty())
		return -1;
	for (it = container.begin() ; it != container.end() ; it++)
	{
		if (*it == number)
			return (rang);
		rang++;
	}
	return (-1);
}
