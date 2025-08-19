/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:55 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/16 13:13:41 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <vector>

class PmergeMe
{
	private:
	std::vector<std::vector<int> > _bordel;
	std::vector<std::vector<int> > _bordelv2;
	std::vector<std::vector<int> > _pend;
	std::vector<std::vector<int> > _main;
	std::vector<std::vector<int> > _useless;
	std::deque<std::deque<int> > _deque_bordel;
	std::deque<std::deque<int> > _deque_pend;
	std::deque<std::deque<int> > _deque_bordelv2;
	std::deque<std::deque<int> > _deque_main;
	std::deque<std::deque<int> > _deque_useless;
	char **_expression;
	int _nb_elements;
	int _deque_nb_elements;
	int _nb_vecteurs;
	int _indice;
	int _nb_comp;
	int _deque_nb_comp;
	int _deque_nb_vecteurs;

	public:

	PmergeMe();
	PmergeMe(char **expression, int ac);
	PmergeMe(const PmergeMe &copy);
	void fill_bordel_with_expression();
	void make_pairs();
	void console_sort_paired_sequence();
	void demake_pairs_2();
	void demake_pairs(int taille);
	bool check_2_meme_taille();
	void print_bordel();
	void putUselessInBordel();
	void sort_pend_main_useless();
	void sort_with_jacobsthal();
	void sort_binary(int i);
	void print_bilan(clock_t time);
	void setBordel(std::vector<std::vector<int> > bordel);
	int	getResult() const;
	void deque_fill_deque_bordel_with_expression();
	void deque_make_pairs();
	void deque_console_sort_paired_sequence();
	void deque_demake_pairs_2();
	void deque_demake_pairs(int taille);
	bool deque_check_2_meme_taille();
	void deque_print_bordel();
	void deque_putUselessInBordel();
	void deque_sort_pend_main_useless();
	void deque_sort_with_jacobsthal();
	void deque_sort_binary(int i);
	void deque_print_bilan(clock_t time);
	void deque_setBordel(std::deque<std::deque<int> > bordel);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();
};
