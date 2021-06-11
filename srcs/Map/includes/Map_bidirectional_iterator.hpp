/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_bidirectional_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:17:40 by lucas             #+#    #+#             */
/*   Updated: 2021/06/11 14:06:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BIDIRECTIONAL_ITERATOR_HPP
# define MAP_BIDIRECTIONAL_ITERATOR_HPP

# include <cstddef>
# include <memory>
# include <iostream>
# include <limits>
# include "./MapNode.hpp"


namespace ft
{

	template <class T>
	class MapIterator
	{
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef T									&reference;
			typedef const T								&const_reference;
			typedef T									*pointer;
			typedef	ptrdiff_t							difference_type;
			typedef size_t								size_type;

		private:
			typedef MapNode<T>		node;
			node					*_ptr;
			typedef MapIterator		_self;

		public:

		MapIterator(): _ptr(NULL) {}

		MapIterator(node *elem): _ptr(elem) {}

		MapIterator(_self *other): _ptr(other->_ptr) {}

		_self		&operator=(_self const &other)
		{
			_ptr = other._ptr;
			return (*this);
		}

		// INCREMENTERS
		_self		operator++(int)
		{
			if (_ptr->right)
			{
				_ptr = _ptr->right;
				while (_ptr->left)
					_ptr = _ptr->left;
			}
			else
			{
				node	*tmp = _ptr;
				_ptr = _ptr->parent;
				while (_ptr->parent && tmp == _ptr->right)
				{
					tmp = _ptr;
					_ptr = _ptr->parent;
				}
			}
			return (*this);
		}

		_self		operator++()
		{
			_self		it = *this;

			if (_ptr->right)
			{
				_ptr = _ptr->right;
				while (_ptr->left)
					_ptr = _ptr->left;
			}
			else
			{
				node	*tmp = _ptr;
				_ptr = _ptr->parent;
				while (_ptr->parent && tmp == _ptr->right)
				{
					tmp = _ptr;
					_ptr = _ptr->parent;
				}
			}
			return (*this);
		}

		_self		operator--()
		{
			if (_ptr->left)
			{
				_ptr = _ptr->left;
				while (_ptr->right)
					_ptr = _ptr->right;
			}
			else
			{
				node	*tmp = _ptr;
				_ptr = _ptr->parent;
				while (_ptr->parent && tmp == _ptr->left)
				{
					tmp = _ptr;
					_ptr = _ptr->parent;
				}
			}
			return (*this);
		}

		_self		operator--(int)
		{
			_self		it = *this;

			if (_ptr->left)
			{
				_ptr = _ptr->left;
				while (_ptr->right)
					_ptr = _ptr->right;
			}
			else
			{
				node	*tmp = _ptr;
				_ptr = _ptr->parent;
				while (_ptr->parent && tmp == _ptr->left)
				{
					tmp = _ptr;
					_ptr = _ptr->parent;
				}
			}
			return (*this);
		}

		// BOOLEANS
		bool			operator==(_self const &other)
		{
			return (_ptr == other._ptr);
		}

		bool			operator!=(_self const &other) const
		{
			return (_ptr != other._ptr);
		}

		pointer			operator->()
		{
			return (&_ptr->elem);
		}

		value_type		operator*()
		{
			return (_ptr->elem);
		}
	};
} // namespace ft

#endif
