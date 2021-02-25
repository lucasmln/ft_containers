/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:37:17 by lucas             #+#    #+#             */
/*   Updated: 2021/02/25 19:44:20 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <cstddef>

namespace ft
{
	template <class T>
	class			node
	{
		public:
			typedef T		value_type;
			typedef T &		reference;
			typedef T *		pointer;

			node	*_next;
			node	*_before;
			T		_elem;

		public:
			node(const value_type &val = value_type()):
			_next(NULL), _before(NULL), _elem(val) {}

			node(node *nxt, node *bfr, const value_type &val):
			_next(nxt), _before(bfr), _elem(val) {}

			node(const node &other):
			_next(other._next), _before(other._before), _elem(other._elem) {}

			~node()
			{
			}

			node		&operator=(const node &other)
			{
				_next = other.next;
				_before = other._before;
				_elem = other.elem;
				return (*this);
			}

			bool		operator==(const node &other)
			{
				if (_elem != other._elem || _before != other._before ||
														_next != other._next)
					return (false);
				return (true);
			}

			bool		operator!=(const node &other)
			{
				return (!(*this == other));
			}

			node		*get_next()
			{
				return (this->_next);
			}

			node		*get_before()
			{
				return (this->before);
			}
};
} // namespace ft
#endif
