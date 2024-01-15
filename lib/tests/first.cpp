#include <tmpl/example.hpp>

#include <sstream>
#include <cassert>

int main()
{
	const std::string str{"Hello example"};
	const tmpl::example val(str);

	std::stringstream ss;
	ss << val;

	assert(ss.str() == str);
}
