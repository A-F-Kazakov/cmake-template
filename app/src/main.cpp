/**
 * \file
 * \brief main application file
 *
 * This file contains main function of application
 */

#include <tmpl/example.hpp>

#include <fstream>
#include <iostream>

using tmpl::example;

int main()
{
	const example val{"hello app"};

	std::cout << val << std::endl;
}
