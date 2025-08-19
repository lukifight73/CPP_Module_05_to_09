/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/03 16:56:31 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> array;
	for (int i = 0; i < 20; i += 2)
		array.push_back(i);

	int j = easyfind(array, 3);
	if (j != -1)
		std::cout << "3 has been found in position " << j << " in the array" << std::endl;
	else
		std::cout << "3 has not been found in the array" << std::endl;\

	j = easyfind(array, 18);
	if (j != -1)
		std::cout << "18 has been found in position " << j << " in the array" << std::endl;
	else
		std::cout << "18 has not been found in the array" << std::endl;

	j = easyfind(array, 4);
	if (j != -1)
		std::cout << "4 has been found in position " << j << " in the array" << std::endl;
	else
		std::cout << "4 has not been found in the array" << std::endl;

	j = easyfind(array, 3);
	if (j != -1)
		std::cout << "28 has been found in position " << j << " in the array" << std::endl;
	else
		std::cout << "28 has not been found in the array" << std::endl;
	return (0);
}
