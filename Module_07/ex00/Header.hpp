/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                       :+:      :+:    :+:   */
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

template < typename T >
T const & max( T const & x, T const & y)
{
	return ( x >= y ? x : y);
}

template < typename T >
T const & min( T const & x, T const & y)
{
	return ( x <= y ? x : y);
}

template < typename T >
void swap( T & x, T & y)
{
	T z;

	z = x;
	x = y;
	y = z;
}
