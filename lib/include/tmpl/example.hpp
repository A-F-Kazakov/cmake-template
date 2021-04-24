/**
 * \file
 * \brief example interface
 *
 *	This file contains interface for example class
 */

#ifndef TMPL_LIB_EXAMPLE_HPP
#define TMPL_LIB_EXAMPLE_HPP

#include <config.hpp>
#include <string>
#include <ostream>

/**
 * \brief class interface for example purpose
 * \version v1
 * \warning This is an example
 */

namespace LIB_NAMESPACE
{
	struct example
	{
		example();
		example(std::string);

		/**
		 *
		 * copy inner data to ostream
		 * \param [out] os output stream
		 * \param [in] exmpl instance of a class
		 *
		 * \return same output stream
		*/
		friend std::ostream& operator<<(std::ostream&, const example&);

		private:
			std::string data;
	};

	std::ostream& operator<<(std::ostream&, const example&);
}

#endif
