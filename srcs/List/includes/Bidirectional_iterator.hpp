/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:25:36 by lucas             #+#    #+#             */
/*   Updated: 2021/02/18 15:45:56 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <limits>
# include <sstream>
# include <iostream>
# include "./node.hpp"
# include "../List.hpp"

namespace ft
{
	template <typename T>
	class Bidirectional_iterator
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
			typedef node<T>		value_node;
			value_node			*_ptr;
			typedef Bidirectional_iterator		Bi_iterator;

		public:
			Bidirectional_iterator():_ptr(nullptr) {}

			Bidirectional_iterator(value_node *elem): _ptr(elem) {}

			Bidirectional_iterator(Bi_iterator *other)
			{
				_ptr = other->_ptr;
			}

			~Bidirectional_iterator() {}

			Bidirectional_iterator		&operator=(Bi_iterator const &it)
			{
				this->_ptr = it._ptr;
				return (*this);
			}

			// INCREMENTERS
			Bi_iterator			operator++()
			{
				_ptr = _ptr->_next;
				return (*this);
			}

			Bi_iterator			operator++(int)
			{
				Bi_iterator		it = *this;

				_ptr = _ptr->_next;
				return (it);
			}

			Bi_iterator			operator--()
			{
				_ptr = _ptr->_before;
				return (*this);
			}

			Bi_iterator			operator--(int)
			{
				Bi_iterator		it = *this;

				_ptr = _ptr->_before;
				return (it);
			}

			// BOOLEANS
			bool			operator==(Bi_iterator const &other)
			{
				return (_ptr == other._ptr);
			}

			bool			operator!=(Bi_iterator const &other)
			{
				return (_ptr != other._ptr);
			}

			// DEREFERENCING & ADDRESS STUFF
			reference		operator*()
			{
				return (_ptr->_elem);
			}

			const_reference	operator*() const
			{
				return (_ptr->_elem);
			}

			pointer			operator->()
			{
				return (&(_ptr->_elem));
			}
	};
} // namespace ft

#endif
