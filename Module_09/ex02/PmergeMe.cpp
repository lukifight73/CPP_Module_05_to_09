/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/16 14:22:38 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <deque>

PmergeMe::PmergeMe()
{
	_expression = NULL;
	_nb_elements = 0;
	_indice = 0;
	_nb_comp = 0;
	_deque_nb_comp = 0;
}

PmergeMe::PmergeMe(char **expression, int ac)
{
	_expression = expression;
	_nb_elements = ac - 1;
	_deque_nb_elements = 0;
	_indice = 0;
	_nb_comp = 0;
	_deque_nb_comp = 0;
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
		this->sort_pend_main_useless();
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
	else if (_pend[i][t - 1] == _main[j][t - 1])
	{
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

	while (is_not_fully_empty(_pend))
	{
		i = combien_vaut_i(_pend);
		t = _pend[i].size();
		this->sort_binary(i);
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
	if (this->check_2_meme_taille())
		this->make_pairs();
}


//#########################################################################################################################################################

void PmergeMe::deque_fill_deque_bordel_with_expression(void)
{
	if (!_expression)
		return ;
	int i = 1;
	while (i <= _nb_elements && _expression[i])
	{
		std::deque<int> elements;
		elements.push_back(atoi(_expression[i]));
		_deque_bordel.push_back(elements);
		i++;
	}
	_deque_bordelv2 = _deque_bordel;
	_deque_nb_vecteurs = _nb_elements;
}

void PmergeMe::deque_print_bordel()
{
	int t = 0;
	int i = 0;
	int u;

	std::cout << std::endl << "---------------------------------------------" << std::endl;
	while (i < (int)_deque_bordel.size() && !_deque_bordel[i].empty())
	{
		t = _deque_bordel[i].size();
		std::cout << i << " (size: " << t << ") \t: ";
		u = 0;
		while (u < t)
		{
			std::cout << " [ " << _deque_bordel[i][u] << " ]";
			u++;
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl << std::endl;
}

int	deque_prochain_plus_petit(std::deque<std::deque<int> > _deque_bordel, int taille)
{
	int i = 0;
	while (i < (int)_deque_bordel.size())
	{
		if ((int)_deque_bordel[i].size() < taille)
			return ((int)_deque_bordel[i].size());
		i++;
	}
	return (taille);
}

void PmergeMe::deque_demake_pairs(int taille)
{
	std::deque<std::deque<int> > dequebordel2;
	int number;
	int t_new_pairs;
	int t_nb_pairs;
	int l = 0;

	if (_deque_bordel.size() > 1 && taille / 2 == deque_prochain_plus_petit(_deque_bordel, taille))
	{
		t_new_pairs = taille / 2;
		t_nb_pairs = 2;
	}
	else if (taille > 8)
	{
		t_new_pairs = _deque_bordel[0].size() / 4;
		t_nb_pairs = 4;
	}
	else
	{
		t_new_pairs = taille / 2;
		t_nb_pairs = 2;
	}
	while ((int)_deque_bordel.size() > l && (int)_deque_bordel[l].size() == taille)
	{
		for (int i = 0 ; i < t_nb_pairs ; i++)
		{
			std::deque<int> elements;
			for (int j = i * t_new_pairs; j < (i * t_new_pairs) + t_new_pairs; j++)
			{
				number = _deque_bordel[l][j];
				elements.push_back(number);
			}
			dequebordel2.push_back(elements);
		}
		l++;
	}
	while ((int)_deque_bordel.size() > l && _deque_bordel[l].size())
	{
		std::deque<int> elements;
		for (int j = 0; j < (int)_deque_bordel[l].size(); j++)
		{
			number = _deque_bordel[l][j];
			elements.push_back(number);
		}
		dequebordel2.push_back(elements);
		l++;
	}
	_deque_bordel.clear();
	this->deque_setBordel(dequebordel2);
	_deque_nb_vecteurs = dequebordel2.size();
}

void PmergeMe::deque_console_sort_paired_sequence()
{
	while (_deque_bordel[0].size() > 1)
	{
		this->deque_demake_pairs((int)_deque_bordel[0].size());
		this->deque_sort_pend_main_useless();
	}
}

void PmergeMe::deque_demake_pairs_2(void)
{
	std::deque<std::deque<int> > dequebordel2;
	int number;

	int t = 1;
	int l = 0;
	while (_deque_bordel[l].size() == 2)
	{
		for (int i = 0 ; i < 2 ; i++)
		{
			std::deque<int> elements;
			for (int j = i * t; j < (i * t) + t; j++)
			{
				number = _deque_bordel[l][j];
				elements.push_back(number);
			}
			dequebordel2.push_back(elements);
		}
		l++;
	}
	if (!_deque_bordel[l].empty() && _deque_bordel[l].size() > dequebordel2[0].size())
	{
		for (int b = 0 ; b < 2 ; b++)
		{
			std::deque<int> elements;
			for (int j = b * t; j < (b * t) + t; j++)
			{
				number = _deque_bordel[1][j];
				elements.push_back(number);
			}
			dequebordel2.push_back(elements);
		}
		l++;
	}
	while (_deque_bordel[l].size())
	{
		std::deque<int> elements;
		for (int j = 0; j < (int)_deque_bordel[l].size(); j++)
		{
			number = _deque_bordel[l][j];
			elements.push_back(number);
		}
		dequebordel2.push_back(elements);
		l++;
	}
	_deque_bordel.clear();
	this->deque_setBordel(dequebordel2);
	_deque_nb_vecteurs = dequebordel2.size();
}

void PmergeMe::deque_print_bilan(clock_t start)
{
	clock_t end = clock();
	double duration = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << _nb_elements;
	std::cout << " elements with std::deque : " << duration << " ms." << std::endl;
	std::cout << "Number of comparaisons : " << _deque_nb_comp << "." << std::endl;
}

bool deque_is_not_fully_empty(std::deque<std::deque<int> > &_deque_pend)
{
	int i = 0;

	while (i < (int)_deque_pend.size())
	{
		if (!_deque_pend[i].empty())
			return (true);
		i++;
	}
	return (false);
}

int deque_Jacobsthal(int indice)
{
	if (indice == 0)
		return (0);
	else if (indice == 1)
		return (1);
	else
		return (Jacobsthal(indice - 1) + (2 * Jacobsthal(indice - 2)));
}

int deque_combien_vaut_i(std::deque<std::deque<int> > &_deque_pend)
{
	int jacobsthal;

	int j = 2;
	while (1)
	{
		jacobsthal = Jacobsthal(j);
		if ((int)_deque_pend.size() > jacobsthal)
		{
			if (!_deque_pend[jacobsthal].empty())
				return (jacobsthal);
		}
		int i = 0;
		while (i < (int)_deque_pend.size() && i < jacobsthal)
		{
			if (!_deque_pend[i].empty())
				return (i);
			i++;
		}
		j++;
	}
	return (j);
}

void PmergeMe::deque_sort_binary(int i)
{
	int number;
	int t = _deque_main[0].size();
	int j = _deque_main.size() / 2;

	_deque_nb_comp++;
	if (_deque_pend[i][t - 1] > _deque_main[j][t - 1])
	{
		j++;
		while (j < (int)_deque_main.size() && _deque_pend[i][t - 1] > _deque_main[j][t - 1])
		{
			_deque_nb_comp++;
			j++;
		}
		std::deque<int> elements;
		for (int g = 0; g < (int)_deque_pend[i].size(); g++)
		{
			number = _deque_pend[i][g];
			elements.push_back(number);
		}
		_deque_main.insert(_deque_main.begin() + j, elements);
		_deque_pend[i].clear();
	}
	else if (_deque_pend[i][t - 1] < _deque_main[j][t - 1])
	{
		while (j >= 0 && _deque_pend[i][t - 1] < _deque_main[j][t - 1])
		{
			_deque_nb_comp++;
			j--;
		}
		j++;
		std::deque<int> elements;
		for (int g = 0; g < (int)_deque_pend[i].size(); g++)
		{
			number = _deque_pend[i][g];
			elements.push_back(number);
		}
		_deque_main.insert(_deque_main.begin() + j, elements);
		_deque_pend[i].clear();
	}
	else if (_deque_pend[i][t - 1] == _deque_main[j][t - 1])
	{
		std::deque<int> elements;
		for (int g = 0; g < (int)_deque_pend[i].size(); g++)
		{
			number = _deque_pend[i][g];
			elements.push_back(number);
		}
		_deque_main.insert(_deque_main.begin() + j, elements);
		_deque_pend[i].clear();
	}
}

void PmergeMe::deque_putUselessInBordel()
{
	int i = 0;
	int number;
	while (i < (int)_deque_useless.size())
	{
		std::deque<int> elements;
		for (int g = 0; g < (int)_deque_useless[i].size(); g++)
		{
			number = _deque_useless[i][g];
			elements.push_back(number);
		}
		_deque_bordel.push_back(elements);
		i++;
	}
}

void PmergeMe::deque_sort_with_jacobsthal()
{
	int i;
	int t;

	while (deque_is_not_fully_empty(_deque_pend))
	{
		i = deque_combien_vaut_i(_deque_pend);
		t = _deque_pend[i].size();
		this->deque_sort_binary(i);
	}
	_deque_bordel = _deque_main;
	_deque_main.clear();
	this->deque_putUselessInBordel();
	_deque_useless.clear();
	_deque_pend.clear();
}

void PmergeMe::deque_sort_pend_main_useless()
{
	int number;
	std::size_t size = _deque_bordel[0].size();
	std::deque<std::deque<int> > pend;
	std::deque<std::deque<int> > main;
	std::deque<std::deque<int> > useless;

	int i = 2;
	while ((int)_deque_bordel.size() > i && !_deque_bordel[i].empty() && _deque_bordel[i].size() == _deque_bordel[0].size())
	{
		std::deque<int> elements;
		for (int j = 0; j < (int)_deque_bordel[i].size(); j++)
		{
			number = _deque_bordel[i][j];
			elements.push_back(number);
		}
		pend.push_back(elements);
		_deque_bordel[i].clear();
		i += 2;
	}
	i = 0;
	while (i < (int)_deque_bordel.size())
	{
		if (_deque_bordel[i].empty())
			i++;
		else if (_deque_bordel[i].size() == size)
		{
			std::deque<int> elements;
			for (int j = 0; j < (int)_deque_bordel[i].size(); j++)
			{
				number = _deque_bordel[i][j];
				elements.push_back(number);
			}
			main.push_back(elements);
			_deque_bordel[i].clear();
			i++;
		}
		else
			i++;
	}
	i = 0;
	while (i < (int)_deque_bordel.size())
	{
		if (_deque_bordel[i].empty())
			i++;
		else if (_deque_bordel[i].size() < size)
		{
			std::deque<int> elements;
			for (int j = 0; j < (int)_deque_bordel[i].size(); j++)
			{
				number = _deque_bordel[i][j];
				elements.push_back(number);
			}
			useless.push_back(elements);
			_deque_bordel[i].clear();
			i++;
		}
		else
			i++;
	}
	_deque_useless = useless;
	_deque_main = main;
	_deque_pend = pend;
	this->deque_sort_with_jacobsthal();
}

void PmergeMe::deque_setBordel(std::deque<std::deque<int> > bordel)
{
	_deque_bordel = bordel;
}

bool PmergeMe::deque_check_2_meme_taille()
{
	int t;
	int j;
	int i;
	int taille = _deque_bordel.size();
	t = 0;
	while (t < taille)
	{
		i = _deque_bordel[t].size();
		for (int l = t + 1 ; l < taille ; l++)
		{
			j = _deque_bordel[l].size();
			if (i == j)
				return (true);
		}
		t++;
	}
	return (false);
}

void PmergeMe::deque_make_pairs(void)
{
	int t = _deque_bordel[0].size();
	int u;
	int nb;
	if (!_expression)
		return ;
	int i = 0;
	while (i < _nb_elements / 2)
	{
		if ((int)_deque_bordel[i + 1].size() == t)
		{
			u = 0;
			while (u < t)
			{
				_deque_bordel[i].push_back(_deque_bordel[i + 1][u]);
				u++;
			}
			_deque_nb_comp++;
			if (_deque_bordel[i][t - 1] > _deque_bordel[i][2 * t - 1])
			{
				u = 0;
				while (u < t)
				{
					nb = _deque_bordel[i][u];
					_deque_bordel[i][u] = _deque_bordel[i][u + t];
					_deque_bordel[i][u + t] = nb;
					u++;
				}
			}
			_deque_bordel[i + 1].clear();
			for (int j = i + 1 ; j != _deque_nb_vecteurs - 1 ; j++)
				_deque_bordel[j].swap(_deque_bordel[j + 1]);
			_deque_bordel.pop_back();
			_deque_nb_vecteurs--;
		}
		i++;
	}
	if (this->deque_check_2_meme_taille())
		this->deque_make_pairs();
}

PmergeMe::~PmergeMe()
{
}
