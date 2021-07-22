#ifndef TMPL_LIB_EXAMPLE_HPP
#define TMPL_LIB_EXAMPLE_HPP

#include <config.hpp>
#include <string>
#include <ostream>

namespace LIB_NAMESPACE
{
	 /**
	  * \brief meaningless writer object
	  *
	  * This is more complex and exaustive description of this class
	  */
	struct example
	{
		/**
		 * \effects Creates the default example object
		 */
		example();

		/**
		 * \effects creates example instance with specified string
		 */
		example(std::string);

		friend std::ostream& operator<<(std::ostream&, const example&);

		private:
			std::string data;
	};

		/**
		 * \brief example stream operator
		 *
		 * prints underlying data to specific stream
		 *
		 * \param os specific output stream
		 *
		 * \param exmpl instance of the example
		 *
		 * \returns same output stream
		*/
	std::ostream& operator<<(std::ostream& os, const example& exmpl);
}

#endif
