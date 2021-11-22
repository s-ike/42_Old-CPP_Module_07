#include <iostream>
#include "iter.hpp"

#define COLOR_RESET	"\033[m"
#define COLOR_CYAN	"\033[36m"

void	print_header(const std::string &str)
{
	std::cout << COLOR_CYAN "\n[ " << str << " ]" COLOR_RESET << std::endl;
}

template <class T>
void	print_const(const T& x)
{ std::cout << x << std::endl; }

template <class T>
void	print(T& x)
{ std::cout << x << std::endl; }

int	main()
{
	{
		print_header("int array");
		const int	array[] = {-1, 0, 1, 2, 3, 4};
		iter(array, sizeof(array) / sizeof(array[0]), print_const);
	}
	{
		print_header("double array");
		double	array[] = {-1.1, 0, 1.1, 1.2, 1.3, 1.4};
		iter(array, sizeof(array) / sizeof(array[0]), print_const);
	}
	{
		print_header("string array");
		const std::string	array[] = {"a", "ar", "arr", "arra", "array"};
		iter(array, sizeof(array) / sizeof(array[0]), print_const);
	}
	{
		print_header("int array (non const function)");
		const int	array[] = {-1, 0, 1, 2, 3, 4};
		iter(array, sizeof(array) / sizeof(array[0]), print);
	}
	{
		print_header("int array (function ptr is NULL)");
		const int*  array = NULL;
		iter(array, 1, print);
	}
}
