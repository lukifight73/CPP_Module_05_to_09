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

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>

class Span
{
	private:
	int _N;
	std::vector<int> _array;

	public:
	Span();
	Span(unsigned int N);
	Span(const Span &src);
	Span &operator=(const Span &src);
	void addNumber(int number);
	long int shortestSpan();
	long int longestSpan();
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	~Span();

	class ArrayIsAlreadyFull : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class CannotFindSpan : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif
