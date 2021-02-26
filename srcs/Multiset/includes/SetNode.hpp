/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:52:45 by lucas             #+#    #+#             */
/*   Updated: 2021/02/25 19:45:24 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETNODE_HPP
# define SETNODE_HPP

# include <cstddef>
# include <iostream>
# include "./utils.hpp"

namespace ft
{
	template <class T>
	class SetNode
	{
		public:
			typedef T		value_type;

			SetNode							*parent;
			SetNode							*right;
			SetNode							*left;
			value_type						elem;

			SetNode(value_type const &val = value_type())
			{
				elem = val;
				parent = NULL;
				right = NULL;
				left = NULL;
			}

			SetNode(value_type const &val, SetNode *depend)
			{
				elem = val;
				parent = depend;
				right = NULL;
				left = NULL;
			}

			SetNode(SetNode const &other)
			{
				parent = other.parent;
				right = other.right;
				left = other.left;
				elem = other.elem;
			}

			SetNode		&operator=(SetNode const &other)
			{
				parent = other.parent;
				right = other.right;
				left = other.left;
				elem = other.elem;
				return (*this);
			}

			~SetNode()
			{
			}

			value_type		operator->()
			{
				return (elem.first);
			}
	};
}

#endif
