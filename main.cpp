/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:54:41 by lucas             #+#    #+#             */
/*   Updated: 2021/01/30 13:25:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

int main(int argc, const char *argv[])
{
	(void)argc;
	(void) argv;

	ft::Vector<int>		v1(12, 15);
	ft::Vector<int>::iterator	begin = v1.begin() + 3;
	ft::Vector<int>::iterator	end = v1.end();
	ft::Vector<int>	v2(begin, end);

	std::cout << "\t\tV2 :" << std::endl << std::endl;

	std::cout << "v2 size : " << v2.size() << std::endl;
	std::cout << "v2 value with i\n";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	std::cout << "v2 value with ite\n";
	for (ft::Vector<int>::iterator ite = v2.begin() ;ite != v2.end(); ite++)
		std::cout << *ite << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "\t\tV1 :" << std::endl << std::endl;

	std::cout << "v1 size : " << v1.size() << std::endl;
	std::cout << "v1 value with i\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
	std::cout << "v1 value with ite\n";
	for (ft::Vector<int>::iterator ite = v1.begin(); ite != v1.end(); ite++)
		std::cout << *ite << std::endl;
	return (0);
//	ft::Vector<int>		vect(ite + 3, v1.end());
//	std::vector<int>	v1(12, 15);
//	std::vector<int>		vect(v1.begin() + 3, v1.end());
/*
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << "value at " << i << " : " << vect[i] << std::endl;
	std::cout << "capacity : " << vect.capacity() << std::endl;
  vect.push_back(78);
	std::cout << "capacity : " << vect.capacity() << std::endl;
  vect.push_back(16);

  // now front equals 78, and back 16

  vect.front() -= vect.back();

  std::cout << "myvector.front() is now " << vect.front() << '\n';


	std::cout << "capacity : " << vect.capacity() << std::endl;
	vect.reserve(150);

	std::cout << "capacity : " << vect.capacity() << std::endl;
	std::cout << "value 9 & 13 : " << vect[9] << " & " << vect[13] << std::endl;
	std::cout << "end first\n\n";

	ft::Vector<int>		v2 = vect;
//	std::vector<int>		v2 = vect;
	vect[9] = 100;
	std::cout << "value vect1 after change 9 & 13 : " << vect[9] << " & " << vect[13] << std::endl;
	std::cout << "capacity : " << v2.capacity() << std::endl;
	std::cout << "value 9 & 13 : " << v2[9] << " & " << v2[13] << std::endl;
//	v2.clear();

//	std::vector<int>::iterator it = v2.begin();
	ft::Vector<int>::iterator it = v2.begin();
	it = v2.begin();
	std::cout << "capacity : " << v2[2] << std::endl;
	v2.push_back(16);
	*/return 0;
}
