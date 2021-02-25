/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:13:09 by lucas             #+#    #+#             */
/*   Updated: 2021/02/25 19:18:29 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Set.hpp"
#include <iostream>

#include <iostream>
#include <list>
#include <set>
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

	MODE::set<int>				test;
	MODE::set<int>				test2;
	MODE::set<int>::iterator	ite;
	char							c = 'a';
	int								i = 1;

	std::cout << "Test with insert :\n\n";
	std::cout << "Add ten pair to set :\n";
	while (i <= 10)
	{
		std::cout  << "{" << c << "/" << i << "}" << " ";
		test.insert(i++);
	}
	std::cout << "size " << test.size() << std::endl;
	std::cout << std::endl;
	for (MODE::set<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	ite = test.begin();
	ite++;
	ite++;
	ite++;
	std::cout << "\nAdd values in test2 with range iterator start to the fourth value of test :\n";
	test2.insert(ite, test.end());
	for (MODE::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;

	std::cout << "\nAdd three first values of test in test2 with hint :\n";
	ite = test.begin();
	MODE::set<int>::iterator itt = test2.begin();
	for (int i = 0; i < 3; i++)
	{
		test2.insert(itt, *ite);
		ite++;
		itt = test2.begin();
		itt++;
	}
	for (MODE::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;
}

{
	MODE::set<char>				test;
	MODE::set<char>				test2;
	MODE::set<char>::iterator	ite;
	char	tab[] = "zhmegfncsxd";

	std::cout << "\nTest with insert :\n\n";
	std::cout << "Add eleven pair to set and key value 'z' :\n";

	std::cout << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout  << "{" << tab[i] << "/" << i + 1 << "}" << " ";
		test.insert(tab[i]);
	}
	std::cout << std::endl;

	for (MODE::set<char>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Erase node with one child at head. Value 'z'\n";
	test.erase('z');
	for (MODE::set<char>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Erase leaf (No children) value 'd'\n";
	test.erase('d');
	for (MODE::set<char>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Erase node with 2 children value 'e'\n";
	test.erase('e');
	for (MODE::set<char>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Erase begin() value '" << *(test.begin()) << "'" <<std::endl;
	test.erase(test.begin());
	for (MODE::set<char>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	MODE::set<char>::iterator ender = test.end();
	ite = test.begin();
	ite++; ite++;
	ender--;
	ender--;
	ender--;
	std::cout << "Erase begin() +2(inclus) to end() -1(exclu) value. " << *ite << " to " << *ender << std::endl;
	test.erase(ite, ender);
	for (MODE::set<char>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
	
	ender = test.end();
	ender--;
	std::cout << "Erase begin() to end() value. " << *(test.begin()) << " to " <<
															*(ender) << "(include)" << std::endl;
	test.erase(test.begin(), test.end());
	for (MODE::set<char>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout  << "{" << tab[i] << "/" << i + 1 << "}" << " ";
		test.insert(tab[i]);
	}

	std::cout << std::endl;
	std::cout << "Reinsert the initial set value after erase all" << std::endl;
	for (MODE::set<char>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
}

{
	std::cout << "\n\nTest with clear() :\n\n";

	MODE::set<int>				test;
	MODE::set<int>::iterator	ite;
	PAIR<char, int>					p;
	char	tab[] = "zhmegfncsxd";

	for (int i = 0; i < 11; i++)
	{
		std::cout  << "{" << tab[i] << "/" << i + 1 << "}" << " ";
		test.insert(tab[i]);
	}

	std::cout << std::endl;
	std::cout << "Value in order :" << std::endl;
	for (MODE::set<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "Clear the set, print value and size\n";
	test.clear();
	for (MODE::set<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	for (int i = 0; i < 11; i++)
	{
		std::cout  << "{" << tab[i] << "/" << i + 1 << "}" << " ";
		test.insert(tab[i]);
	}

	std::cout << std::endl;
	std::cout << "Reinsert the initial set value after erase all" << std::endl;
	for (MODE::set<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	std::cout << "\n\nTest with count :\n\n";
	for (MODE::set<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;

	if (test.count('g'))
		std::cout << "g is in the set\n";
	else
		std::cout << "g is not in the set\n";

	if (test.count('-'))
		std::cout << "- is in the set\n";
	else
		std::cout << "- is not in the set\n";

	if (test.count('4'))
		std::cout << "4 is in the set\n";
	else
		std::cout << "4 is not in the set\n";

	if (test.count('z'))
		std::cout << "z is in the set\n";
	else
		std::cout << "z is not in the set\n";
	if (test.count('c'))
		std::cout << "c is in the set\n";
	else
		std::cout << "c is not in the set\n";

	MODE::set<int>				test2;
	MODE::set<int>::iterator	ender;
	MODE::set<int>::iterator	beginner;

	std::cout << "\n\nTest with lower_bound, upper_bound, equal_rabge :\n\n";
	std::cout << "Value in set :\n";
	test2.insert(20);
	test2.insert(-30);
	test2.insert(200);
	test2.insert(80);
	test2.insert(10);
	test2.insert(40);
	for (MODE::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;

	ender = test2.upper_bound('d');
	beginner = test2.lower_bound('b');
	std::cout << "upper_bound('d') is " << *(ender) << " lower_bound('b') is " << *(beginner) << std::endl;
	std::cout << "Erased values between iterator return by lower/upper_bound\n";
	test2.erase(beginner, ender);
	for (MODE::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;
}

{
	MODE::set<int> myset;

	myset.insert(10);
	myset.insert(30);
	myset.insert(300);
	myset.insert(20);

	std::cout << "\nTest with equal_rang :\n\n";
	for (MODE::set<int>::iterator it = myset.begin(); it != myset.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << myset.size() << std::endl;

	PAIR<MODE::set<int>::iterator, MODE::set<int>::iterator> ret;
	std::cout << "equal_range('b')\n";
	ret = myset.equal_range('b');

	std::cout << "first iterator point to: ";
	std::cout << *(ret.first) << " => " << *(ret.first) << '\n';

	std::cout << "second iterator point to: ";
	std::cout << *(ret.second) << " => " << *(ret.second) << '\n';

	std::cout << "\nTest with max_size :\n";

	std::cout << "Max_size : " << myset.max_size() << std::endl;
}

{
	std::cout << "\nTest with operator = :\n";
	MODE::set<int>		test;
	MODE::set<int>		test2;

	test.insert(18);
	test.insert(15);
	test.insert(150);
	test.insert(98);
	test.insert(-65);
	test.insert(13);

	std::cout << "print test :\n";
	for (MODE::set<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
	
	std::cout << "print test2 :\n";
	for (MODE::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;

	std::cout << "Use tes2 = test && tes.clear() :\n";
	test2 = test;
	test.clear();
	std::cout << "print test :\n";
	for (MODE::set<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test.size() << std::endl;
	
	std::cout << "print test2 :\n";
	for (MODE::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout  << "{" << *it << "/" << *it << "}" << " ";
	std::cout << "size " << test2.size() << std::endl;
}

{
	std::set<int> foo,bar;

	foo.insert(100);
	foo.insert(200);
	foo.insert(300);

	bar.insert(10);
	bar.insert(20);
	bar.insert(30);
	bar.insert(40);
	bar.insert(50);
	
	std::cout << "before swap FOO contains:\n";
	for (std::set<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it << " => " << *it << '\n';

	std::cout << "before swap BAR contains:\n";
	for (std::set<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it << " => " << *it << '\n';

	foo.swap(bar);

	std::cout << "after swap FOO contains:\n";
	for (std::set<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it << " => " << *it << '\n';

	std::cout << "after swap BAR contains:\n";
	for (std::set<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it << " => " << *it << '\n';
}

{
	std::cout << "\nTest with relational operators :\n\n";
	MODE::set<int> foo,bar;

	foo.insert(100);
	foo.insert(200);
	foo.insert(300);

	bar.insert(10);
	bar.insert(20);
	bar.insert(30);
	bar.insert(40);
	bar.insert(50);

	std::cout << "FOO contains:\n";
	for (MODE::set<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it << " => " << *it << '\n';

	std::cout << "BAR contains:\n";
for (MODE::set<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it << " => " << *it << '\n';

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
//	if (foo==bar) std::cout << "foo and bar are equal\n";
//	if (foo!=bar) std::cout << "foo and bar are not equal\n";
//	if (foo< bar) std::cout << "foo is less than bar\n";
//	if (foo> bar) std::cout << "foo is greater than bar\n";
//	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}

	return 0;
}
