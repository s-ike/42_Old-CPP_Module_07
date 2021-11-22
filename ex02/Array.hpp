/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:40:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/22 16:04:54 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <class T>
class Array
{
	unsigned	_size;
	T*			_array;

	bool	is_valid_index(unsigned idx) const
	{ return idx < _size; }

public:
	Array(unsigned n = 0)
		: _size(n), _array(new T[_size])
	{}
	Array(const Array& other)
		: _size(other._size), _array(new T[_size])
	{
		for (unsigned i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	Array&	operator=(const Array& other)
	{
		if (this != &other)
		{
			if (_size != other._size)
			{
				T*	temp = new T[other._size];
				delete[] _array;
				_size = other._size;
				_array = temp;
			}
			for (unsigned i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		return *this;
	}
	~Array()
	{ delete[] _array; }

	// operators
	T&	operator[](unsigned idx)
	{
		if (!is_valid_index(idx))
			throw IdxRngException();
		return _array[idx];
	}
	const T&	operator[](unsigned idx) const
	{
		if (!is_valid_index(idx))
			throw IdxRngException();
		return _array[idx];
	}

	// exceptions
	class IdxRngException : public std::exception
	{
		virtual const char*	what() const throw()
		{
			return "Out of range";
		}
	};

	// methods
	unsigned	size() const
	{ return _size; }
};

#endif /* ARRAY_HPP */
