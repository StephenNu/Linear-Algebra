#ifndef DIMENSION_TO_LOW_EXCEPTION_H
#define DIMENSION_TO_LOW_EXCEPTION_H
#include <exception>

class dimension_to_low_exception : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "dimension is to low for that operation";
		}
};
#endif
