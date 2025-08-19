/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/16 13:33:58 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "PmergeMe.hpp"

void print_bordel(std::vector<std::vector<int> > _bordel)
{
	int t = 0;
	int i = 0;
	int u;

	std::cout << std::endl << "---------------------------------------------" << std::endl;
	while (i < (int)_bordel.size() && !_bordel[i].empty())
	{
		t = _bordel[i].size();
		std::cout << i << " (size: " << t << ") \t: ";
		u = 0;
		while (u < t)
		{
			std::cout << " [ " << _bordel[i][u] << " ]";
			u++;
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl << std::endl;
}

bool parsing_entry(char **av)
{
	int i = 1;
	int j = 0;

	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cout << "Error: Wrong number of parameters" << std::endl;
		return (1);
	}
	if (!parsing_entry(av))
	{
		std::cout << "Error: Wrong parameters" << std::endl;
		return (1);
	}
	clock_t start = clock();
	PmergeMe yo(av, ac);
	yo.fill_bordel_with_expression();
	yo.make_pairs();
	yo.console_sort_paired_sequence();
	yo.print_bilan(start);
	start = clock();
	yo.deque_fill_deque_bordel_with_expression();
	yo.deque_make_pairs();
	yo.deque_console_sort_paired_sequence();
	yo.deque_print_bilan(start);
	return (0);
}
