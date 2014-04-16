#ifndef LIN_VECTOR_H
#define LIN_VECTOR_H
#include <vector>
#include <cmath>
#include <limits>
#include <iostream>
#include <initializer_list>
#include "unequal_dimensions_exception.h"
#include "dimension_too_low_exception.h"
#include "dimension_too_high_exception.h"

namespace linear
{
template<class T, class A = std::allocator<T> >
class vector{
	public:
		/* Container values */
		typedef A allocator_type;
		typedef typename A::value_type value_type; 
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::difference_type difference_type;
		typedef typename A::size_type size_type;

		typedef typename std::vector<T>::iterator iterator;
		typedef typename std::vector<T>::const_iterator const_iterator;
		
		/* Constructors */
		vector() = default;
		vector(const std::vector<T>&);
		vector(const vector<T,A>&);
		vector(const std::initializer_list<T>);

		/* Accessors */
		T& at(const int);
		const T& at(const int) const;
		T& operator[](int index);
		const T& operator[](int index) const;
		T* data();
		void push_back(const T&);
		const T* data() const;
		iterator begin()		{ return _data.begin(); }
		const_iterator begin() const	{ return _data.begin(); }
		iterator end()			{ return _data.end(); }
		const_iterator end() const	{ return _data.end(); }
		iterator rbegin()		{ return _data.rbegin(); }
		iterator rbegin() const		{ return _data.rbegin(); }
		iterator rend()			{ return _data.rend(); }
		iterator rend() const		{ return _data.rend(); }
		const_iterator cbegin()	const	{ return _data.cbegin(); }
		const_iterator cend() const	{ return _data.cend(); }
		const_iterator crbegin() const	{ return _data.crbegin(); }
		const_iterator crend() const	{ return _data.crend(); }


		unsigned int dim() const;
	       	unsigned int size() const;	
		unsigned int max_size() const noexcept;	
		double norm(const unsigned int) const;
		bool empty() const noexcept;
		void resize (size_type n);
		void resize (size_type n, const value_type& val);
		size_type capacity() const noexcept;
		void reserve (size_type n);
		void shrink_to_fit();
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const value_type& val);
	//	void assign(initializer_list<value_type> il);
		
		iterator insert(const_iterator position, const value_type& val);
		iterator insert(const_iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		iterator insert(const_iterator position, InputIterator first, InputIterator last);
		iterator insert(const_iterator position, value_type&& val);
	//	iterator insert(const_iterator position, initializer_list<value_type> il);
		iterator erase(const_iterator position);
		iterator erase(const_iterator first, const_iterator last);
		void swap (vector& x);
		void clear() noexcept;
		template <class... Args>
		iterator emplace (const_iterator position, Args&&... args);
		template <class... Args>
		void emplace_back (Args&&... args);
		allocator_type get_allocator() const noexcept;



		/* Operators */
		vector<T,A>& operator = (const vector<T,A>&);
		vector<T,A>& operator += (const vector<T,A>&);
		vector<T,A> operator + (const vector<T,A>&) const;
		vector<T,A>& operator -= (const vector<T,A>&);
		vector<T,A> operator - (const vector<T,A>&) const;
		vector<T,A>& operator *= (const T&);
		vector<T,A> operator * (const T&) const;
		vector<T,A>& operator /= (const T&);
		vector<T,A> operator / (const T&) const;
		double dot_product(const vector<T,A>&) const;
		vector<T,A> cross_product(const vector<T,A>&) const;
		vector<double> projection(const vector<T,A>&) const;
		vector<double> unit_vector() const;
		friend std::ostream& operator<<(std::ostream& out, const vector& val)
		{
			out << "\n";
			for (auto i = val.begin(); i != val.end(); ++i)
			{
				out << "\t" << *i << "\n";
			}
			out << "\n";
			return out;
		}
		/* Type changing functions */
		// TODO: add other types.
		vector<double> to_double() const;	
	private:
		/* Data storage */
		std::vector<T> _data;

};
// include function prototype.
#include "vector.hxx"
}
#endif
