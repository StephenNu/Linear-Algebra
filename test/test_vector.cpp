#include "../include/lin_vector.h"
#include <iostream>
#include <vector>
int main()
{
	std::vector<int> y;
	y.push_back(1);
	y.push_back(2);
	y.push_back(3);
	lin_vector<int> x(y);
	for (unsigned int i = 0; i < x.dim(); ++i)
	{
		std::cout << x.at(i) << " ";
	}
	std::cout << std::endl;
	std::vector<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	lin_vector<int> w(q);
	for (unsigned int i = 0; i < w.dim(); ++i)
	{
		std::cout << w.at(i) << " ";
	}
	std::cout << std::endl;
	x += w;
	for (unsigned int i = 0; i < x.dim(); ++i)
	{
		std::cout << x.at(i) << " ";
	}
	std::cout << std::endl;
	x -= w;
	for (unsigned int i = 0; i < x.dim(); ++i)
	{
		std::cout << x.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << x.dot_product(w) << std::endl;
	x *= 3;
	for (unsigned int i = 0; i < x.dim(); ++i)
	{
		std::cout << x.at(i) << " ";
	}
	std::cout << std::endl;
	x /= 3;
	for (unsigned int i = 0; i < x.dim(); ++i)
	{
		std::cout << x.at(i) << " ";
	}
	std::cout << std::endl;
	lin_vector<int> l = x.cross_product(w);
	for (unsigned int i = 0; i < l.dim(); ++i)
	{
		std::cout << l.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "norm 1 = " << x.norm(1) << " norm 2 = " << x.norm(2);
	std::cout << " max norm = " << x.norm(std::numeric_limits<const unsigned int>::max()) << std::endl;
}
