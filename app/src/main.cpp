/**
 * \file
 * \brief main application file
 *
 * This file contains main function of application
 */

#include <tmpl/example.hpp>

#include<iostream>

using LIB_NAMESPACE::example;

int main()
{
	example e("hello app");

	std::cout << e << std::endl;
}
