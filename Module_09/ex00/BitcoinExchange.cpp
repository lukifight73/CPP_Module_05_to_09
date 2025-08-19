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

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <list>

std::list<std::string> get_data(std::ifstream monFluxData)
{
	std::list<std::string> liste;

	std::string string;
	while (getline(monFluxData, string))
		liste.push_back(string);
	monFluxData.close();
	return (liste);
}

float	check_format(std::list<std::string>::iterator it)
{
	int annee;
	int mois;
	int jour;
	float value;

	std::string yo;
	yo = *it;
	if (yo == "date")
	{
		std::cout << "Error: Invalid Date" << std::endl;
		return (-1);
	}
	if (yo == "format")
	{
		std::cout << "Error: Invalid Format" << std::endl;
		return (-1);
	}
	if (yo == "value")
	{
		std::cout << "Error: Invalid Value" << std::endl;
		return (-1);
	}
	const char *uh = yo.c_str();
	while (!isalnum(*uh))
		uh++;
	annee = atoi(uh);
	uh += 5;
	mois = atoi(uh);
	uh += 3;
	jour = atoi (uh);
	uh += 2;
	while (*uh && !isdigit(*uh) && *uh != '-')
		uh++;
	value = strtof(uh, NULL);
	if (!isdigit(*uh))
	{
		std::cout << "Error: Invalid Value : No Value" << std::endl;
		return (-1);
	}
	if (annee < 2009 || annee > 2025)
	{
		std::cout << "Error: Invalid Date : " << annee << "-" << mois << "-" << jour << std::endl;
		return (-1);
	}
	if (mois < 1 || mois > 12 || jour < 1 || jour > 31)
	{
		std::cout << "Error: Invalid Date : " << annee << "-" << mois << "-" << jour << std::endl;
		return (-1);
	}
	if (value < 0 || value > 1000)
	{
		std::cout << "Error: Invalid Value : " << value << std::endl;
		return (-1);
	}
	return (value);
}

float get_taux_change(std::list<std::string>::iterator it, std::list<std::string> liste_data)
{
	std::string yo;
	std::string ya;
	std::string yu;
	std::string yi;
	yo = *it;

	for (int i = 10 ; i > 0 ; i--)
	{
		ya = yo.substr(0, i);
		//std::cout << "yo : " << yo << std::endl;
		for (std::list<std::string>::iterator it_data = liste_data.begin() ; it_data != liste_data.end() ; it_data++)
		{
			yi = *it_data;
			yu = yi.substr(0, i);
			//std::cout << "yu : " << yu << std::endl;
			//std::cout << "yi : " << yi << std::endl;
			//std::cout << "ya : " << ya << std::endl;
			if (ya == yu)
			{
				yi = yi.substr(11);
				return (strtof(yi.c_str(), NULL));
			}
		}
	}
	return (-1);
}

void	write_what_is_needed(std::list<std::string> liste_data, std::list<std::string> liste)
{
	std::list<std::string>::iterator it = liste.begin();
	float	value;
	float	taux_change;
	std::string yu;
	std::string yi;

	it++;
	while (it != liste.end())
	{
		value = check_format(it);
		if (value != -1)
		{
			taux_change = get_taux_change(it, liste_data);
			//std::cout << taux_change << std::endl;
			yi = *it;
			yu = yi.substr(0, 10);
			std::cout << yu << " => " << value << " = " << value * taux_change << std::endl;
		}
		it++;
	}
}



