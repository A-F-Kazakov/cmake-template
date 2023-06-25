/**
 * \file
 * \brief main application file
 *
 * This file contains main function of application
 */

#include <filesystem>
#include <fstream>
#include <iostream>

#include <tmpl/example.hpp>

using tmpl::example;

int main()
{
	example e{"hello app"};

	std::cout << e << std::endl;
	std::filesystem::path root{"refs"};
}
