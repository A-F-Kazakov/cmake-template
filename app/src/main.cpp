#include <tmpl/example.hpp>

#include<iostream>

using LIB_NAMESPACE::example;

int main()
{
	example e("hello app");

	std::cout << e << std::endl;
}
