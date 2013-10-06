#ifndef UNEQUAL_DIMENSIONS_EXCEPTION_H
#define UNEQUAL_DIMENSIONS_EXCEPTION_H
#include <exception>

class unequal_dimensions_exception : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "dimensions are unequal";
		}
};
#endif
