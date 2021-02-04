/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:15:46 by lucas             #+#    #+#             */
/*   Updated: 2021/02/04 18:31:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/Bidirectional_iterator.hpp"
# include "includes/ReverseIterator.hpp"
# include "srcs/list.hpp"
# include <list>

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

int main(int argc, const char *argv[])
{
	(void)argv;
	(void)argc;
{
	ft::list<int>	lst(4, 12);
	ft::list<int>	lst2(7);
	ft::list<int>	lst3;
	ft::list<int>::iterator		ite = lst.begin();

	std::cout << "Lst2 = lst\n";
	lst2 = lst;
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	std::cout << "Push 16, 24, 32, 48 in lst3\n";
	lst3.push_back(16);
	lst3.push_back(24);
	lst3.push_back(32);
	lst3.push_back(48);
	std::cout << "Front value in lst3 is " << lst3.front() << std::endl;
	std::cout << "Back value in lst3 is " << lst3.back() << std::endl;

	lst3.clear();
	std::cout << "list with four 12\n";
	std::cout << "push_back 16 in the list\n";
	lst.push_back(16);
	ite++;
	ite++;
	std::cout << "Insert three 1 after the second value\n";
	lst.insert(ite, 3, 1);


	ft::list<int>::iterator		test = lst.begin();
	while (test != lst.end())
		test++;
	test++;
	std::cout << "\nTry to print with boucle it\n";
	while (test != lst.end())
	{
		std::cout << *test << std::endl;
		test++;
	}
	std::cout << "success\n";

	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

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
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
}

{
	std::cout << "Assign test\n\n";
	ft::list<int>	lst(4, 12);

	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

	ft::list<int> test(2, 600);
	ft::list<int>::iterator start = test.begin(), end = test.end();
	for (int i = 0; i < 6; i++)
		start++;

	std::cout << "Assign two value of 600 with iterator\n";
	lst.assign(start, end);
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "Assign eight value of 90 with size\n";
	lst.assign(8, 90);
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "\nCreate list with iterator\n";
	ft::list<int>	with_it(start, end);
	for (ft::list<int>::iterator it = with_it.begin(); it != with_it.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "\nCreate list with copy of lst\n";
	ft::list<int>	copy(lst);
	for (ft::list<int>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it << std::endl;
}

{
	std::cout << "\nErase test :\n";
	ft::list<int>				lst;
	ft::list<int>::iterator		it = lst.begin();

	std::cout << "Create list with values 0 to 9\n";
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	for (int i = 0; i < 7; i++)
		it++;
	std::cout << "Erase the value seven\n";
	lst.erase(it);
	for (ft::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << std::endl;

	std::cout << "Erase value 0 to 4\n";
	ft::list<int>::iterator ite = lst.begin();
	for (int i = 0; i < 5; i++)
		ite++;
	lst.erase(lst.begin(), ite);
	for (ft::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << std::endl;
}

{
	std::cout << "\nInsert test\n";
	ft::list<int>			lst;
	ft::list<int>::iterator	it = lst.begin();
	ft::list<int>::iterator	i = lst.begin();

	std::cout << "Create list with values 0 to 9\n";
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	it++;
	it++;
	std::cout << "Insert value 99 before the third value\n";
	lst.insert(it, 99);
	for (ft::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << "\t";
	std::cout << std::endl;

	std::cout << "Insert three value of 1000 before the first value\n";
	ft::list<int>::iterator		t = lst.begin();
	lst.insert(t, 3, 1000);
	for (ft::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << "\t";
	std::cout << std::endl;

	std::cout << "Insert value with iterator 96 to 99 before the fourth value\n";
	ft::list<int>		test;
	for (int i = 90; i < 100; i++)
		test.push_back(i);
	ft::list<int>::iterator		it_test = test.begin();
	it++;
	it++;
	for (int x = 0; x < 6; x++)
		it_test++;
	lst.insert(it, it_test, test.end());
	for (ft::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << "\t";
	std::cout << std::endl;

}

{
	std::cout << "\nPop/push  back/front test :\n\n";

	ft::list<int>	lst;

	for (int i = 0; i < 5; i++)
		lst.push_back(i);
	lst.push_back(100);
	std::cout << "Initial value of lst : ";
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Pop back 2 times\n";
	lst.pop_back();
	lst.pop_back();
//	lst.insert(lst.begin(), 4, 12);
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << "\nPop front 2 times\n";
	lst.pop_front();
	lst.pop_front();
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << "\nPop front 3 times\n";
	lst.pop_front();
	lst.pop_front();
	lst.pop_front();
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";

	std::cout << "\nPush front values 0 to 8\n";
	for (int i = 0; i < 9; i++)
		lst.push_front(i);
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
}

{
	std::cout << "\n\nTest with remove\n";

	ft::list<int>		lst;

	for (int i = 0; i < 10; i++)
		lst.push_back(i % 3);
	std::cout << "Initial value : ";
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Remove all value equal to 0\n";
	lst.remove(0);
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Remove all value equal to 2\n";
	lst.remove(2);
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Remove all value equal to 1\n";
	lst.remove(1);
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "size = " << lst.size() << std::endl;
}


{
	std::cout << "\nTest with remove_if :\n\n";

	ft::list<int>	lst;

	lst.push_back(15);
	lst.push_back(36);
	lst.push_back(7);
	lst.push_back(17);
	lst.push_back(20);
	lst.push_back(39);
	lst.push_back(4);
	lst.push_back(1);
	lst.remove_if (single_digit);           // 15 36 17 20 39

	lst.remove_if (is_odd());               // 36 20

//	lst.remove_if (is_even());               // emptu

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

{
	std::cout << "\nTest with resize :\n";

	ft::list<int>	lst;

	for (int i = 0; i < 20; i+= 2)
		lst.push_back(i);
	std::cout << "Initial value : ";
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Resize 15 with _size 10\n";
	lst.resize(15, 1);
	std::cout << "size =" << lst.size() << "\t";
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;

	std::cout << "Resize 5 with _size 15\n";
	lst.resize(5, 8);
	std::cout << "size =" << lst.size() << "\t";
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	
	std::cout << "Resize 0 with _size 5\n";
	lst.resize(0, 8);
	std::cout << "size =" << lst.size() << "\t";
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;

	std::cout << "Resize 4 with _size 0\n";
	lst.resize(4, 1);
	std::cout << "size =" << lst.size() << "\t";
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
}

{
	std::cout << "\nTest with reverse :\n";
	
	ft::list<int> lst;

	for (int i = 1; i <= 10; ++i)
		lst.push_back(i);
	std::cout << "Initial value : ";
	for (ft::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	lst.reverse();

	std::cout << "reverse lst contains:";
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

{
	std::cout << "\nTest with sort :\n";

	ft::list<std::string> lst;
	ft::list<std::string>::iterator it;
	lst.push_back ("one");
	lst.push_back ("two");
	lst.push_back ("Three");
	lst.push_back("four");
	lst.push_back("five");
	lst.push_back("fivee");
	lst.push_back("six");
	std::cout << "Initial value : ";
	for (ft::list<std::string>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << " " << *ite;
	std::cout << std::endl;
	lst.sort();

	std::cout << "mylist contains:";
	for (it=lst.begin(); it!=lst.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Sort with function compare_nocase\n";
	lst.sort(compare_nocase);

	std::cout << "mylist contains:";
	for (it = lst.begin(); it != lst.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

{
	std::list<int>	true_lst(4, 12);
	std::cout << "\ntest with real list\n";
	for (std::list<int>::iterator it = true_lst.begin(); it != true_lst.end(); it++)
		std::cout << *it << std::endl;

	std::list<int> test(2, 600);
	std::list<int>::iterator start = test.begin(), end = test.end();
	for (int i = 0; i < 6; i++)
		start++;
	std::cout << "assign\n";
	true_lst.assign(start, end);
	for (std::list<int>::iterator it = true_lst.begin(); it != true_lst.end(); it++)
		std::cout << *it << std::endl;
}
	return 0;
}
