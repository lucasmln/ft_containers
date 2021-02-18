/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:07:00 by lucas             #+#    #+#             */
/*   Updated: 2021/02/18 17:02:37 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "./includes/utils.hpp"
# include <utility>
# include <iostream>
# include "./includes/Map_bidirectional_iterator.hpp"
# include "./includes/Map_reverse_bidirectional_iterator.hpp"
# include "./includes/MapNode.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key> >
	class map
	{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef Pair<key_type, mapped_type>			value_type;
			typedef Compare								key_compare;
			typedef value_type &						reference;
			typedef const value_type &					const_reference;
			typedef value_type *						pointer;
			typedef const value_type *					const_pointer;
			typedef MapIterator <value_type>			iterator;
			typedef const MapIterator <value_type>		const_iterator;
			typedef MapReverseIterator <value_type>		reverse_iterator;
			typedef const MapReverseIterator <value_type>	const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;
			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				public:
					bool operator()(const value_type &x, const value_type &y) const
					{
						return comp(x.first, y.first);
					}

				private:
					Compare comp;
					value_compare(Compare c)
					{
						this->comp = c;
					}
					friend class map;
			};

		private:
			typedef MapNode<value_type>	MapNode;
			key_compare			_comp;
			MapNode				*_top;
			MapNode				*_lower;
			MapNode				*_upper;
			size_type			_size;

			MapNode		*find_node(key_type key)
			{
				MapNode		*tmp = _top;
				value_type	val;

				val.first = key;
				val.second = 0;
				if (_size == 0)
					return (nullptr);
				while (true)
				{
					if (tmp->elem.first == val.first)
						return (tmp);
					if (value_comp()(val, tmp->elem))
					{
						if (tmp->left)
							tmp = tmp->left;
						else
							break;
					}
					else
					{
						if (tmp->right)
							tmp = tmp->right;
						else
							break;
					}
				}
				return (nullptr);
			}

			void		erase_leaf(MapNode *leaf)
			{
				if (_size == 1)
				{
					delete leaf;
					leaf = nullptr;
					_top = nullptr;
					delete _upper;
					_upper = nullptr;
					_lower = nullptr;
					_size = 0;
					return ;
				}
				if (leaf->parent && value_comp()(leaf->elem, leaf->parent->elem))
					leaf->parent->left = nullptr;
				else
				{
					if (leaf->right == _upper)
						leaf->parent->right = _upper;
					else
						leaf->parent->right = nullptr;
				}
				delete leaf;
				leaf = nullptr;
				set_upper();
				set_lower();
				_size--;
			}

			void		erase_single(MapNode *single)
			{
				if (single->left && (!single->right || single->right == _upper))
				{
					if (single->parent && value_comp()(single->elem, single->parent->elem))
						single->parent->left = single->left;
					else if (single->parent)
						single->parent->right = single->left;
					if (_top == single)
					{
						_top = single->left;
						single->left->parent = nullptr;
					}
					else
						single->left->parent = single->parent;
				}
				else if (single->right && single->right != _upper && !single->left)
				{
					if (single->parent && value_comp()(single->elem, single->parent->elem))
						single->parent->left = single->right;
					else if (single->parent)
						single->parent->right = single->right;
					single->right->parent = single->parent;
					if (single == _top)
						_top = single->right;
				}
				delete single;
				single = nullptr;
				set_upper();
				set_lower();
				_size--;
			}

			void		erase_double(MapNode *node)
			{
				MapNode		*near = node;
				MapNode		*traverser;
				value_type	tmp;

				near = near->left;
				while (near->right)
					near = near->right;
				if (node->parent)
				{
					if (value_comp()(node->elem, node->parent->elem))
						node->parent->left = near;
					else
						node->parent->right = near;
					near->parent = node->parent;
					node->parent = nullptr;
				}
				near->right = node->right;
				near->right->parent = near;
				node->right = nullptr;
				if (near->parent->elem.first != node->elem.first)
				{
					if (near->left)
					{
						traverser = near->left;
						while (traverser->left)
							traverser = traverser->left;
						traverser->left = node->right;
						node->left->parent = traverser;
					}
				//	else
				//		near->parent->parent = near;
				}
				if (node == _top)
				{
					_top = near;
					near->parent = nullptr;
				}
				delete node;
				node = nullptr;
				_size--;
			}

		public:
			explicit map(const key_compare &comp = key_compare())
			{
				_comp = comp;
				_lower = nullptr;
				_upper = nullptr;
				_top = nullptr;
				_size = 0;
			}

			map(const map& x)
			{
				_size = x._size;
				_comp = x._comp;
				_lower = x._lower;
				_upper = new MapNode(x._upper);
				_top = new MapNode(x._top);
			}

			~map()
			{
				clear();
			}

			iterator		begin()
			{
				return (iterator(_lower));
			}

			const_iterator	begin() const
			{
				return (const_iterator(_lower));
			}

			void			clear()
			{
				erase(begin(), end());
			}

			size_type		count(const key_type& k) const
			{
				if (find(k) != end())
					return (1);
				return (0);
			}

			bool			empty() const
			{
				return (_size == 0 ? true : false);
			}

			iterator		end()
			{
				return (iterator(_upper));
			}

			const_iterator	end() const
			{
				return (const_iterator(_upper));
			}

			Pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			{
				key_type	l = k;
				MapNode		*tmp = find_node(l);
				iterator	it(tmp);
				iterator	next = it;

				if (!tmp)
					return (make_pair(end(), end()));
				next++;
				return (make_pair(it, next));
			}

			Pair<iterator,iterator>				equal_range(const key_type& k)
			{
				key_type	l = k;
				MapNode		*tmp = find_node(l);
				iterator	it(tmp);
				iterator	next = it;

				if (!tmp)
					return (make_pair(end(), end()));
				next++;
				return (make_pair(it, next));
			}

			size_type		erase(const key_type& k)
			{
				MapNode		*tmp = find_node(k);

				if (!tmp)
					return (0);
				if (tmp)
				{
					if ((!tmp->left && !tmp->right) ||
										(!tmp->left && tmp->right == _upper))
						erase_leaf(tmp);
					else if ((tmp->left && (!tmp->right || tmp->right == _upper)) ||
							(tmp->right && tmp->right != _upper && !tmp->left))
						erase_single(tmp);
					else
						erase_double(tmp);
				}
				return (_size);
			}

			void			erase(iterator position)
			{
				erase(position->first);
			}

			void			erase(iterator first, iterator last)
			{
				iterator		tmp = first;

				while (first != last)
				{
					tmp++;
					erase(first);
					first = tmp;
				}
			}

			iterator				find(const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->first == k)
						return (it);
				}
				return (end());
			}

			const_iterator			find(const key_type& k) const
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->first == k)
						return (it);
				}
				return (end());
			}


			Pair<iterator,bool>		insert(const value_type& val)
			{
				MapNode		*node = _top;
				MapNode		*create = nullptr;

				if (_size == 0)
				{
					_top = new MapNode;
					_top->parent = nullptr;
					_top->elem = val;
					_lower = _top;
					_upper = new MapNode;
					_top->right = _upper;
					_upper->parent = _top;
					_size++;
					return (make_pair(iterator(_top), true));
				}
				while (true)
				{
					if (node->elem.first == val.first)
					{
						node->elem.second = val.second;
						return (make_pair(iterator(node), false));
					}
					if (value_comp()(val, node->elem))
					{
						if (node->left)
							node = node->left;
						else
						{
							create = new MapNode(val);
							create->parent = node;
							if (node->left == _lower)
								create->left = _lower;
							node->left = create;
							break ;
						}
					}
					else
					{
						if (node->right)
							node = node->right;
						else
						{
							create = new MapNode(val);
							create->parent = node;
							if (node->right == _upper)
								create->right = _upper;
							if (node == _upper)
							{
								_upper->elem = val;
								_upper->right = create;
								_upper->parent = node->parent;
								_upper = create;
							}
							else
								node->right = create;
							break ;
						}
					}
				}
				set_lower();
				_size++;
				return (make_pair(iterator(create), true));
			}

			iterator		insert(iterator position, const value_type& val)
			{
				(void)position;
				insert(val);
				return (position);
			}

			template <class InputIterator>
			void			insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			key_compare		key_comp() const
			{
				return (key_compare());
			}

			iterator		lower_bound(const key_type& k)
			{
				MapNode		*tmp = find_node(k);

				if (!tmp)
					return (end());
				if (tmp->left)
					return (iterator(tmp->left));
				return (iterator(tmp));
			}

			const_iterator		lower_bound(const key_type& k) const
			{
				MapNode		*tmp = find_node(k);

				if (!tmp)
					return (end());
				if (tmp->left)
					return (const_iterator(tmp->left));
				return (iterator(tmp));
			}

			size_type		max_size() const
			{
				return (SIZE_T_MAX / sizeof(MapNode));
			}

			reverse_iterator		rbegin()
			{
				return (reverse_iterator(_upper->parent));
			}

			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(_upper->parent));
			}

			reverse_iterator		rend()
			{
				return (reverse_iterator(_lower));
			}

			const_reverse_iterator			rend() const
			{
				return (const_reverse_iterator(_upper));
			}

			size_type		size() const
			{
				return (_size);
			}

			void			swap(map& x)
			{
				map<key_type, mapped_type>	tmp = x;

				x = *this;
				*this = tmp;
			}

			iterator		upper_bound(const key_type& k)
			{
				MapNode		*tmp = find_node(k);

				if (!tmp)
					return (end());
				if (tmp->right && tmp->right != _upper)
					return (iterator(tmp->right));
				return (iterator(tmp));
			}

			const_iterator		upper_bound(const key_type& k) const
			{
				MapNode		*tmp = find_node(k);

				if (!tmp)
					return (end());
				if (tmp->right && tmp->right != _upper)
					return (const_iterator(tmp->right));
				return (tmp);
			}

			value_compare	value_comp() const
			{
				return (value_compare(this->_comp));
			}

			mapped_type		&operator[](const key_type& k)
			{
				value_type		paire;
				MapNode			*tmp = find_node(k);

				if (tmp)
					return (tmp->elem.second);
				paire.first = k;
				paire.second = mapped_type();
				insert(make_pair(k, mapped_type()));
				return ((insert(make_pair(k, mapped_type())).first)->second);
			}

			map				&operator=(const map& x)
			{
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}


		private:
			void		set_upper()
			{
				MapNode		*node = _top;

				while (node->right)
					node = node->right;
				if (node == _upper)
					return ;
				if (_upper)
					delete _upper;
				node->right = new MapNode;
				_upper = node->right;
				_upper->parent = node;
			}

			void		set_lower()
			{
				MapNode		*node = _top;

				while (node->left)
					node = node->left;
				_lower = node;
				node->left = nullptr;
			}
};

template <class Key, class T, class Compare>
bool		operator==(const map<Key, T, Compare>& lhs,
			const map<Key, T, Compare>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (typename map<Key, T, Compare>::iterator l = lhs.begin(), r = rhs.begin();
		l != lhs.end(); l++, r++)
	{
		if (*l != *r)
			return (false);
	}
	return (true);
}

template <class Key, class T, class Compare>
bool		operator!=(const map<Key, T, Compare> &lhs,
			const map<Key, T, Compare> &rhs)
{
	return (!(lhs  == rhs));
}

template <class Key, class T, class Compare>
bool		operator<(const map<Key, T, Compare> &lhs,
			const map<Key, T, Compare> &rhs)
{
	for (typename map<Key, T, Compare>::iterator l = lhs.begin(), r = rhs.begin();
		l != lhs.end(); l++, r++)
	{
		if (*l >= *r)
			return (false);
	}
	return (true);
}

template <class Key, class T, class Compare>
bool		operator>(const map<Key, T, Compare> &lhs,
			const map<Key, T, Compare> &rhs)
{
	if (lhs == rhs)
		return (false);
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare>
bool		operator<=(const map<Key, T, Compare> &lhs,
			const map<Key, T, Compare> &rhs)
{
	if (lhs == rhs)
		return (true);
	return (lhs < rhs);
}

template <class Key, class T, class Compare>
bool		operator>=(const map<Key, T, Compare> &lhs,
			const map<Key, T, Compare> &rhs)
{
	if (lhs == rhs)
		return (true);
	return (lhs > rhs);
}

template <class Key, class T, class Compare>
void		swap(map<Key, T, Compare> &x, map<Key, T, Compare> &y)
{
	x.swap(y);
}

} // namespace ft

#endif
