/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/07 12:09:30 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main( void )
{
	Array<int>yoyo;

	Array<int>yo(3);
	Array<std::string>ya;

	yo[0] = 1;
	yo[1] = 2;
	yo[2] = 3;

	try
	{
		std::cout << ya[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << ya.size() << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << yo[0] << " / " << yo[1] << " / " << yo[2] << std::endl;
	std::cout << yo.size() << std::endl;
	yoyo = yo;
	std::cout << "-------------------yoyo = yo--------------------------------" << std::endl;
	std::cout << yoyo[0] << " / " << yoyo[1] << " / " << yoyo[2] << std::endl;
	std::cout << yoyo.size() << std::endl;
	yoyo[1] = 18;
	try
	{
		yoyo[40] = 20;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "yoyo[1] = " << yoyo[1] << std::endl;
	std::cout << "yo[1] = " << yo[1] << std::endl;

	return 0;
}
