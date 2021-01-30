/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:32:37 by lucas             #+#    #+#             */
/*   Updated: 2021/01/30 16:39:38 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP
# include <cstdlib>
# include <cstddef>
# include <memory>
# include <limits>
# include <sstream>
# include <iostream>

namespace ft
{
	template <typename T>
	class ReverseIterator
	{
		public:
			typedef std::random_access_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	T									&reference;
			typedef const T								&const_reference;
			typedef T									*pointer;
			typedef	ptrdiff_t							difference_type;
			typedef size_t								size_type;

		private:
			pointer						_ptr;
			typedef ReverseIterator			self;

		public:
			ReverseIterator() {}

			ReverseIterator(pointer other): _ptr(other) {}

			ReverseIterator(ReverseIterator *other)
			{
				this->_ptr = other->_ptr;
			}

			~ReverseIterator() {}

			reference		operator=(self const &it)
			{
				_ptr = it._ptr;
				return (*this);
			}

			// INCREMENTERS
			self			operator++()
			{
				--_ptr;
				return (*this);
			}

			self			operator++(int)
			{
				self		it = *this;

				--_ptr;
				return (it);
			}

			self			operator+=(size_type nb)
			{
				_ptr -= nb;
				return (*this);
			}

			self			operator--()
			{
				++_ptr;
				return (*this);
			}

			self			operator--(int)
			{
				self		it = *this;

				++_ptr;
				return (it);
			}

			self			operator-=(size_type nb)
			{
				_ptr += nb;
				return (*this);
			}

			// ARITHMETICS
			self			operator+(difference_type n)
			{
				return (_ptr - n);
			}

			self			operator-(difference_type n)
			{
				return (_ptr + n);
			}

			self			operator+(self &other)
			{
				return (_ptr - other._ptr);
			}

			self			operator-(self &other)
			{
				return (_ptr + other._ptr);
			}

			// BOOLEANS
			bool			operator==(self const &other)
			{
				return (_ptr == other._ptr);
			}

			bool			operator!=(self const &other)
			{
				return (_ptr != other._ptr);
			}

			bool			operator>=(self const &other)
			{
				return (_ptr >= other._ptr);
			}

			bool			operator>(self const &other)
			{
				return (_ptr > other._ptr);
			}

			bool			operator<=(self const &other)
			{
				return (_ptr <= other._ptr);
			}

			bool			operator<(self const &other)
			{
				return (_ptr < other._ptr);
			}

			// DEREFERENCING & ADDRESS STUFF
			reference		operator*()
			{
				return (*_ptr);
			}

			const_reference	operator*() const
			{
				return (*_ptr);
			}

			pointer			operator->()
			{
				return (_ptr);
			}

			reference		operator[](size_type n)
			{
				return (*(_ptr + n));
			}

			const_reference	operator[](size_type n) const
			{
				return (*(_ptr + n));
			}
	};
}
#endif
