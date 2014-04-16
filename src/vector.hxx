/* Constructors */
template <class T, class A>
vector<T,A>::vector(const std::vector<T>& input)
				: _data{input}
{
}
template <class T, class A>
vector<T,A>::vector(const vector<T,A>& input)
				: _data{input._data}
{
}

template <class T, class A>
vector<T,A>::vector(const std::initializer_list<T> input)
				: _data{input.begin(), input.end()}
{
}
/* Accessors */
	template <class T, class A>
T& vector<T,A>::at(const int index)
{
	return this->_data.at(index);
}

template <class T, class A>
const T& vector<T,A>::at(const int index) const
{
	return this->_data.at(index);
}
	template <class T, class A>
T& vector<T,A>::operator[](int index)
{
	return this->_data[index];
}
template <class T, class A>
const T& vector<T,A>::operator[](int index) const
{
	return this->_data[index];
}
	template <class T, class A>
T* vector<T,A>::data()
{
	return this->_data.data();
}
template <class T, class A>
const T* vector<T,A>::data() const
{
	return this->_data.data();
}
	template <class T, class A>
void vector<T,A>::push_back(const T& a)
{
	this->_data.push_back(a);
}
template <class T, class A>
unsigned int vector<T,A>::dim() const
{
	return this->_data.size();
}
template <class T, class A>
unsigned int vector<T,A>::size() const
{
	return this->dim();
}
template <class T, class A>
unsigned int vector<T,A>::max_size() const noexcept
{
	return this->_data.max_size();
}

	template <class T, class A>
void vector<T,A>::resize(size_type n)
{
	this->_data.resize(n);
}
	template <class T, class A>
void vector<T,A>::resize(size_type n, const value_type& val)
{
	this->_data.resize(n, val);
}

template <class T, class A>
typename A::size_type vector<T,A>::capacity() const noexcept
{
	return this->_data.capacity();
}
	template <class T, class A>
void vector<T,A>::reserve(size_type n)
{
	return this->_data.reserve(n);
}
	template <class T, class A>
void vector<T,A>::shrink_to_fit()
{
	this->_data.shrink_to_fit();
}
	template <class T, class A>
void vector<T,A>::assign(size_type n, const value_type& val)
{
	this->_data.assign(n, val);
}
	template <class T, class A>
typename std::vector<T>::iterator vector<T,A>::insert(const_iterator position, const value_type& val)
{

}
	template <class T, class A>
typename std::vector<T>::iterator vector<T,A>::insert(const_iterator position, size_type n, const value_type& val)
{
	return this->_data.insert(position, n, val);
}
template <class T, class A>
	template <class InputIterator>
typename std::vector<T>::iterator vector<T,A>::insert(const_iterator position, InputIterator first, InputIterator last)
{
	return this->_data.insert(position, first, last);
}
	template <class T, class A>
typename std::vector<T>::iterator vector<T,A>::insert(const_iterator position, value_type&& val)
{
	return this->_data.insert(position, val);
}
	template <class T, class A>
typename std::vector<T>::iterator vector<T,A>::erase(const_iterator position)
{
	return this->_data.erase(position);
}
	template <class T, class A>
typename std::vector<T>::iterator vector<T,A>::erase(const_iterator first, const_iterator last)
{
	return this->_data.erase(first, last);
}
	template <class T, class A>
void vector<T,A>::swap(vector& x)
{
	this->_data.swap(x._data);
}
template <class T, class A>
void vector<T,A>::clear() noexcept
{
	this->_data.clear();
}
template <class T, class A>
	template <class... Args>
typename std::vector<T>::iterator vector<T,A>::emplace(const_iterator position, Args&&... args)
{
	return this->_data.emplace(position, args...);
}
template <class T, class A>
	template <class... Args>
void vector<T,A>::emplace_back(Args&&... args)
{
	this->_data.emplace(args...);
}
template <class T, class A>
A vector<T,A>::get_allocator() const noexcept
{
	return this->data.get_allocator();
}


/*


 */


template <class T, class A>
double vector<T,A>::norm(const unsigned int norm_power) const
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
template <class T, class A>
bool vector<T,A>::empty() const noexcept
{
	return this->dim() == 0;
}

/* Operators */
	template <class T, class A>
vector<T,A>& vector<T,A>::operator=(const vector<T,A>& a)
{
	if (this->dim() == a.dim())
	{
		for (unsigned int i = 0; i < this->dim(); ++i)
		{
			(*this)[i] = a[i];
		}
		return *this;
	}
	else
	{
		throw unequal_dimensions_exception();
	}
}
	template <class T, class A>
vector<T,A>& vector<T,A>::operator+=(const vector<T,A>& a)
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
template <class T, class A>
vector<T,A> vector<T,A>::operator+(const vector<T,A>& a) const
{
	vector<T,A> b(*this);
	return b += a;
}
	template <class T, class A>
vector<T,A>& vector<T,A>::operator-=(const vector<T,A>& a)
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
template <class T, class A>
vector<T,A> vector<T,A>::operator-(const vector<T,A>& a) const
{
	vector<T,A> b(*this);
	return b -= a;
}
	template <class T, class A>
vector<T,A>& vector<T,A>::operator*=(const T& a)
{
	for (unsigned int i = 0; i < this->dim(); ++i)
	{
		(*this)[i] *= a;
	}
	return *this;
}
template <class T, class A>
vector<T,A> vector<T,A>::operator*(const T& a) const
{
	vector<T,A> b(*this);
	return b *= a;
}
	template <class T, class A>
vector<T,A>& vector<T,A>::operator/=(const T& a)
{
	for (unsigned int i = 0; i < this->dim(); ++i)
	{
		(*this)[i] /= a;
	}
	return *this;
}
template <class T, class A>
vector<T,A> vector<T,A>::operator/(const T& a) const
{
	vector<T,A> b(*this);
	return b /= a;
}
template <class T, class A>
double vector<T,A>::dot_product(const vector<T,A>& a) const
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
template <class T, class A>
vector<T,A> vector<T,A>::cross_product(const vector<T,A>& a) const
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
		vector<T,A> a(x);
		return a;
	}
}
// Reminder this is a projection of b onto the direction of a (this vector).
template <class T, class A>
vector<double> vector<T,A>::projection(const vector<T,A>& b) const
{
	vector<double> a_unit(this->unit_vector());
	double scalar = b.to_double().dot_product(a_unit);
	return a_unit *= scalar;
}
template <class T, class A>
vector<double> vector<T,A>::unit_vector() const
{
	vector<double> a = this->to_double();
	return a /= this->norm(2);
}


/* Type changing functions */
template <class T, class A>
vector<double> vector<T,A>::to_double() const
{	
	vector<double> a;
	for (unsigned int i = 0; i < this->dim(); ++i)
	{
		a.push_back((double)(*this)[i]);
	}
	return a;
}




template <class T, class A>
bool operator== (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	else
	{
		for (auto i = 0; i < lhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}
		}
		return true;
	}
}

template <class T, class A>
bool operator!= (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class A>
bool operator<  (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		throw unequal_dimensions_exception();
	}
	else
	{
		for (auto i = 0; i < lhs.size(); ++i)
		{
			if (!(lhs[i] < rhs[i]))
			{
				return false;
			}
		}
		return true;
	}
}

template <class T, class A>
bool operator<= (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return (lhs < rhs) || (!(lhs < rhs) && !(rhs < lhs));
}

template <class T, class A>
bool operator>  (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return rhs < lhs;
}

template <class T, class A>
bool operator>= (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return (lhs < rhs) || (!(lhs < rhs) && !(rhs < lhs));
}

