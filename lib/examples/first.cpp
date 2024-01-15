#include <tmpl/example.hpp>

#include <iostream>

int main()
{
	const tmpl::example val("Hello example");

	std::cout << val << '\n';

#ifndef TMPL_NO_DEPRECATED
		std::cout << val.func();
#endif
}
