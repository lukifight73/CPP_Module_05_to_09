/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                       :+:      :+:    :+:   */
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

template < typename T >
class Array
{
	public:
	Array()
	{
		std::cout << "Default constructor called." << std::endl;
		m_size = 0;
		m_elements = new T[m_size];
	}
	Array(int n)
	{
		std::cout << "size constructor called." << std::endl;
		m_size = n;
		m_elements = new T[n];
	}
	Array(const Array &copy): m_size(copy.size())
	{
		std::cout << "Array Copy Constructor called" << std::endl;
		m_elements = NULL;
		*this = copy;
	}

	Array &operator=(const Array &src)
	{
		std::cout << "Array assignment operator called" << std::endl;
		if (this != &src)
		{
			delete [] this->m_elements;
			this->m_size = src.size();
			this->m_elements = new T[this->m_size];
			for (int i = 0; i < m_size; i++)
			{
				this->m_elements[i] = src.m_elements[i];
			}
		}
		return (*this);
	}

	T &operator[](int index)
	{
		if (index < 0 || index >= this->m_size || !this->m_elements)
		{
			std::cout << "index: " << index << std::endl;
			throw Array<T>::InvalidIndex();
		}
		return (m_elements[index]);
	}

	class	InvalidIndex : public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};

	int size(void)const
	{
		return (m_size);
	}

	~Array()
	{
		std::cout << "Array destructor operator called" << std::endl;
		if (this->m_elements)
			delete [] this->m_elements;
	}

	private:

	T *m_elements;
	int m_size;
};

template< typename T >
const char	*Array<T>::InvalidIndex::what() const throw()
{
	return ("Error: Invalid index");
}
