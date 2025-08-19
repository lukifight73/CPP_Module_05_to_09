/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                       :+:      :+:    :+:   */
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
#include <stack>

class RPN
{
	private:
	std::stack<int> _pile;
	const char *_expression;
	int	_result;

	public:

	RPN();
	RPN(const char *expression);
	RPN(const RPN &copy);
	void treat_expression();
	int	getResult() const;
	RPN &operator=(const RPN &src);
	~RPN();
};
