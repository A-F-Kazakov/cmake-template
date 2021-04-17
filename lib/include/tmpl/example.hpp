#ifndef TMPL_LIB_EXAMPLE_HPP
#define TMPL_LIB_EXAMPLE_HPP

#include <config.hpp>
#include <string>
#include <ostream>

namespace LIB_NAMESPACE
{
	struct example
	{
		example();
		example(std::string);

		friend std::ostream& operator<<(std::ostream&, const example&);

		private:
			std::string data;
	};

	std::ostream& operator<<(std::ostream&, const example&);
}

#endif
