/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_print.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/16 13:26:45 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

PmergeMe::PmergeMe()
{
	_expression = NULL;
	_nb_elements = 0;
	_indice = 0;
	_nb_comp = 0;
}

PmergeMe::PmergeMe(char **expression, int ac)
{
	_expression = expression;
	_nb_elements = ac - 1;
	_indice = 0;
	_nb_comp = 0;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	_expression = copy._expression;
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_expression = src._expression;
		*this = src;
	}
	return (*this);
}

void PmergeMe::fill_bordel_with_expression(void)
{
	if (!_expression)
		return ;
	int i = 1;
	while (i <= _nb_elements && _expression[i])
	{
		std::vector<int> elements;
		elements.push_back(atoi(_expression[i]));
		_bordel.push_back(elements);
		i++;
	}
	_bordelv2 = _bordel;
	_nb_vecteurs = _nb_elements;
}

void print_vecteur(std::vector<std::vector<int> > _bordel, std::string yo)
{
	int t = 0;
	int i = 0;
	int u;

	std::cout << "-------------------" << yo << "--------------------------" << std::endl;
	while (i < (int)_bordel.size())
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
}

void PmergeMe::print_bordel()
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

int	prochain_plus_petit(std::vector<std::vector<int> > _bordel, int taille)
{
	int i = 0;
	while (i < (int)_bordel.size())
	{
		if ((int)_bordel[i].size() < taille)
			return ((int)_bordel[i].size());
		i++;
	}
	return (taille);
}

void PmergeMe::demake_pairs(int taille)
{
	std::vector<std::vector<int> > bordel2;
	int number;
	int t_new_pairs;
	int t_nb_pairs;
	int l = 0;

	if (_bordel.size() > 1 && taille / 2 == prochain_plus_petit(_bordel, taille))
	{
		t_new_pairs = taille / 2;
		t_nb_pairs = 2;
	}
	else if (taille > 8)
	{
		t_new_pairs = _bordel[0].size() / 4;
		t_nb_pairs = 4;
	}
	else
	{
		t_new_pairs = taille / 2;
		t_nb_pairs = 2;
	}
	this->print_bordel();
	while ((int)_bordel.size() > l && (int)_bordel[l].size() == taille)
	{
		for (int i = 0 ; i < t_nb_pairs ; i++)
		{
			std::vector<int> elements;
			for (int j = i * t_new_pairs; j < (i * t_new_pairs) + t_new_pairs; j++)
			{
				number = _bordel[l][j];
				elements.push_back(number);
			}
			bordel2.push_back(elements);
		}
		l++;
	}
	this->print_bordel();
	while ((int)_bordel.size() > l && _bordel[l].size())
	{
		std::vector<int> elements;
		for (int j = 0; j < (int)_bordel[l].size(); j++)
		{
			number = _bordel[l][j];
			elements.push_back(number);
		}
		bordel2.push_back(elements);
		l++;
	}
	_bordel.clear();
	this->setBordel(bordel2);
	_nb_vecteurs = bordel2.size();
}

void PmergeMe::console_sort_paired_sequence()
{
	while (_bordel[0].size() > 1)
	{
		this->demake_pairs((int)_bordel[0].size());
		this->print_bordel();
		this->sort_pend_main_useless();
		this->print_bordel();
	}
}

void PmergeMe::demake_pairs_2(void)
{
	std::vector<std::vector<int> > bordel2;
	int number;

	int t = 1;
	int l = 0;
	while (_bordel[l].size() == 2)
	{
		for (int i = 0 ; i < 2 ; i++)
		{
			std::vector<int> elements;
			for (int j = i * t; j < (i * t) + t; j++)
			{
				number = _bordel[l][j];
				elements.push_back(number);
			}
			bordel2.push_back(elements);
		}
		l++;
	}
	if (!_bordel[l].empty() && _bordel[l].size() > bordel2[0].size())
	{
		for (int b = 0 ; b < 2 ; b++)
		{
			std::vector<int> elements;
			for (int j = b * t; j < (b * t) + t; j++)
			{
				number = _bordel[1][j];
				elements.push_back(number);
			}
			bordel2.push_back(elements);
		}
		l++;
	}
	while (_bordel[l].size())
	{
		std::vector<int> elements;
		for (int j = 0; j < (int)_bordel[l].size(); j++)
		{
			number = _bordel[l][j];
			elements.push_back(number);
		}
		bordel2.push_back(elements);
		l++;
	}
	this->print_bordel();
	_bordel.clear();
	this->setBordel(bordel2);
	_nb_vecteurs = bordel2.size();
}

