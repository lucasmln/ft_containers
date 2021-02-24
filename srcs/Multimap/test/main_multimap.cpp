/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_multimap.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:13:09 by lucas             #+#    #+#             */
/*   Updated: 2021/02/24 20:07:21 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Map_bidirectional_iterator.hpp"
#include "../includes/Map_reverse_bidirectional_iterator.hpp"
#include "../Multimap.hpp"
#include <iostream>

#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <cmath>

#ifndef MODE
# define MODE ft
#endif

#ifndef PAIR
# define PAIR Pair
#endif

bool fncomp (char lhs, char rhs) {return lhs>rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs>rhs;}
};

int main ()
{
{
	srand(time(NULL));

	MODE::multimap<char, int>				test;
	MODE::multimap<char, int>				test2;
	MODE::multimap<char, int>::iterator	ite;
	PAIR<char, int>					p;
	char							c = 'a';
	int								i = 1;

	std::cout << "Test with insert :\n\n";
	std::cout << "Add ten pair to multimap :\n";
	while (i <= 10)
	{
		std::cout  << "{" << c << "/" << i << "}" << " ";
		p.first = c++;
		p.second = i++;
		test.insert(p);
	}
	c = 'a';
	while (i > 0)
	{
		std::cout  << "{" << c << "/" << i << "}" << " ";
		p.first = c++;
		p.second = i--;
		test.insert(p);
	}
	std::cout << "size " << test.size() << std::endl;
	std::cout << std::endl;
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	ite = test.begin();
	ite++;
	ite++;
	ite++;
	std::cout << "\nAdd values in test2 with range iterator start to the fourth value of test :\n";
	test2.insert(ite, test.end());
	for (MODE::multimap<char, int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;

	std::cout << "\nAdd three first values of test in test2 with hint :\n";
	ite = test.begin();
	MODE::multimap<char, int>::iterator itt = test2.begin();
	for (int i = 0; i < 3; i++)
	{
		test2.insert(itt, *ite);
		ite++;
		itt = test2.begin();
		itt++;
	}
	for (MODE::multimap<char, int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;
}
/*
{
	MODE::multimap<char, int>				test;
	MODE::multimap<char, int>				test2;
	MODE::multimap<char, int>::iterator	ite;
	PAIR<char, int>					p;
	char	tab[] = "zhmegfncsxd";

	std::cout << "\nTest with insert :\n\n";
	std::cout << "Add eleven pair to multimap and key value 'z' :\n";

//	system("cat srcs/Map/test/tree.txt");
	std::cout << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout  << "{" << tab[i] << "/" << i + 1 << "}" << " ";
		p.first = tab[i];
		p.second = i + 1;
		test.insert(p);
	}
	std::cout << std::endl;

	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Erase node with one child at head. Value 'z'\n";
	test.erase('z');
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Erase leaf (No children) value 'd'\n";
	test.erase('d');
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Erase node with 2 children value 'e'\n";
	test.erase('e');
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Erase begin() value '" << test.begin()->first << "'" <<std::endl;
	test.erase(test.begin());
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	MODE::multimap<char, int>::iterator ender = test.end();
	ite = test.begin();
	ite++; ite++;
	ender--;
	ender--;
	ender--;
	std::cout << "Erase begin() +2(inclus) to end() -1(exclu) value. " << ite->first << " to " << ender->first << std::endl;
	test.erase(ite, ender);
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
	
	ender = test.end();
	ender--;
	std::cout << "Erase begin() to end() value. " << test.begin()->first << " to " <<
															ender->first << "(include)" << std::endl;
	test.erase(test.begin(), test.end());
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout  << "{" << tab[i] << "/" << i + 1 << "}" << " ";
		p.first = tab[i];
		p.second = i + 1;
		test.insert(p);
	}

	std::cout << std::endl;
	std::cout << "Reinsert the initial multimap value after erase all" << std::endl;
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
}

{
	std::cout << "\n\nTest with clear() :\n\n";

	MODE::multimap<char, int>				test;
	MODE::multimap<char, int>::iterator	ite;
	PAIR<char, int>					p;
	char	tab[] = "zhmegfncsxd";

	for (int i = 0; i < 11; i++)
	{
		std::cout  << "{" << tab[i] << "/" << i + 1 << "}" << " ";
		p.first = tab[i];
		p.second = i + 1;
		test.insert(p);
	}

	std::cout << std::endl;
	std::cout << "Value in order :" << std::endl;
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Clear the multimap, print value and size\n";
	test.clear();
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	for (int i = 0; i < 11; i++)
	{
		std::cout  << "{" << tab[i] << "/" << i + 1 << "}" << " ";
		p.first = tab[i];
		p.second = i + 1;
		test.insert(p);
	}

	std::cout << std::endl;
	std::cout << "Reinsert the initial multimap value after erase all" << std::endl;
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "\n\nTest with count :\n\n";
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	if (test.count('g'))
		std::cout << "g is in the multimap\n";
	else
		std::cout << "g is not in the multimap\n";

	if (test.count('-'))
		std::cout << "- is in the multimap\n";
	else
		std::cout << "- is not in the multimap\n";

	if (test.count('4'))
		std::cout << "4 is in the multimap\n";
	else
		std::cout << "4 is not in the multimap\n";

	if (test.count('z'))
		std::cout << "z is in the multimap\n";
	else
		std::cout << "z is not in the multimap\n";
	if (test.count('c'))
		std::cout << "c is in the multimap\n";
	else
		std::cout << "c is not in the multimap\n";

	MODE::multimap<char, int>				test2;
	MODE::multimap<char, int>::iterator	ender;
	MODE::multimap<char, int>::iterator	beginner;
	PAIR<char, int>		p2;

	std::cout << "\n\nTest with lower_bound, upper_bound, equal_rabge :\n\n";
	std::cout << "Value in multimap :\n";
	p2.first = 'a';
	p2.second = 20;
	test2.insert(p2);
	p2.first = 'b';
	p2.second = 40;
	test2.insert(p2);
	p2.first = 'c';
	p2.second = 60;
	test2.insert(p2);
	p2.first = 'd';
	p2.second = 80;
	test2.insert(p2);
	p2.first = 'e';
	p2.second = 100;
	test2.insert(p2);
	for (MODE::multimap<char, int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;

	ender = test2.upper_bound('d');
	beginner = test2.lower_bound('b');
	std::cout << "upper_bound('d') is " << ender->first << " lower_bound('b') is " << beginner->first << std::endl;
	std::cout << "Erased values between iterator return by lower/upper_bound\n";
	test2.erase(beginner, ender);
	for (MODE::multimap<char, int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;
}

{
	MODE::multimap<char,int> test;
	PAIR<char, int>		p2;

	p2.first = 'a';
	p2.second = 100;
	test.insert(p2);
	p2.first = 'b';
	p2.second = 20;
	test.insert(p2);
	p2.first = 'c';
	p2.second = 30;
	test.insert(p2);

	std::cout << "\nTest with equal_rang :\n\n";
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	PAIR<MODE::multimap<char,int>::iterator, MODE::multimap<char,int>::iterator> ret;
	std::cout << "equal_range('b')\n";
	ret = test.equal_range('b');

	std::cout << "first iterator point to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "second iterator point to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	std::cout << "\nTest with max_size :\n";

	std::cout << "Max_size : " << test.max_size() << std::endl;
}

{
	std::cout << "\nTest with operator = :\n";
	MODE::multimap<char, int>		test;
	MODE::multimap<char, int>		test2;
	PAIR<char, int>		p2;

	p2.first = 'h';
	p2.second = 15;
	test.insert(p2);
	p2.first = 'o';
	p2.second = 150;
	test.insert(p2);
	p2.first = 'e';
	p2.second = 98;
	test.insert(p2);
	p2.first = 't';
	p2.second = -65;
	test.insert(p2);
	p2.first = 'i';
	p2.second = 13;
	test.insert(p2);

	std::cout << "print test :\n";
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
	
	std::cout << "print test2 :\n";
	for (MODE::multimap<char, int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;

	std::cout << "Use tes2 = test && tes.clear() :\n";
	test2 = test;
	test.clear();
	std::cout << "print test :\n";
	for (MODE::multimap<char, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
	
	std::cout << "print test2 :\n";
	for (MODE::multimap<char, int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << it->first << "/" << it->second << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;
}
*/
/*
{
	std::multimap<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	
	std::cout << "before swap FOO contains:\n";
	for (std::multimap<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "before swap BAR contains:\n";
	for (std::multimap<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	foo.swap(bar);

	std::cout << "after swap FOO contains:\n";
	for (std::multimap<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "after swap BAR contains:\n";
	for (std::multimap<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
*/
/*
{
	std::cout << "\nTest with relational operators :\n\n";
	MODE::multimap<char,int> foo,bar;
	PAIR<char, int>		p2;
	p2.first = 'a';
	p2.second = 100;
	foo.insert(p2);
	p2.first = 'b';
	p2.second = 200;
	foo.insert(p2);
	p2.first = 'a';
	p2.second = 10;
	bar.insert(p2);
	p2.first = 'z';
	p2.second = 1000;
	bar.insert(p2);

	std::cout << "FOO contains:\n";
	for (MODE::multimap<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "BAR contains:\n";
	for (MODE::multimap<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}
*/
	return 0;
}
