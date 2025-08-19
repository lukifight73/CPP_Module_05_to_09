/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/16 14:33:02 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

void print_echantillon(std::list<std::string> liste_echantillon)
{
	std::cout << "-----------------------echantillon-------------------------" << std::endl;
	for (std::list<std::string>::iterator it = liste_echantillon.begin() ; it != liste_echantillon.end() ; it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void parsing_echantillon(std::list<std::string> &liste_echantillon)
{
	int indice = 0;
	int l;
	std::list<std::string> liste_echantillon2;

	for (std::list<std::string>::iterator it = liste_echantillon.begin() ; it != liste_echantillon.end() ; it++)
	{
		indice = 0;
		std::string yo;
		yo = *it;
		int j = 0;
		while (yo[j] && !isdigit(yo[j]))
		{
			yo.erase(j, 1);
		}
		l = j + 4;
		while (!indice && j < l)
		{
			if (!yo[j] || !isdigit(yo[j]))
			{
				yo = "date";
				indice = 1;
			}
			j++;
		}
		if (!yo[j] || (!indice && (yo[j] != '-')))
			yo = "date";
		j++;
		l = j + 2;
		while (!indice && j < l)
		{
			if (!yo[j] || !isdigit(yo[j]))
			{
				yo = "date";
				indice = 1;
			}
			j++;
		}
		if (!yo[j] || (!indice && (yo[j] != '-')))
			yo = "date";
		j++;
		l = j + 2;
		while (!indice && j < l)
		{
			if (!yo[j] || !isdigit(yo[j]))
			{
				yo = "date";
				indice = 1;
			}
			j++;
		}
		if (!indice && yo[j] && (yo[j] == ' '))
			j++;
		else if (!indice && !yo[j])
		{
			yo = "format";
			indice = 1;
		}
		while (!indice && yo[j] && (yo[j] != '|'))
			yo.erase(j, 1);
		j++;
		if (!indice && yo[j] && (yo[j] == ' '))
			j++;
		else if (!indice)
		{
			yo = "format";
			indice = 1;
		}
		while (!indice && yo[j] && !isdigit(yo[j]))
		{
			if (yo[j] == '-')
				yo = "value";
			else
				yo.erase(j, 1);
			j++;
		}
		liste_echantillon2.push_back(yo);
	}
	liste_echantillon = liste_echantillon2;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	std::ifstream monFlux(av[1]);
	std::ifstream monFluxData("./data.csv");
	if (!monFlux)
		std::cout << "ERREUR: Impossible d'ouvrir le fichier '" << av[1] << "' en lecture." << std::endl;
	if (!monFluxData)
		std::cout << "ERREUR: Impossible d'ouvrir le fichier contenant les datas." << std::endl;
	std::list<std::string> liste_data;
	std::list<std::string> liste_echantillon;
	std::string string;
	while (getline(monFluxData, string))
		liste_data.push_back(string);
	while (getline(monFlux, string))
		liste_echantillon.push_back(string);
	parsing_echantillon(liste_echantillon);
	monFluxData.close();
	monFlux.close();
	write_what_is_needed(liste_data, liste_echantillon);
	return (0);
}
