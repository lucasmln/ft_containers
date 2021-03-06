/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:21:20 by lucas             #+#    #+#             */
/*   Updated: 2021/02/12 17:59:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../List/List.hpp"

namespace ft
{
	template <class T, class Container = list<T> >
	class queue
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type	_container;

		public:
			explicit queue(const container_type& ctnr = container_type())
			{
				_container = ctnr;
			}

			value_type&			back()
			{
				return (_container.back());
			}

			const value_type&	back() const
			{
				return (_container.back());
			}

			bool				empty() const
			{
				return (_container.empty());
			}

			value_type&			front()
			{
				return (_container.front());
			}

			const value_type&	front() const
			{
				return (_container.front());
			}

			void				pop()
			{
				_container.pop_front();
			}

			void				push(const value_type& val)
			{
				_container.push_back(val);
			}

			size_type			size() const
			{
				return (_container.size());
			}

		template <class T2, class Cntr>
		friend bool operator==(const queue<T2, Cntr> &lhs, const queue<T2, Cntr> &rhs);

		template <class T2, class Cntr>
		friend bool operator<(const queue<T2, Cntr> &lhs, const queue<T2, Cntr> &rhs);

	};

	template <class T, class Container>
	bool	operator==(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return ((lhs._container == rhs._container));
	};

	template <class T, class Container>
	bool	operator!=(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T, class Container>
	bool	operator<(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return ((lhs._container < rhs._container));
	};

	template <class T, class Container>
	bool	operator<=(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		if (lhs == rhs)
			return (true);
		return ((lhs < rhs));
	};

	template <class T, class Container>
	bool	operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{
		if (rhs ==  lhs)
			return (false);
		return (!(lhs < rhs));
	}

	template <class T, class Container>
	bool	operator>=(const queue<T, Container> &lhs, const queue<T, Container>& rhs)
	{
		if (lhs == rhs)
			return (true);
		return (!(lhs < rhs));
	}
} // ft namespace

#endif
