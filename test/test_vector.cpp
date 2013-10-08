#include "../include/lin_vector.h"
#include <iostream>
#include <vector>
#include <string>

/*
	TODO: At some point look into automated testing. Something like Ctest
*/
using namespace std;

template <class T>
void printv(string expected, lin_vector<T> a)
{
	cout << "what is expected " << expected << " what really happened = ";
	for (unsigned int i = 0; i < a.dim(); ++i)
	{
		cout << a.at(i) << " ";
	}
	cout << endl;
}

template <class T>
void printn(string expected, T a)
{
	cout << "what is expected " << expected << " what really happened = " << a << endl;
}

int main()
{
	/* Setup two vectors */
	std::vector<int> y;
	y.push_back(1);
	y.push_back(2);
	y.push_back(3);
	lin_vector<int> x(y);
	printv<int>("1 2 3", x);
	
	std::vector<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	lin_vector<int> w(q);
	printv<int>("1 2 3", w);
	
	/* Test + and += operator */
	printv<int>("(+) 2 4 6", x + w);
	x += w;
	printv<int>("(+=) 2 4 6", x);
	
	/* Test - and -= operator */
	printv<int>("(-) 1 2 3", x - w);
	x -= w;
	printv<int>("(-=) 1 2 3", x);

	/* Test dot_product */
	printn<double>("dot_product) 14", x.dot_product(w));

	/* Test * and *= operator */
	printv<int>("(*) 3 6 9", x * 3);
	x *= 3;
	printv<int>("(*=) 3 6 9", x);

	/* Test / and /= operator */
	printv<int>("(/) 1 2 3", x / 3);
	x /= 3;
	printv<int>("(/=) 1 2 3", x);

	/* Test cross_product */
	lin_vector<int> l = x.cross_product(w);
	printv<int>("(cross_product) 0 0 0", l);
	
	/* Test norms */
	printn<double>("(norm(1)) 6", x.norm(1));
	printn<double>("(norm(2)) 3.74166", x.norm(2));
	printn<double>("(infinity norm) 3", x.norm(std::numeric_limits<const unsigned int>::max()));
	
	/* Test unit_vector */
	lin_vector<double> unit = x.unit_vector();
	printv<double>("(unit_vector) 0.267261 0.534522 0.801784", unit);
	printn<double>("(unit_vector) 1", unit.dot_product(unit));

	/* Test projection */
	std::vector<int> e;
	e.push_back(1);
	e.push_back(1);
	e.push_back(1);
	lin_vector<int> a(e);
	printv("(projection) 2 2 2", a.projection(x));
}
