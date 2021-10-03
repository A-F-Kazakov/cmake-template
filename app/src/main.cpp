/**
 * \file
 * \brief main application file
 *
 * This file contains main function of application
 */

#include <iostream>
#include <tmpl/example.hpp>

using LIB_NAMESPACE::example;

int main()
{
	example e{"hello app"};

	std::cout << e << std::endl;
}
