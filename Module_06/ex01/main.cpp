/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/04 15:22:31 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data *a = new Data();
	Serializer b;
	__intptr_t c;
	Data *d;

	a->charra = 'c';
	a->ohohoh = 65;
	a->string = "youpiii";
	std::cout << a->charra << " / " << a->ohohoh << " / " << a->string << std::endl;
	c = b.serialize(a);
	d = b.deserialize(c);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << d->charra << " / " << d->ohohoh << " / " << d->string << std::endl;
	delete a;
	return (0);
}
