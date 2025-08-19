/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                       :+:      :+:    :+:   */
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
#include <list>
#include <fstream>

float	check_format(std::list<std::string>::iterator it);
float get_taux_change(std::list<std::string>::iterator it, std::list<std::string> liste_data);
std::list<std::string> get_data(std::ifstream monFluxData);
void	write_what_is_needed(std::list<std::string> liste_data, std::list<std::string> liste);

