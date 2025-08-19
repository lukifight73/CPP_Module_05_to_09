/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                       :+:      :+:    :+:   */
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

typedef struct Data
{
	int 	ohohoh;
	std::string string;
	char charra;
}			Data;

class Serializer
{
	public:

	Serializer();
	Serializer(const Serializer &copy);
	static __intptr_t serialize(Data* ptr);
	static Data* deserialize(__intptr_t raw);
	Serializer &operator=(const Serializer &src);
	~Serializer();
};
