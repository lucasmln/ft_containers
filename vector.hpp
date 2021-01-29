/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:42:18 by lucas             #+#    #+#             */
/*   Updated: 2021/01/29 13:23:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <limits>
# include <sstream>
# include <iostream>
# include "traits.hpp"
//# include "ReverseIterator.hpp"
//# include "Iterator.hpp"

namespace ft
{
	template <typename T, typename R, typename P>
	class Iterator
	{
		public:
			typedef std::random_access_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	R									reference;
			typedef const R								const_reference;
			typedef T									pointer;
			typedef	ptrdiff_t							difference_type;
			typedef size_t								size_type;

		private:
			pointer						_ptr;
			typedef Iterator			self;

		public:
			Iterator() {}

			Iterator(pointer other): _ptr(other) {}

			Iterator(Iterator &other)
			{
				this->_ptr = other->_ptr;
			}

			~Iterator() {}

			Iterator	&operator=(self const &it)
			{
				_ptr = it._ptr;
				return (*this);
			}

			// INCREMENTERS
			self			operator++()
			{
				++_ptr;
				return (*this);
			}

			self			operator++(int)
			{
				self		it = *this;

				++_ptr;
				return (it);
			}

			self			operator+=(size_type nb)
			{
				_ptr += nb;
				return (*this);
			}

			self			operator--()
			{
				--_ptr;
				return (*this);
			}

			self			operator--(int)
			{
				self		it = *this;

				--_ptr;
				return (it);
			}

			self			operator-=(size_type nb)
			{
				_ptr -= nb;
				return (*this);
			}

			// ARITHMETICS
			self			operator+(difference_type n)
			{
				return (_ptr + n);
			}

			self			operator-(difference_type n)
			{
				return (_ptr - n);
			}

			self			operator+(self &other)
			{
				return (_ptr + other._ptr);
			}

			self			operator-(self &other)
			{
				return (_ptr - other._ptr);
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

	template <typename T>
	class ReverseIterator
	{
		public:
			typedef std::random_access_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	T &									reference;
			typedef T const &							const_reference;
			typedef T *									pointer;
			typedef	ptrdiff_t							difference_type;
			typedef size_t								size_type;

		private:
			pointer						_ptr;
			typedef ReverseIterator <T>	self;

		public:
			ReverseIterator(): _ptr(NULL) {}

			ReverseIterator(pointer elem)
			{
				_ptr = elem;
			}

			ReverseIterator(ReverseIterator &other)
			{
				*this = other;
			}

			~ReverseIterator() {}

			self			operator=(const self &it)
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

	template <typename T, class Allocator = std::allocator<T> >
	class Vector
	{
		public:
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef T													&reference;
			typedef const T												&const_reference;
			typedef T													*pointer;
			typedef const T												*const_pointer;
			ptrdiff_t													difference_type;
			typedef size_t												size_type;
			typedef Iterator <value_type, reference, pointer>			iterator;
			typedef const Iterator <value_type, reference, pointer>		const_iterator;
		//	typedef ReverseIterator <value_type, reference, pointer>	reverse_iterator;
		//	typedef const ReverseIterator <value_type, reference, pointer>	const_reverse_iterator;

		private:
			Allocator	_alloc;
			pointer		_array;
			size_type	_size;
			size_type	_size_alloc;


		public:
			//default
			Vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _array(NULL), _size(0), _size_alloc(0) {}
			//fill
			explicit Vector(size_type n, const value_type &value = value_type(),
			const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				for (size_type i = 0; i < n; i++)
					push_back(value);
			}
			//copy
			Vector(const Vector& x): _alloc(x._alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				for (size_type i = 0; i < x.capacity(); i++)
					push_back(x[i]);
			}
			//range
			template <class InputIt>
				Vector (InputIt first, InputIt last,
				const allocator_type& alloc = allocator_type(),
				typename enable_if<is_iterator<typename InputIt::iterator_category>::value, InputIt>::type * = nullptr):
				_alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
				{
					while (first != last)
					{
						this->push_back((int)*first);
						first++;
					}
				}
			//destructor
			~Vector()
			{
				_alloc.destroy(_array);
				_alloc.deallocate(_array, _size_alloc);
			}

			template <class InputIt>
			void				assign(InputIt first, InputIt last) //range
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_array[i]);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void				assign(size_type n, const value_type& val) //fill
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_array[i]);
				for (size_type i = 0; i < n ; i++)
					push_back(val);
			}

			reference			at(size_type i)
			{
				if (i < 0 || i >= _size_alloc)
					throw out_of_range(i);
				return (_array[i]);
			}

			const_reference		at(size_type i) const
			{
				if (i < 0 || i >= _size_alloc)
					throw out_of_range(i);
				return (_array[i]);
			}

			reference			back()
			{
				return (*(_array + _size - 1));
			}
			
			const_reference		back() const
			{
				return (*(_array + _size - 1));
			}

			iterator			begin()
			{
				return (iterator(_array));
			}
			
			const_iterator		begin() const
			{
				return (iterator(_array));
			}

			size_type			capacity() const
			{
				return (_size_alloc);
			}

			const_iterator		cbegin() const
			{
				return (const_iterator(_array));
			}
			
			iterator		end()
			{
				return (iterator(_array + _size));
			}

			const_iterator		cend() const
			{
				return (const_iterator(_array + _size));
			}

			void				clear()
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					_alloc.destroy(&(*it));
				_size = 0;
			}

			bool				empty() const
			{
				return (_size == 0 ? true : false);
			}

			reference			front()
			{
				return (_array[0]);
			}
			
			const_reference		front() const
			{
				return (_array[0]);
			}

			size_type			max_size(void) const
			{
				return (std::numeric_limits<value_type>::max());
			}

			void				push_back(const_reference val)
			{
				if (_size == _size_alloc)
					reserve((_size_alloc == 0 ? 1 : _size_alloc) * 2);
				_alloc.construct(&_array[_size], val);
				_size++;
			}

			void				reserve(size_type n)
			{
				pointer		new_array;
				
				if (n <= _size_alloc)
					return ;
				new_array = _alloc.allocate(n);
				for (size_type i = 0; i < size(); i++)
					_alloc.construct(&new_array[i], _array[i]);
				_alloc.destroy(_array);
				_alloc.deallocate(_array, _size_alloc);
				_size_alloc = n;
				_array = new_array;
			}

			void				resize(size_type n, value_type val = value_type())
			{
				std::allocator<value_type>	a;
				size_type					max = n > _size_alloc ? n : _size_alloc;
				pointer		new_array = a.allocate(max);

				if (n <= size())
				{
					for (size_type i = 0; i < n ; i++)
						a.construct(&new_array[i], _array[i]);
				}
				else
				{
					for (size_type i = 0; i < size() ; i++)
						a.construct(&new_array[i], _array[i]);
					for (size_type i = size() ; i < max ; i++)
						a.construct(&new_array[i], val);
				}
				a.destroy(_array);
				a.deallocate(_array, _size_alloc);
				_array = new_array;
				_size = n;
				_size_alloc = max;
			};

			size_type			size(void) const
			{
				return (_size);
			}

			reference			operator[](size_type i)
			{
				return (_array[i]);
			}

			const_reference		operator[] (size_type i) const
			{
				return (_array[i]);
			}

			reference			operator=(const_reference x)
			{
				this->clear();
				_alloc = x._alloc;
				for (size_type i = 0; i < _size ; i++)
					push_back(x._array[i]);
				reserve(x.capacity());
			}

			std::out_of_range	out_of_range(size_type i)
			{
				std::stringstream	ss;;

				ss << "trying to access index " << i <<
					" in vector of size_alloc " << _size_alloc << std::endl;
				return (std::out_of_range(ss.str()));
			}
	};
}
#endif
