/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:40:56 by lucas             #+#    #+#             */
/*   Updated: 2021/02/18 16:35:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "./includes/node.hpp"
# include "./includes/Bidirectional_iterator.hpp"
# include "./includes/Reverse_Bidirectional_iterator.hpp"

namespace ft
{
	template <typename T>
	class Bidirectional_iterator;

	template <typename T>
	class Reverse_Bidirectional_iterator;

	template <class T, class Allocator = std::allocator<T> > class list
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef T											&reference;
			typedef const T										&const_reference;
			typedef T											*pointer;
			typedef const T										*const_pointer;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;
			typedef Bidirectional_iterator <value_type>			iterator;
			typedef const Bidirectional_iterator <value_type>	const_iterator;
			typedef Reverse_Bidirectional_iterator <value_type>		reverse_iterator;
			typedef const Reverse_Bidirectional_iterator <value_type>	const_reverse_iterator;

		private:
			typedef node<T>	node;
			node			*_head;
			node			*_tail;
			size_type		_size;
			allocator_type	_alloc;

			void		init(void)
			{
				_head = new node;
				_tail = new node;
				_head->_next = _tail;
				_head->_before = _tail;
				_tail->_next = _head;
				_tail->_before = _head;
			}

			node		*find(iterator pos)
			{
				node	*find = _head;

				for (iterator it = begin(); it != pos && it != end(); it++)
					find = find->_next;
				return (find);
			}

		public:
			explicit	list(const allocator_type& alloc = allocator_type()):
			_alloc(alloc)
			{
				init();
				_tail = _head;
				_size = 0;
			}

			explicit	list(size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			_size(0), _alloc(alloc)
			{
				if (n > 0)
				{
					init();
					_tail = _head;
					for (size_type i = 0; i < n; i++)
						push_back(val);
				}
			}

			template <class InputIt>
			list(InputIt first, InputIt last,
				const allocator_type& alloc = allocator_type(),
								typename InputIt::difference_type * = nullptr)
			{
				_alloc = alloc;
				init();
				_head->_elem = *first++;
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			list(const list& x): _size(0), _alloc(x.get_allocator())
			{
				init();
				_tail = _head;
				if (x.size() > 0)
					_head->_elem = x._head->_elem;
				for (iterator it = x.begin(); x.size() > 0 && it != x.end(); it++)
					push_back(*it);
			}

			~list()
			{
				clear();
				delete _head;
			}

			list				&operator=(const list& x)
			{
				clear();
				insert(begin(), x.begin(), x.end());
				return (*this);
			}

			template <class InputIt>
			void				assign(InputIt first, InputIt last,
								typename InputIt::difference_type * = nullptr)
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void				assign(size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			reference			back()
			{
				return (_tail->_before->_elem);
			}

			const_reference		back() const
			{
				return (_tail->_before->_elem);
			}

			iterator			begin()
			{
				return (iterator(_head));
			}

			const_iterator		begin() const
			{
				return (const_iterator(_head));
			}

			void				clear()
			{
				size_type	n = _size;

				while (n-- > 0)
					pop_back();
				_size = 0;
			}

			bool				empty() const
			{
				return (_size == 0 ? true : false);
			}

			iterator			end()
			{
				return (iterator(_tail));
			}

			const_iterator			end() const
			{
				return (const_iterator(_tail));
			}

			iterator				erase(iterator position)
			{
				node	*del;

				if (_size == 0)
					return (position);
				del = find(position);
				if (del == _head)
				{
					if (del->_next == _tail)
					{
						_tail = _head;
						_size--;
						return (position);
					}
					_head = del->_next;
				}
				if (del == _tail)
					return (position);
				if (_head != _tail)
				{
					del->_before->_next = del->_next;
					del->_next->_before = del->_before;
				}
				if (del != _head && del != _tail)
					delete del;
				_size--;
				return (position);
			}

			iterator				erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
				return (first);
			}

			reference			front()
			{
				return (_head->_elem);
			}

			const_reference			front() const
			{
				return (_head->_elem);
			}

			allocator_type			get_allocator() const
			{
				return (_alloc);
			}

			iterator				insert(iterator position, const value_type& val)
			{
				node	*f = find(position);
				node	*add = new node(val);

				add->_before = f->_before;
				add->_next = f;
				add->_before->_next = add;
				f->_before = add;
				if (f == _head)
					_head = add;
				_size++;
				return (position);
			}

			void					insert(iterator position, size_type n,
														const value_type& val)
			{
				for (size_type i = 0; i < n; i++)
					insert(position, val);
			}

			template <class InputIt>
			void					insert(iterator position, InputIt first,
						InputIt last, typename InputIt::difference_type * = nullptr)
			{
				while (first != last)
				{
					insert(position, *first);
					first++;
				}
			}

			size_type				max_size() const
			{
				return (SIZE_T_MAX / sizeof(node));
			}

			void					merge(list& x)
			{
				bool		is_sort = true;
				iterator	test = x.begin();

				test++;
				for (iterator it = x.begin(); test != x.end(); it++, test++)
					if (*test < *it)
						is_sort = false;
				test = begin();
				test++;
				for (iterator it = begin(); test != end(); it++, test++)
					if (*test < *it)
						is_sort = false;
				for (iterator it = x.begin(); it != x.end(); it++)
					push_back(*it);
				x.clear();
				if (is_sort)
					sort();
			}

			template <class Compare>
			void					merge(list& x, Compare comp)
			{
				bool		is_sort[] = {true, true, true, true};
				iterator	test = ++x.begin();

				if (this == &x)
					return ;
				for (iterator it = x.begin(); test != x.end(); it++)
				{
					if (!comp(*it, *test))
						is_sort[0] = false;
					if (*test < *it)
						is_sort[1] = false;
					test++;
				}
				test = ++begin();
				for (iterator it = begin(); test != end(); it++, test++)
				{
					if (!comp(*it, *test))
						is_sort[2] = false;
					if (*test < *it)
						is_sort[3] = false;
				}
				if (is_sort[2] && is_sort[1])
					x.sort();
				if (is_sort[3] && is_sort[0])
					for (iterator it = x.begin(); it != x.end(); it++)
					{
						if (comp(*it, *begin()))
							push_front(*it);
						else
							push_back(*it);
					}
				else
					for (iterator it = x.begin(); it != x.end(); it++)
						push_back(*it);
				x.clear();
				if (is_sort[0] && is_sort[2])
					sort(comp);
			}

			void					pop_back()
			{
				erase(--end());
			}

			void					pop_front()
			{
				erase(begin());
			}

			void					push_back(const value_type& val)
			{
				node	*add = new node;

				_tail->_elem = val;
				_tail->_next = add;
				add->_before = _tail;
				_tail = add;
				_tail->_next = _head;
				_size++;
			}

			void					push_front(const value_type& val)
			{
				node	*add = new node;

				add->_elem = val;
				add->_next = _head;
				add->_before = _tail;
				_head = add;
				_size++;
			}

			reverse_iterator		rbegin()
			{
				return (reverse_iterator(_tail));
			}

			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(_tail));
			}

			void					remove(const value_type& val)
			{
				iterator	it = begin();

				while (it != end())
				{
					if (*it == val)
					{
						erase(it);
						it = begin();
					}
					else
						it++;
				}
			}

			template <class Predicate>
			void					remove_if(Predicate pred)
			{
				size_type	n = _size;
				iterator	it = begin();

				while (n > 0)
				{
					if (pred(*it))
						erase(it);
					it++;
					n--;
				}
			}

			reverse_iterator		rend()
			{
				return (reverse_iterator(_head));
			}

			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(_head));
			}

			void					resize(size_type n, value_type val = value_type())
			{
				iterator		it = begin();
				size_type				y = 0;

				if (n <= 0)
					clear();
				else if (n > _size)
				{
					for (size_type i = _size; n > i; i++)
						push_back(val);
				}
				else if (n < _size)
				{
					for (; y < n; y++)
						it++;
					erase(it, end());
				}
				_size = n;
			}

			void					reverse()
			{
				iterator	up = begin();
				iterator	down = end();
				node		*tmp = new node;

				for (size_type i = 0; i < _size / 2; i++)
				{
					down--;
					tmp->_elem = *up;
					*up++ = *down;
					*down = tmp->_elem;
				}
				delete tmp;
			}

			size_type				size() const
			{
				return (_size);
			}

			void					sort()
			{
				iterator	up = begin();
				iterator	follow = begin();
				node		*tmp = new node;

				while (++up != end())
				{
					if (*up < *follow)
					{
						tmp->_elem = *follow;
						*follow = *up;
						*up = tmp->_elem;
						up = begin();
						follow = begin();
					}
					else
						follow++;
				}
				delete tmp;
			}

			template <class Compare>
			void					sort(Compare comp)
			{
				iterator	up = begin();
				iterator	follow = begin();
				node		*tmp = new node;

				while (++up != end())
				{
					if (comp(*up, *follow))
					{
						tmp->_elem = *follow;
						*follow = *up;
						*up = tmp->_elem;
						up = begin();
						follow = begin();
					}
					else
						follow++;
				}
				delete tmp;
			}

			void					splice(iterator position, list& x)
			{
				for (iterator it = x.begin(); it != x.end(); it++)
					insert(position, *it);
				x.clear();
			}

			void					splice(iterator position, list& x, iterator i)
			{
				insert(position, *i);
				x.erase(i);
			}

			void					splice(iterator position, list& x,
												iterator first, iterator last)
			{
				iterator	tmp = first;
				
				while (first != last)
				{
					insert(position, *first);
					first++;
				}
				x.erase(tmp, last);
			}

			void					swap(list& x)
			{
				list<value_type>	tmp(x);

				x = *this;
				*this = tmp;
			}

			void					unique()
			{
				iterator		test;

				for (iterator it = begin(); it != end(); it++)
				{
					test = it;
					test++;
					while (test != end())
					{
						if (*test == *it)
							erase(test);
						test++;
					}
				}
			}

			template <class BinaryPredicate>
			void					unique(BinaryPredicate binary_pred)
			{
				iterator		test;

				for (iterator it = begin(); it != end(); it++)
				{
					test = it;
					test++;
					while (test != end())
					{
						if (binary_pred(*it, *test))
							erase(test);
						test++;
					}
				}
			}
	};

	template <class T, class Alloc>
	bool	operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (typename list<T>::iterator l = lhs.begin(), r = rhs.begin();
													l != lhs.end(); l++, r++)
		{
			if (*l != *r)
				return (false);
		}
		return (true);
	}

	template <class T, class Alloc>
	bool	operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if ((*(lhs.begin()) < *(rhs.begin())))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool	operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool	operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return ((rhs < lhs));
	}

	template <class T, class Alloc>
	bool	operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void	swap(list<T,Alloc>& x, list<T,Alloc>& y)
	{
		x.swap(y);
	}
} //namespace ft
#endif