void PmergeMe::print_bilan(clock_t start)
{
	std::cout << "Before \t:";
	int i = 0;
	while (i < (int)_bordelv2.size())
	{
		std::cout << " " << _bordelv2[i][0];
		i++;
	}
	std::cout << std::endl << "After \t:";
	i = 0;
	while (i < (int)_bordel.size())
	{
		std::cout << " " << _bordel[i][0];
		i++;
	}
	clock_t end = clock();
	double duration = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
    std::cout << std::endl << "Time to process a range of " << _nb_elements;
	std::cout << " elements with std::vector : " << duration << " ms." << std::endl;
}

bool is_not_fully_empty(std::vector<std::vector<int> > &_pend)
{
	int i = 0;

	while (i < (int)_pend.size())
	{
		if (!_pend[i].empty())
			return (true);
		i++;
	}
	return (false);
}

int Jacobsthal(int indice)
{
	if (indice == 0)
		return (0);
	else if (indice == 1)
		return (1);
	else
		return (Jacobsthal(indice - 1) + (2 * Jacobsthal(indice - 2)));
}

int combien_vaut_i(std::vector<std::vector<int> > &_pend)
{
	int jacobsthal;

	int j = 2;
	while (1)
	{
		jacobsthal = Jacobsthal(j);
		if ((int)_pend.size() > jacobsthal)
		{
			if (!_pend[jacobsthal].empty())
				return (jacobsthal);
		}
		int i = 0;
		while (i < (int)_pend.size() && i < jacobsthal)
		{
			if (!_pend[i].empty())
				return (i);
			i++;
		}
		j++;
	}
	return (j);
}

void PmergeMe::sort_binary(int i)
{
	int number;
	int t = _main[0].size();
	int j = _main.size() / 2;

	_nb_comp++;
	if (_pend[i][t - 1] > _main[j][t - 1])
	{
		j++;
		while (j < (int)_main.size() && _pend[i][t - 1] > _main[j][t - 1])
		{
			_nb_comp++;
			j++;
		}
		std::vector<int> elements;
		for (int g = 0; g < (int)_pend[i].size(); g++)
		{
			number = _pend[i][g];
			elements.push_back(number);
		}
		_main.insert(_main.begin() + j, elements);
		_pend[i].clear();
	}
	else if (_pend[i][t - 1] < _main[j][t - 1])
	{
		while (j >= 0 && _pend[i][t - 1] < _main[j][t - 1])
		{
			_nb_comp++;
			j--;
		}
		j++;
		std::vector<int> elements;
		for (int g = 0; g < (int)_pend[i].size(); g++)
		{
			number = _pend[i][g];
			elements.push_back(number);
		}
		_main.insert(_main.begin() + j, elements);
		_pend[i].clear();
	}
}

void PmergeMe::putUselessInBordel()
{
	int i = 0;
	int number;
	while (i < (int)_useless.size())
	{
		std::vector<int> elements;
		for (int g = 0; g < (int)_useless[i].size(); g++)
		{
			number = _useless[i][g];
			elements.push_back(number);
		}
		_bordel.push_back(elements);
		i++;
	}
}

