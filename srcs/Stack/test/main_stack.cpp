/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:17:05 by lucas             #+#    #+#             */
/*   Updated: 2021/02/18 15:50:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <stack>          // std::stack
#include "../Stack.hpp"

int main ()
{
{
	std::cout << "Test with constructor :\n";
		ft::list<int> mydeck(3,100);        // deque with 3 elements
	ft::list<int> mylist(2,200);         // list with 2 elements

	ft::stack<int> first;                 // empty stack
	ft::stack<int, ft::list<int> > second(mydeck);       // stack initialized to copy of deque

	ft::stack<int, ft::list<int> > third; // empty stack with list as underlying container
	ft::stack<int, ft::list<int> > fourth(mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}

{
	std::cout << "\nTest with empty() :\n";
	ft::stack<int> mystack;
	int sum (0);

	mystack.empty() ? std::cout << "mystack is empty\n": std::cout << "mystack is not empty\n";
	std::cout << "fill mystack\n";
	for (int i=1;i<=10;i++) mystack.push(i);
	mystack.empty() ? std::cout << "mystack is empty\n": std::cout << "mystack is not empty\n";

	while (!mystack.empty())
	{
		sum += mystack.front();
		mystack.pop();
	}
	std::cout << "total: " << sum << '\n';
}

{
	std::cout << "\nTest with front() : \n";
	ft::stack<int> mystack;

	mystack.push(77);
	mystack.push(16);


	std::cout << "mystack.front() is now " << mystack.front() << '\n';
}

{
	std::cout << "\nTest with pop() and push() :\n";

	ft::stack<int> mystack;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		mystack.push (myint);
	} while (myint);

	std::cout << "mystack contains: ";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.front();
		mystack.pop();
	}
	std::cout << '\n';
}

{
	std::cout << "\nTest with size() :\n";

	ft::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

}

{
	std::cout << "\nTest with relational operator :\n";

	ft::stack<int>	a;
	ft::stack<int>	b;
	ft::stack<int>	c;

	a.push(10); a.push(20); a.push(30);
	b.push(10); b.push(20); b.push(30);
	c.push(30); c.push(20); c.push(10);

	std::cout << " a = {10, 20, 30}\n";
	std::cout << " b = {10, 20, 30}\n";
	std::cout << " c = {30, 20, 10}\n\n";
	std::cout << "a and b are ";
	std::cout << (a == b ? "equal\n": "not equal\n") << std::endl;

	std::cout << "b and c are ";
	std::cout << (b != c ? "not equal\n": "equal\n") << std::endl;;

	std::cout << "b is ";
	std::cout << (b != c ? "not less than c\n": "less than c\n");

	std::cout << std::endl;

	std::cout << "c is ";
	std::cout << (c > b ? "greter than b\n": "not greater than b\n");

	std::cout << std::endl;

	std::cout << "a is ";
	std::cout << (a <= b ? "less or equal to b\n": "not less or equal to b\n");

	std::cout <<std::endl;

	std::cout << "a is ";
	std::cout << (a >= b ? "greater or equal to b\n": "not greater or equal to b");

	std::cout << std::endl;
}

return 0;
}
