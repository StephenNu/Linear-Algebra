#include "vector.h"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
/*
   To run automated test go to test directory and run the commands "make", then "make test"
*/
using namespace std;

template <class T>
void printv(std::vector<T> expected, linear::vector<T> a)
{
	for (unsigned int i = 0; i < a.dim(); ++i)
	{
		cout << "what is expected " << expected.at(i) << " what really happened = " << a.at(i) << endl;
		if (std::numeric_limits<T>::is_integer)
		{
			assert(expected.at(i) == a.at(i));
		}
		else
		{
			assert(abs(expected.at(i)-a.at(i)) <= numeric_limits<T>::epsilon() * max(abs(expected.at(i)), abs(a.at(i))) * 4);
		}
	}
	cout << endl;
}

template <class T>
void printn(T expected, T a)
{
	cout << "what is expected " << expected << " what really happened = " << a << endl;
	assert(expected == a);
}

int main()
{
	/* Setup two vectors */
	std::vector<int> y;
	y.push_back(1);
	y.push_back(2);
	y.push_back(3);
	linear::vector<int> x(y);
	printv(std::vector<int>{1, 2, 3}, x);
	
	for (auto it = x.begin(); it != x.end(); ++it)
	{
		cout << *it;
	}
	cout << x;
	
	
	linear::vector<int> w{1,2,3};
	printv(std::vector<int>{1, 2, 3}, w);
	
	linear::vector<int> k{1,1,1};
	printv(std::vector<int>{1, 1, 1}, k);

	/* Test = operator */
	k = y;
	printv(std::vector<int>{1, 2, 3}, k);
	linear::vector<int> o = k;
	printv(std::vector<int>{1, 2, 3}, o);	

	/* Test + and += operator */
	printv(std::vector<int>{2, 4, 6}, x + w);
	x += w;
	printv(std::vector<int>{2, 4, 6}, x);
	
	/* Test - and -= operator */
	printv(std::vector<int>{1, 2, 3}, x - w);
	x -= w;
	printv(std::vector<int>{1, 2, 3}, x);

	/* Test dot_product */
	printn<double>(14.0, x.dot_product(w));

	/* Test * and *= operator */
	printv(std::vector<int>{3, 6, 9}, x * 3);
	x *= 3;
	printv(std::vector<int>{3, 6, 9}, x);

	/* Test / and /= operator */
	printv(std::vector<int>{1, 2, 3}, x / 3);
	x /= 3;
	printv(std::vector<int>{1, 2, 3}, x);

	/* Test cross_product */
	linear::vector<int> l = x.cross_product(w);
	printv(std::vector<int>{0, 0, 0}, l);
	
	/* Test norms */
	printn<double>(6.0, x.norm(1));
	printn<double>(sqrt(14), x.norm(2));
	printn<double>(3.0, x.norm(std::numeric_limits<const unsigned int>::max()));
	
	/* Test unit_vector */
	linear::vector<double> unit = x.unit_vector();
	printv<double>(std::vector<double>{1/sqrt(14), sqrt(2.0/7.0), 3/sqrt(14)}, unit);
	printn<double>(1, unit.dot_product(unit));

	/* Test projection */
	std::vector<int> e;
	e.push_back(1);
	e.push_back(1);
	e.push_back(1);
	linear::vector<int> a(e);
	printv(std::vector<double>{2,2,2}, a.projection(x));
}
