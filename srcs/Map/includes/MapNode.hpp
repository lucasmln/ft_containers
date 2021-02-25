/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:12:42 by lucas             #+#    #+#             */
/*   Updated: 2021/02/25 19:44:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
# define MAPNODE_HPP

# include <cstddef>
# include <iostream>

namespace ft
{
	template <class T>
	class MapNode
	{
		public:
			typedef T		value_type;

			MapNode			*parent;
			MapNode			*right;
			MapNode			*left;
			value_type		elem;

			MapNode(value_type const &val = value_type())
			{
				elem = val;
				parent = NULL;
				right = NULL;
				left = NULL;
			}

			MapNode(value_type const &val, MapNode *depend)
			{
				elem = val;
				parent = depend;
				right = NULL;
				left = NULL;
			}

			MapNode(MapNode const &other)
			{
				parent = other.parent;
				right = other.right;
				left = other.left;
				elem = other.elem;
			}

			MapNode		&operator=(MapNode const &other)
			{
				parent = other.parent;
				right = other.right;
				left = other.left;
				elem = other.elem;
				return (*this);
			}

			~MapNode()
			{
			}

			value_type		operator->()
			{
				return (elem);
			}
	};
}

#endif
