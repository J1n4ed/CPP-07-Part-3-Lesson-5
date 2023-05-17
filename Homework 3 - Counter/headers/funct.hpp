// functor header

#pragma once

#include <iostream>
#include <vector>

namespace jinx
{
	class Functor
	{
	public:
		// PUBLIC AREA

		// Public methods

		int get_sum()
		{
			return _sum;
		} // get_sum()

		int get_count()
		{
			return _counter;
		} // get_count()

		// Overloads
		
		// void operator()(const std::vector<int> & numList)
		void operator()(const int & num)
		{
			// нужно реализовать функтор, который подсчитывает сумму и количество чисел, делящихся на 3.

			if (num % 3 == 0)
			{
				_sum += num;
				++_counter;		
			}
		} // operator()

		// Constructors

		Functor()
		{
			_sum = 0;
			_counter = 0;
		}

		// Destructor

		~Functor() {}

	protected:
		// PROTECTED AREA
	private:
		// PRIVATE AREA

		int _sum = -1;
		int _counter = -1;

	}; // end of Functor class

} // END OF Jinx namespace