void PmergeMe::sort_with_jacobsthal()
{
	int i;
	int t;

	std::cout << std::endl << "-----------" << "triage pend into main" << "----------" << std::endl;
	while (is_not_fully_empty(_pend))
	{
		i = combien_vaut_i(_pend);
		std::cout << std::endl << "Jacobsthal number : " << i << " / _pend[" << i <<  "] : ";
		t = _pend[i].size();
		for (int l = 0; l < t ; l++)
			std::cout << " [ " << _pend[i][l] << " ]";
		std::cout << std::endl;
		this->sort_binary(i);
		print_vecteur(_main, "_main");
		print_vecteur(_pend, "_pend");
		print_vecteur(_useless, "_useless");
	}
	_bordel = _main;
	_main.clear();
	this->putUselessInBordel();
	_useless.clear();
	_pend.clear();
}

void PmergeMe::sort_pend_main_useless()
{
	int number;
	std::size_t size = _bordel[0].size();
	std::vector<std::vector<int> > pend;
	std::vector<std::vector<int> > main;
	std::vector<std::vector<int> > useless;

	int i = 2;
	while ((int)_bordel.size() > i && !_bordel[i].empty() && _bordel[i].size() == _bordel[0].size())
	{
		std::vector<int> elements;
		for (int j = 0; j < (int)_bordel[i].size(); j++)
		{
			number = _bordel[i][j];
			elements.push_back(number);
		}
		pend.push_back(elements);
		_bordel[i].clear();
		i += 2;
	}
	i = 0;
	while (i < (int)_bordel.size())
	{
		if (_bordel[i].empty())
			i++;
		else if (_bordel[i].size() == size)
		{
			std::vector<int> elements;
			for (int j = 0; j < (int)_bordel[i].size(); j++)
			{
				number = _bordel[i][j];
				elements.push_back(number);
			}
			main.push_back(elements);
			_bordel[i].clear();
			i++;
		}
		else
			i++;
	}
	i = 0;
	while (i < (int)_bordel.size())
	{
		if (_bordel[i].empty())
			i++;
		else if (_bordel[i].size() < size)
		{
			std::vector<int> elements;
			for (int j = 0; j < (int)_bordel[i].size(); j++)
			{
				number = _bordel[i][j];
				elements.push_back(number);
			}
			useless.push_back(elements);
			_bordel[i].clear();
			i++;
		}
		else
			i++;
	}
	_useless = useless;
	_main = main;
	_pend = pend;
	std::cout << "----------------------------------------------------------------" << std::endl;
	print_vecteur(_main, "_main");
	print_vecteur(_pend, "_pend");
	print_vecteur(_useless, "_useless");
	std::cout << "----------------------------------------------------------------" << std::endl << std::endl;
	this->sort_with_jacobsthal();
}

void PmergeMe::setBordel(std::vector<std::vector<int> > bordel)
{
	_bordel = bordel;
}

bool PmergeMe::check_2_meme_taille()
{
	int t;
	int j;
	int i;
	int taille = _bordel.size();
	t = 0;
	while (t < taille)
	{
		i = _bordel[t].size();
		for (int l = t + 1 ; l < taille ; l++)
		{
			j = _bordel[l].size();
			if (i == j)
				return (true);
		}
		t++;
	}
	return (false);
}

void PmergeMe::make_pairs(void)
{
	int t = _bordel[0].size();
	int u;
	int nb;
	if (!_expression)
		return ;
	int i = 0;
	while (i < _nb_elements / 2)
	{
		if ((int)_bordel[i + 1].size() == t)
		{
			u = 0;
			while (u < t)
			{
				_bordel[i].push_back(_bordel[i + 1][u]);
				u++;
			}
			_nb_comp++;
			if (_bordel[i][t - 1] > _bordel[i][2 * t - 1])
			{
				u = 0;
				while (u < t)
				{
					nb = _bordel[i][u];
					_bordel[i][u] = _bordel[i][u + t];
					_bordel[i][u + t] = nb;
					u++;
				}
			}
			_bordel[i + 1].clear();
			for (int j = i + 1 ; j != _nb_vecteurs - 1 ; j++)
				_bordel[j].swap(_bordel[j + 1]);
			_bordel.pop_back();
			_nb_vecteurs--;
		}
		i++;
	}
	this->print_bordel();
	if (this->check_2_meme_taille())
		this->make_pairs();
}

PmergeMe::~PmergeMe()
{
}
