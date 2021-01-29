/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traits.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:56:07 by lucas             #+#    #+#             */
/*   Updated: 2021/01/28 16:02:22 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
# define TRAITS_HPP

namespace ft
{
	struct random_access_iterator_tag
	{
	};

	template <bool B, class T = void>
		struct enable_if
		{
		};

	template <class T>
		struct enable_if<true, T>
		{
			typedef T type;
		};

	template <bool is_iterator, typename T>
		struct iterator_result
		{
			typedef T type;
			static const bool value = is_iterator;
		};

	template <typename>
		struct iterator_check : public iterator_result<false, bool>
	{
	};

	template <>
		struct iterator_check<random_access_iterator_tag>
		: public iterator_result<true, random_access_iterator_tag>
		{
		};

	template <typename T>
		struct is_iterator : public iterator_check<T>
	{
	};
} //namespace ft

#endif
