#ifndef LIN_VECTOR_H
#define LIN_VECTOR_H
#include <vector>
#include <cmath>
#include <limits>
#include <iostream>
#include "unequal_dimensions_exception.h"
#include "dimension_too_low_exception.h"
#include "dimension_too_high_exception.h"
template<class T>
class lin_vector{
	public:
		/* Constructors */
		lin_vector() = default;
		lin_vector(const std::vector<T>&);
		lin_vector(const lin_vector<T>&);

		/* Accessors */
		T& at(const int);
		const T& at(const int) const;
		T& operator[](int index);
		const T& operator[](int index) const;
		T* data();
		void push_back(const T&);
		const T* data() const;
		unsigned int dim() const;
	       	unsigned int size() const;	
		double norm(const unsigned int) const;
		bool empty() const;
		/* Operators */
		lin_vector<T>& operator += (const lin_vector<T>&);
		lin_vector<T> operator + (const lin_vector<T>&) const;
		lin_vector<T>& operator -= (const lin_vector<T>&);
		lin_vector<T> operator - (const lin_vector<T>&) const;
		lin_vector<T>& operator *= (const T&);
		lin_vector<T> operator * (const T&) const;
		lin_vector<T>& operator /= (const T&);
		lin_vector<T> operator / (const T&) const;
		double dot_product(const lin_vector<T>&) const;
		lin_vector<T> cross_product(const lin_vector<T>&) const;
		lin_vector<double> projection(const lin_vector<T>&) const;
		// TODO: check to see if I can handle complex numbers.
		lin_vector<double> unit_vector() const;
		
		/* Type changing functions */
		// TODO: add other types.
		lin_vector<double> to_double() const;	
	
	private:
		/* Data storage */
		std::vector<T> _data;

};

/* Constructors */
template <class T>
lin_vector<T>::lin_vector(const std::vector<T>& input)
	: _data(input)
{
}
template <class T>
lin_vector<T>::lin_vector(const lin_vector<T>& input)
	: _data(input._data)
{
}

/* Accessors */
template <class T>
T& lin_vector<T>::at(const int index)
{
	return this->_data.at(index);
}

template <class T>
const T& lin_vector<T>::at(const int index) const
{
	return this->_data.at(index);
}
template <class T>
T& lin_vector<T>::operator[](int index)
{
	return this->_data[index];
}
template <class T>
const T& lin_vector<T>::operator[](int index) const
{
	return this->_data[index];
}
template <class T>
T* lin_vector<T>::data()
{
	return this->_data.data();
}
template <class T>
const T* lin_vector<T>::data() const
{
	return this->_data.data();
}
template <class T>
void lin_vector<T>::push_back(const T& a)
{
	this->_data.push_back(a);
}
template <class T>
unsigned int lin_vector<T>::dim() const
{
	return this->_data.size();
}
template <class T>
unsigned int lin_vector<T>::size() const
{
	return this->dim();
}
template <class T>
double lin_vector<T>::norm(const unsigned int norm_power) const
{
	T norm = 0;
	if (norm_power == std::numeric_limits<decltype(norm_power)>::max())
	{
		if (!this->empty())
		{			
			norm = (*this)[0];
		}
		for (unsigned int i = 1; i < this->dim(); ++i)
		{
			// TODO: std::max_element once iterators are defined.
			norm = std::max((*this)[i], norm);
		}
		return norm;
	}
	else if ((norm_power % 2) == 1)
	{
		for (unsigned int i = 0; i < this->dim(); ++i)
		{
			norm += pow(std::abs((*this)[i]),(T)norm_power);
		}
	}
	else
	{
		for (unsigned int i = 0; i < this->dim(); ++i)
		{
			norm += pow((*this)[i], (T)norm_power);
		}
	}
	return pow(norm, 1.0/norm_power);	
}
template <class T>
bool lin_vector<T>::empty() const
{
	return this->dim() == 0;
}

/* Operators */
template <class T>
lin_vector<T>& lin_vector<T>::operator+=(const lin_vector<T>& a)
{
	if (this->dim() == a.dim())
	{
		for (unsigned int i = 0; i < this->dim(); ++i)
		{
			(*this)[i] += a[i];
		}
		return *this;
	}
	else
	{
		throw unequal_dimensions_exception();
	}
}
template <class T>
lin_vector<T> lin_vector<T>::operator+(const lin_vector<T>& a) const
{
	lin_vector<T> b(*this);
	return b += a;
}
template <class T>
lin_vector<T>& lin_vector<T>::operator-=(const lin_vector<T>& a)
{
	if (this->dim() == a.dim())
	{
		for (unsigned int i = 0; i < this->dim(); ++i)
		{
			(*this)[i] -= a[i];
		}
		return *this;
	}
	else
	{
		throw unequal_dimensions_exception();
	}
}
template <class T>
lin_vector<T> lin_vector<T>::operator-(const lin_vector<T>& a) const
{
	lin_vector<T> b(*this);
	return b -= a;
}
template <class T>
lin_vector<T>& lin_vector<T>::operator*=(const T& a)
{
	for (unsigned int i = 0; i < this->dim(); ++i)
	{
		(*this)[i] *= a;
	}
	return *this;
}
template <class T>
lin_vector<T> lin_vector<T>::operator*(const T& a) const
{
	lin_vector<T> b(*this);
	return b *= a;
}
template <class T>
lin_vector<T>& lin_vector<T>::operator/=(const T& a)
{
	for (unsigned int i = 0; i < this->dim(); ++i)
	{
		(*this)[i] /= a;
	}
	return *this;
}
template <class T>
lin_vector<T> lin_vector<T>::operator/(const T& a) const
{
	lin_vector<T> b(*this);
	return b /= a;
}
template <class T>
double lin_vector<T>::dot_product(const lin_vector<T>& a) const
{
	double sum = 0.0;
	if (this->dim() == 0)
	{
		throw dimension_to_low_exception();
	}
	else
	{
		for (unsigned int i = 0; i < this->dim(); ++i)
		{
			sum += (*this)[i] * a[i];
		}
		return sum;
	}
}
template <class T>
lin_vector<T> lin_vector<T>::cross_product(const lin_vector<T>& a) const
{
	int s1, s2, s3;
	std::vector<T> x;
	if (this->dim() > 3 || a.dim() > 3)
	{
		throw dimension_to_high_exception();
	}
	else if (this->dim() < 3 || a.dim() < 3)
	{
		throw dimension_to_low_exception();
	}
	else
	{
		s1 = (*this)[1]*a[2] - (*this)[2]*a[1];
		x.push_back(s1);
		s2 = (*this)[2]*a[0] - (*this)[0]*a[2];
		x.push_back(s2);
		s3 = (*this)[0]*a[1] - (*this)[1]*a[0];
		x.push_back(s3);
		lin_vector<T> a(x);
		return a;
	}
}
// Reminder this is a projection of b onto the direction of a (this vector).
template <class T>
lin_vector<double> lin_vector<T>::projection(const lin_vector<T>& b) const
{
	lin_vector<double> a_unit(this->unit_vector());
	double scalar = b.to_double().dot_product(a_unit);
	return a_unit *= scalar;
}
template <class T>
lin_vector<double> lin_vector<T>::unit_vector() const
{
	lin_vector<double> a = this->to_double();
	return a /= this->norm(2);
}


/* Type changing functions */
template <class T>
lin_vector<double> lin_vector<T>::to_double() const
{	
	lin_vector<double> a;
	for (unsigned int i = 0; i < this->dim(); ++i)
	{
		a.push_back((double)(*this)[i]);
	}
	return a;
}
#endif
