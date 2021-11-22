/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:24:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/22 16:25:06 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Array.hpp"

#define PRG_NAME "a.out"

#define COLOR_RESET	"\033[m"
#define COLOR_RED	"\033[31m"
#define COLOR_CYAN	"\033[36m"

#define CATCH_ERR (std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl)

void	print_header(const std::string &str)
{
	std::cout << COLOR_CYAN "\n[ " << str << " ]" COLOR_RESET << std::endl;
}

void	leaks()
{
	print_header("leaks Report");
		if (system("leaks -q " PRG_NAME))
			std::cout << COLOR_RED << "LEAK!" << COLOR_RESET << std::endl;
}

template <class T>
void	put_all(const Array<T>& x)
{
	for (size_t i = 0; i < x.size(); i++)
		std::cout << '[' << i << "]: " << x[i] << '\n';
	std::cout << std::flush;
}

int	main()
{
	{
		try
		{
			print_header("empty int array");
			Array<int>	x;
			std::cout << "x.size(): " << x.size() << std::endl;

			print_header("int array(5)");
			Array<int>	y(5);
			std::cout << "y.size(): " << y.size() << std::endl;
			put_all(y);
		}
		catch (const std::bad_alloc&)
		{
			std::cout << "allocation failed" << std::endl;
		}
		catch (const std::exception& e)
		{
			CATCH_ERR;
		}
		leaks();
	}

	{
		try
		{
			print_header("empty const int array");
			const Array<int>	x;
			std::cout << "x.size(): " << x.size() << std::endl;

			print_header("int const array(5)");
			const Array<int>	y(5);
			std::cout << "y.size(): " << y.size() << std::endl;
			put_all(y);
		}
		catch (const std::bad_alloc&)
		{
			std::cout << "allocation failed" << std::endl;
		}
		catch (const std::exception& e)
		{
			CATCH_ERR;
		}
		leaks();
	}

	{
		try
		{
			print_header("empty std::string array");
			Array<std::string>	x;
			std::cout << "x.size(): " << x.size() << std::endl;

			print_header("std::string array(5)");
			Array<std::string>	y(5);
			std::cout << "y.size(): " << y.size() << std::endl;
			put_all(y);

			print_header("assign elements to std::string array(5)");
			for (size_t i = 0; i < y.size(); i++)
				y[i] = "hello";
			y[1] = "world";
			std::cout << "y =" << std::endl;
			put_all(y);

			print_header("copy test 1");
			Array<std::string>	z(y);
			std::cout << "z(y); z =" << std::endl;
			put_all(z);

			print_header("copy test 2");
			for (size_t i = 0; i < y.size(); i++)
				y[i] = "y";
			std::cout << "assign new elems to y; y =" << std::endl;
			put_all(y);
			std::cout << "z =" << std::endl;
			put_all(z);

			print_header("assignment test");
			x = z;
			std::cout << "x = z; x =" << std::endl;
			put_all(x);
		}
		catch (const std::bad_alloc&)
		{
			std::cout << "allocation failed" << std::endl;
		}
		catch (const std::exception& e)
		{
			CATCH_ERR;
		}
		leaks();
	}

	{
		try
		{
			print_header("error test");
			Array<int>	x;
			std::cout << "x.size(): " << x.size() << std::endl;
			std::cout << "x[0] =" << std::endl;
			std::cout << x[0] << std::endl;
		}
		catch (const std::bad_alloc&)
		{
			std::cout << "allocation failed" << std::endl;
		}
		catch (const std::exception& e)
		{
			CATCH_ERR;
		}
		leaks();
	}
}
