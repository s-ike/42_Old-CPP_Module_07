/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:36:49 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/22 12:44:13 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class T>
void	swap(T& a, T& b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template <class T>
T	min(T&a, T&b)
{
	return a < b ? a : b;
}

template <class T>
T	max(T&a, T&b)
{
	return a > b ? a : b;
}

#endif /* WHATEVER_HPP */
