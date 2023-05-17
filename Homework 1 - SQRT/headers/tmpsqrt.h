// template functions header

#pragma once

#include <vector>
#include <algorithm>

namespace jinx
{

template<class T>
T my_sqr(const T & element)
{
	return element * element;
}

template<class T>
std::vector<T> my_sqr(const std::vector<T> & element)
{
	std::vector<T> newElement = element;

	std::transform(newElement.begin(), newElement.end(), newElement.begin(), [](T i) -> T { return i * i; });

	return newElement;
}

} // END OF jinx