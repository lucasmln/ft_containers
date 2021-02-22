/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_deque.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:23:09 by lucas             #+#    #+#             */
/*   Updated: 2021/02/22 19:39:21 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Deque.hpp"
#include <deque>
#include <iostream>

#ifndef MODE
# define MODE std
#endif

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

struct is_even {
	bool operator() (const int& value) { return (value%2)==0; }
};

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first) >int(second) ); }

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }


int main(int argc, const char *argv[])
{
	(void)argv;
	(void)argc;
{
	MODE::deque<int>	lst(4, 12);
	MODE::deque<int>	lst2(7);
	MODE::deque<int>	lst3;
	MODE::deque<int>::iterator		ite;

	std::cout << "Lst2 = lst\n";
	lst2 = lst;
	for (MODE::deque<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Push 16, 24, 32, 48 in lst3\n";
	lst3.push_back(16);
	lst3.push_back(24);
	lst3.push_back(32);
	lst3.push_back(48);
	std::cout << "Front value in lst3 is " << lst3.front() << std::endl;
	std::cout << "Back value in lst3 is " << lst3.back() << std::endl;

	lst3.clear();
	std::cout << "deque with four 12\n";
	std::cout << "push_back 16 in the deque\n";
	lst.push_back(16);
	ite = lst.begin();
	ite++;
	ite++;
	std::cout << std::endl;
	for (MODE::deque<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Insert three 1 after the second value\n";
	lst.insert(ite, 3, 1);


	//MODE::deque<int>::iterator		test = lst.begin();
	for (MODE::deque<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "push 48\n";
	lst.push_back(48);
	std::cout << "back = " << lst.back() << std::endl;

	std::cout << "front = " << lst.front() << std::endl;

	std::cout << "lst size = " << lst.size() << std::endl;
	std::cout << "lst3 size = " << lst3.size() << std::endl;

	std::cout << "lst max_size = " << lst3.max_size() << std::endl;

	std::cout << (lst.empty() ? "lst is empty\n" : "lst is not empty\n");
	std::cout << (lst3.empty() ? "lst3 is empty\n" : "lst3 is not empty\n");

	std::cout << "lst size = " << lst.size() << std::endl;
	std::cout << "Clear lst\n";
	lst.clear();
	std::cout << "lst size = " << lst.size() << std::endl;
	for (MODE::deque<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
}

{
	std::cout << "Assign test\n\n";
	MODE::deque<int>	lst;

	lst.assign(5, 100);

	for (MODE::deque<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	MODE::deque<int> test(2, 600);
	MODE::deque<int>::iterator start = test.begin(), end = test.end();

	std::cout << "Assign two value of 600 with iterator\n";
	lst.assign(start, end);
	for (MODE::deque<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Assign eight value of 90 with size\n";
	lst.assign(8, 90);
	for (MODE::deque<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nCreate deque with iterator\n";
	MODE::deque<int>	with_it(start, end);
	for (MODE::deque<int>::iterator it = with_it.begin(); it != with_it.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nCreate deque with copy of lst\n";
	MODE::deque<int>	copy(lst);
	for (MODE::deque<int>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

{
	std::cout << "\nErase test :\n";
	MODE::deque<int>				lst;
	MODE::deque<int>::iterator		it;

	std::cout << "Create deque with values 0 to 9\n";
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	it = lst.begin();
	for (int i = 0; i < 7; i++)
		it++;
	std::cout << "Erase the value " << *it << std::endl;
	lst.erase(it);
	for (MODE::deque<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << " ";
	std::cout << std::endl;

	std::cout << "Erase value 0 to 4\n";
	MODE::deque<int>::iterator ite = lst.begin();
	for (int i = 0; i < 5; i++)
		ite++;
	lst.erase(lst.begin(), ite);
	for (MODE::deque<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << " ";
	std::cout << std::endl;
}

{
	std::cout << "\nInsert test\n";
	MODE::deque<int>			lst;
	MODE::deque<int>::iterator	it;

	std::cout << "Create deque with values 0 to 9\n";
	for (int i = 0; i < 7; i++)
		lst.push_back(i);
	it = lst.begin();
	it++;
	it++;
	std::cout << "Insert value -20 before the third value\n";
	lst.insert(it, -20);
	for (MODE::deque<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << " ";
	std::cout << std::endl;

	std::cout << "Insert three value of 1000 before the first value\n";
	MODE::deque<int>::iterator		t = lst.begin();
	lst.insert(t + 3, 3, 1000);
	for (MODE::deque<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << " ";
	std::cout << std::endl;
	std::cout << "Insert value with iterator 96 to 99 before the fourth value\n";
	MODE::deque<int>		test;
	for (int i = 90; i < 100; i++)
		test.push_back(i);
	MODE::deque<int>::iterator		it_test = test.begin();
	for (int x = 0; x < 6; x++)
		it_test++;
	MODE::deque<int>::iterator		beg = lst.begin();
	beg++;
	beg++;
	std::cout << *it_test << " oui\n";
	lst.insert(beg, it_test, test.end());
	for (MODE::deque<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << " ";
	std::cout << std::endl;
}

{
	std::cout << "\nInsert with first and last by cpp reference :\n\n";
	MODE::deque<int> mydeque;

	// set some initial values:
	for (int i=1; i<6; i++) mydeque.push_back(i); // 1 2 3 4 5

	MODE::deque<int>::iterator it = mydeque.begin();
	++it;

	it = mydeque.insert (it,10);                  // 1 10 2 3 4 5
	// "it" now points to the newly inserted 10


	mydeque.insert (it,2,20);                     // 1 20 20 10 2 3 4 5
	// "it" no longer valid!

	it = mydeque.begin()+2;

	MODE::deque<int> myvector (2,40);

	mydeque.insert (it,myvector.begin(),myvector.end());
	// 1 20 30 30 20 10 2 3 4 5
	std::cout << "mydeque contains:";
	for (it=mydeque.begin(); it!=mydeque.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}

{
	std::cout << "\nPop/push  back/front test :\n\n";

	MODE::deque<int>	lst;

	for (int i = 0; i < 5; i++)
		lst.push_back(i);
	lst.push_back(100);
	std::cout << "Initial value of lst : ";
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "Pop back 2 times\n";
	lst.pop_back();
	lst.pop_back();
//	lst.insert(lst.begin(), 4, 12);
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << "\nPop front 2 times\n";
	lst.pop_front();
	lst.pop_front();
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";

	std::cout << "\nPush front values 0 to 8\n";
	for (int i = 0; i < 9; i++)
		lst.push_front(i);
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
}

{
	std::cout << "\nTest with resize :\n";

	MODE::deque<int>	lst;

	for (int i = 0; i < 20; i += 2)
		lst.push_back(i);
	std::cout << "Initial value : ";
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "Resize 15 with _size 10\n";
	lst.resize(15, 1);
	std::cout << "size =" << lst.size() << " ";
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "Resize 5 with _size 15\n";
	lst.resize(5, 8);
	std::cout << "size =" << lst.size() << " ";
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	std::cout << "Resize 0 with _size 5\n";
	lst.resize(0, 8);
	std::cout << "size =" << lst.size() << " ";
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "Resize 4 with _size 0\n";
	lst.resize(4, 1);
	std::cout << "size =" << lst.size() << " ";
	for (MODE::deque<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

{
	std::cout << "\nTest with swap\n\n";

	MODE::deque<int> first (3,100);   // three ints with a value of 100
	MODE::deque<int> second (5,200);  // five ints with a value of 200

	std::cout << "First BEFORE swap : ";
	for (MODE::deque<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Second BEFORE swap : ";
	for (MODE::deque<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	first.swap(second);

	std::cout << "first AFTER swap:";
	for (MODE::deque<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << first.size();
	std::cout << '\n';

	std::cout << "second AFTER swap:";
	for (MODE::deque<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << second.size();
	std::cout << '\n';

	std::cout << "\nWith 2 empty deque\n";
	MODE::deque<int> lst1;   // three ints with a value of 100
	MODE::deque<int> lst2;  // five ints with a value of 200

	std::cout << "lst1 BEFORE swap : ";
	for (MODE::deque<int>::iterator it=lst1.begin(); it!=lst1.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "lst2 BEFORE swap : ";
	for (MODE::deque<int>::iterator it=lst2.begin(); it!=lst2.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	lst1.swap(lst2);

	std::cout << "lst1 AFTER swap:";
	for (MODE::deque<int>::iterator it=lst1.begin(); it!=lst1.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << lst1.size();
	std::cout << '\n';

	std::cout << "lst2 AFTER swap:";
	for (MODE::deque<int>::iterator it=lst2.begin(); it!=lst2.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << lst2.size();
	std::cout << '\n';
}

{
	std::cout << "\nTest with relational operator\n\n";
	MODE::deque<int> a;
	MODE::deque<int> b;
	MODE::deque<int> c;

	a.push_back(10); a.push_back(20); a.push_back(30);
	b.push_back(10); b.push_back(20); b.push_back(30);
	c.push_back(30); c.push_back(20); c.push_back(10);

	std::cout << " a = {10, 20, 30}\n";
	std::cout << " b = {10, 20, 30}\n";
	std::cout << " c = {30, 20, 10}\n\n";
	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";
}

{
	std::cout << "\nTest with overload swap\n\n";

	MODE::deque<int> foo (3,100);   // three ints with a value of 100
	MODE::deque<int> bar (5,200);   // five ints with a value of 200

	std::cout << "Foo = 100 100 100\n";
	std::cout << "Bar = 200 200 200 200 200\n";
	std::swap(foo,bar);

	std::cout << "foo contains:";
	for (MODE::deque<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (MODE::deque<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
	return (0);
}
