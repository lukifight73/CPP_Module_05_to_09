/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:39 by lbenatar          #+#    #+#             */
/*   Updated: 2025/04/14 11:22:07 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

/*
int main()
{
std::list<int> mstack;
mstack.push_back(5);
mstack.push_back(17);
std::cout << *mstack.begin() << std::endl;
std::cout << mstack.size() << std::endl;
mstack.push_back(3);
mstack.push_back(5);
mstack.push_back(737);
//[...]
mstack.push_back(0);
std::list<int>::iterator it = mstack.begin();
std::list<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
return 0;
}*/

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << "top : " << mstack.top() << std::endl;
std::cout << "size avant pop: " << mstack.size() << std::endl;
mstack.pop();
std::cout << "size apres pop: " << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
std::cout << std::endl << "On liste sur les iterateurs : " << std::endl;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}
