// main function

#include "..\headers\table.h"
#include <iostream>

int main(int argc, char** argv)
{
	// VARIABLES

	int rows = 5;
	int cols = 7;

	jinx::Table<int> table(rows, cols);		

	// BODY

	std::cout << "table size:\nRows = " << rows << ", " << "cols = " << cols << '\n';

	std::cout << "Table created:\n";
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << table[i][j] << ' ';
		}

		std::cout << '\n';
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			table[i][j] = 1;
		}
	}
	
	std::cout << "\n\n";
	std::cout << "Table filled with 1s:\n";
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << table[i][j] << ' ';
		}

		std::cout << '\n';
	}

	std::cout << "\n\n";
	std::cout << "table[0][0] = 4:\n";
	table[0][0] = 4;
	std::cout << table[0][0] << '\n';
	std::cout << "\n\n";

	int newRows = 0;
	int newCols = 0;
	std::cout << "New size variables:\nnewRow = " << newRows << ", " << "newCols = " << newCols << '\n';

	table.size(newRows, newCols);

	std::cout << "Called size() method for table:\nnewRow = " << newRows << ", " << "newCols = " << newCols << '\n';

	// EXIT

	std::cout << std::endl;
	system("pause");
	return 0;
} // END OF main()