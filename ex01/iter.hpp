/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:10:49 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/22 14:41:10 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <class T>
void	iter(T* ptr, size_t len, void(*func)(const T&))
{
	if (ptr && func)
		for (size_t i = 0; i < len; i++)
			func(ptr[i]);
}

#endif /* ITER_HPP */
