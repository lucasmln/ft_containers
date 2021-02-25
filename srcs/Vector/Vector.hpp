/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:42:18 by lucas             #+#    #+#             */
/*   Updated: 2021/02/25 19:39:39 by lucas            ###   ########.fr       */
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
# include "./includes/ReverseIterator.hpp"
# include "./includes/Iterator.hpp"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef T										&reference;
			typedef const T									&const_reference;
			typedef T										*pointer;
			typedef const T									*const_pointer;
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;
			typedef Iterator <value_type>					iterator;
			typedef const Iterator <value_type>				const_iterator;
			typedef ReverseIterator <value_type>			reverse_iterator;
			typedef const ReverseIterator <value_type>		const_reverse_iterator;

		private:
			Allocator	_alloc;
			pointer		_array;
			size_type	_size;
			size_type	_size_alloc;


		public:
			//default
			vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _array(NULL), _size(0), _size_alloc(0) {}
			//fill
			explicit vector(size_type n, const value_type &value = value_type(),
			const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				for (size_type i = 0; i < n; i++)
					push_back(value);
			}
			//copy
			vector(const vector& x): _alloc(x._alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				for (size_type i = 0; i < x.capacity(); i++)
					push_back(x[i]);
			}
			//range
			template <class InputIt>
				vector (InputIt first, InputIt last,
				const allocator_type& alloc = allocator_type(),
				typename InputIt::difference_type * = NULL):
				_alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
				{
					while (first != last)
					{
						this->push_back((int)*first);
						first++;
					}
				}
			//destructor
			~vector()
			{
				_alloc.destroy(_array);
			}

			template <class InputIt>
			void				assign(InputIt first, InputIt last,
				typename InputIt::difference_type * = NULL) // range
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				_size = 0;
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void				assign(size_type n, const value_type& val) //fill
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				_size = 0;
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

			iterator			end()
			{
				return (iterator(_array + _size));
			}

			const_iterator		end() const
			{
				return (const_iterator(_array + _size));
			}

			iterator			erase(iterator position)
			{
				for (iterator it = position; it + 1 != end(); it++)
					*it = *(it + 1);
				_size -= 1;
				return (position);
			}

			iterator			erase(iterator first, iterator last)
			{
				iterator f = first;
				iterator l = last;
				size_type	n = 0;;

				for (iterator it = first; it != last; it++)
					n++;
				for (iterator e = end(); f != e && l != e; f++, l++)
					*f = *l;
				_size -= n;
				return (l);
			}

			reference			front()
			{
				return (_array[0]);
			}
			
			const_reference		front() const
			{
				return (_array[0]);
			}

			allocator_type		get_allocator() const
			{
				return (_alloc);
			}

			iterator			insert(iterator position, const value_type& val) //single element
			{
				value_type		tmp;
				value_type		save;
				iterator		it = position;

				save = *(end() - 1);
				tmp = val;
				for (;it != end() - 1; it++)
				{
					std::swap(tmp, *it);
				}
				*position = val;
				push_back(save);
				std::swap(tmp, *(end() -2));
				return (position);
			}

			void insert			(iterator position, size_type n, const value_type& val) // fill
			{
				size_type		pos = 0;

				for (iterator it = begin(); it != position; it++)
					pos++;
				if (_size_alloc - _size <= n)
				{
					reserve(_size_alloc + n + 1);
					position = begin();
					for (size_type i = 0; i < pos; i++)
						position++;
				}
				for (size_type i = 0; i < n; i++)
				{
					position = insert(position, val);
					position++;
				}
			}

			template <class InputIt>
			void insert			(iterator position, InputIt first, InputIt last,
				typename InputIt::difference_type * = NULL) // range
			{
				size_type		nb = 0;
				size_type		pos = 0;

				for (iterator it = begin(); it != position; it++)
					pos++;
				for (iterator it = first; it != last; it++)
					nb++;
				if (_size_alloc - _size <= nb)
				{
					reserve(_size_alloc + nb + 1);
					position = begin();
					for (size_type i = 0; i < pos; i++)
						position++;
				}
				for (; first != last; first++)
				{
					position = insert(position, *first);
					position++;
				}
			}

			size_type			max_size(void) const
			{
				return (ULONG_MAX / sizeof(value_type));
			}

			void				pop_back()
			{
				_alloc.destroy(&back());
				_size--;
			}

			void				push_back(const_reference val)
			{
				if (_size == _size_alloc)
					reserve((_size_alloc == 0 ? 1 : _size_alloc) * 2);
				_alloc.construct(&_array[_size], val);
				_size++;
			}

			reverse_iterator	rbegin()
			{
				return (reverse_iterator(_array + _size));
			}

			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(_array + _size));
			}

			reverse_iterator		rend()
			{
				return (reverse_iterator(_array));
			}

			const_reverse_iterator		rend() const
			{
				return (const_reverse_iterator(_array));
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
				if (n > _size)
					for (size_type i = n - _size; i > 0; i--)
						push_back(val);
				else if (n < _size)
					for (size_type i = _size - n; i > 0; i--)
						pop_back();
				_size = n;
			}

			size_type			size(void) const
			{
				return (_size);
			}

			void				swap(vector& x)
			{
				std::swap(x._array, this->_array);
				std::swap(x._size, this->_size);
				std::swap(x._size_alloc, this->_size_alloc);
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
	template <class T, class Alloc>
	bool		operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (typename ft::vector<T>::iterator l = lhs.begin(), r = rhs.begin();
												l != lhs.end() ; l++, r++)
			if (*l != *r)
				return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool		operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool		operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs == rhs)
			return (false);
		for (typename ft::vector<T>::iterator l = lhs.begin(), r = rhs.begin();
													l != lhs.end(); l++, r++)
		{
			if (*l < *r)
				return (true);
			if (*l > *r)
				return (false);
		}
		return (false);
	}

	template <class T, class Alloc>
	bool		operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool		operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs == rhs)
			return (true);
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool		operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void		swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
} // namespace ft
#endif
