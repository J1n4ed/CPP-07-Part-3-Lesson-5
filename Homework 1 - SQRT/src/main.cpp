// main file

#include <iostream>
#include <vector>
#include "../headers/tmpsqrt.h"

template <typename T>
void function_call(T num)
{
	std::cout << "[IN]:\t" << num;
	std::cout << "\n[OUT]:\t" << jinx::my_sqr(num);
	std::cout << std::endl;
}

template <typename T>
void function_call(std::vector<T>& num)
{
	std::vector<T> resultVect;

	std::cout << "[IN]:\t";
	for (T i : num)
	{
		std::cout << i << ' ';
	}
	std::cout << "\n[OUT]:\t";

	resultVect = jinx::my_sqr(num);

	for (T i : resultVect)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	// VARIABLES

	std::vector<int> myVectorInt{ 1, -2, 3, 4, 5 };	
	std::vector<double> myVectorDbl{ 1.5, 2.5, -3.5, 4.5, -5.5 };
	int myIntNum = 25;
	double myDblNum = 14.5;
	float myFloatNum = 2.5;
	long myLongNum = 15000;

	// BODY	

	std::cout << "SQRT CALLS:\n\n";

	function_call(myVectorInt);
	std::cout << '\n';

	function_call(myVectorDbl);
	std::cout << '\n';

	function_call(myIntNum);
	std::cout << '\n';

	function_call(myDblNum);
	std::cout << '\n';

	function_call(myFloatNum);
	std::cout << '\n';

	function_call(myLongNum);
	std::cout << '\n';	

	// CLEAR & EXIT
	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}