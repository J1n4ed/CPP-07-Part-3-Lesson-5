// table class

#pragma once

#include <iostream>
#include <vector>

// ----------------------------------------------------------------------------------------------------------------------
namespace jinx

// ----------------------------------------------------------------- ARRAY
{
	/*
	Массив для элементов
	*/
	template<class T>
	class Array
	{
	public:
		// PUBLIC AREA		

		// Public methods		

		int size()
		{
			return _size;
		}		

		// Overloads

		const T& operator [] (int index) const
		{
			if (index >= 0 && index < _size)
				return _array.at(index);
		}

		T& operator [] (int index)
		{
			if (index >= 0 && index < _size)
				return _array.at(index);
		}

		Array& operator=(const Array& other_arr)
		{
			if (this != &other_arr)
			{
				_size = other_arr._size;
				_array.resize(_size);

				_array = other_arr._array;

			} // END OF if this != &other_arr

			return *this;
		}

		// Constructors

		Array() = delete;

		Array(int size)
		{
			_size = size;
			_array.resize(_size);

			for (auto& element : _array)
			{
				element = 0;
			}
		}

		Array(const Array<T>& other_arr)
		{
			_size = other_arr._size;

			_array.resize(_size);

			_array = other_arr._array;
		}

		// Destructor

		~Array(){}

	protected:
		// PROTECTED AREA
	private:
		// PRIVATE AREA
		std::vector<T> _array;
		int _size = -1;
	};

	// ----------------------------------------------------------------- TABLE

	/*
	Таблица для массивов
	*/
	template<class T>
	class Table
	{
	public:
		// PUBLIC AREA

		// Public methods

		int length()
		{
			return _rows;
		}

		void size(int& rows, int& cols) const
		{
			if (_rows != -1 && _cols != -1)
			{
				rows = _rows;
				cols = _cols;
			}
		}

		// Overloads

		const Array<T>& operator [] (int index) const
		{
			if (index >= 0 && index < _rows)
				return _table.at(index);
		}

		Array<T>& operator [] (int index)
		{
			if (index >= 0 && index < _rows)
				return _table.at(index);
		}

		Table& operator=(Table& other_table)
		{

			if (this != &other_table)
			{

				this->_rows = other_table._rows;
				this->_cols = other_table._cols;

				_table.clear();

				for (int i = 0; i < _rows; ++i)
				{
					_table.push_back(other_table._table[i]);
				}
			} // END OF if this != &other_arr

			return *this;
		}

		// Constructors

		Table() = delete;

		Table(int rows, int cols)
		{
			_rows = rows;
			_cols = cols;

			// _table.reserve(_rows);

			for (int i = 0; i < _rows; ++i) 
			{
				Array<T> cols_element(_cols);
				_table.push_back(cols_element);
			}
		}

		// Destructor

		~Table(){}

	protected:
		// PROTECTED AREA

	private:
		// PRIVATE AREA

		std::vector<Array<T>> _table;
		int _rows = -1;
		int _cols = -1;

	}; // END OF class Table

// ----------------------------------------------------------------------------------------------------------------------
} // END OF jinx