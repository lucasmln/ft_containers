/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set_reverse_bidirectional_iterator.hpp             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:53:36 by lucas             #+#    #+#             */
/*   Updated: 2021/02/25 19:45:20 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_REVERSE_BIDIRECTIONAL_ITERATOR_HPP
# define SET_REVERSE_BIDIRECTIONAL_ITERATOR_HPP

# include <cstddef>
# include <memory>
# include <iostream>
# include <limits>
# include "./SetNode.hpp"


namespace ft
{

	template <class T>
	class SetReverseIterator
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
			typedef SetNode<T>			node;
			node						*_ptr;
			typedef SetReverseIterator	_self;

		public:

		SetReverseIterator(): _ptr(NULL) {}

		SetReverseIterator(node *elem): _ptr(elem) {}

		SetReverseIterator(_self *other): _ptr(other->_ptr) {}

		_self		&operator=(_self const &other)
		{
			_ptr = other._ptr;
			return (*this);
		}

		// INCREMENTERS
		_self		operator--(int)
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

		_self		operator--()
		{
			_self		it = *this;

			if (_ptr->right)
			{
				_ptr = _ptr->right;
				while (_ptr->left)
					_ptr = _ptr->left;
			}
			else if (_ptr->parent)
				_ptr = _ptr->parent;
			return (it);
		}

		_self		operator++()
		{
			if (_ptr->left)
			{
				_ptr = _ptr->left;
				while (_ptr->right)
					_ptr = _ptr->right;
			}
			else if (_ptr->parent)
				_ptr = _ptr->parent;
			return (*this);
		}

		_self		operator++(int)
		{
			_self		it = *this;

			if (_ptr->left)
			{
				_ptr = _ptr->left;
				while (_ptr->right)
					_ptr = _ptr->right;
			}
			else if (_ptr->parent && _ptr->parent->right == _ptr)
				_ptr = _ptr->parent;
			return (it);
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
