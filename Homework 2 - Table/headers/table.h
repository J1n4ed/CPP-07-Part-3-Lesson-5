// table class

#pragma once

#include <iostream>

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

		void print()
		{
			for (int i = 0; i < _size; ++i)
			{
				std::cout << i << ' ';
			}
		}

		// Overloads

		const T & operator [] (int index) const
		{
			if (index >= 0 && index < _size)
				return _array[index];
		}

		T & operator [] (int index)
		{
			if (index >= 0 && index < _size)
				return _array[index];
		}

		Array & operator=(Array & other_arr)
		{
			if (this != &other_arr)
			{

				if (this->_size() < other_arr._size())
				{
					delete[] this->_array;
					this->_size = other_arr._size;
					_array = new T[_size] {0};

					for (int i = 0; i < _size; ++i)
					{
						this->_array[i] = other_arr[i];
					}
				}
				else if (this->_size() > other_arr._size())
				{
					for (int i = 0; i < other_arr._size(); ++i)
					{
						this->_array[i] = other_arr[i];
					}
				}

			} // END OF if this != &other_arr

			return * this;
		}

		// Constructors

		Array() = delete;

		Array(int size)
		{
			_size = size;
			_array = new T[_size]{ 0 };
		}

		// Destructor

		~Array()
		{
			delete[] _array;
			_array = nullptr;
		}

	protected:
		// PROTECTED AREA
	private:
		// PRIVATE AREA
		T * _array = nullptr;
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

		// Должна быть константная функция Size, возвращающая размер таблицы.

		int length()
		{
			return _rows;
		}

		void size(int & rows, int & cols) const
		{
			if (_rows != -1 && _cols != -1)
			{
				rows = _rows;
				cols = _cols;
			}
		}

		// Overloads

		// Должны быть константная и неконстантная версии оператора [], возвращающего массив, к которому снова можно применить оператор [].

		const Array<T> & operator [] (int index) const
		{
			if (index >= 0 && index < _rows)
				return *_table[index];
		}

		Array<T> & operator [] (int index)
		{
			if (index >= 0 && index < _rows)
				return *_table[index];
		}

		Table & operator=(Table& other_arr)
		{
			if (this != &other_arr)
			{

				if (this->length() < other_arr.length())
				{
					delete[] this->_table;
					this->_rows = other_arr._rows;
					_table = new Array<T> * [_rows];

					for (int i = 0; i < _rows; ++i)
					{
						this->_table[i] = &other_arr[i];
					}
				}
				else if (this->length() > other_arr.length())
				{
					for (int i = 0; i < other_arr.length(); ++i)
					{
						this->_table[i] = &other_arr[i];
					}
				}

			} // END OF if this != &other_arr

			return * this;
		}

		// Нужно, чтобы работали конструкции вида:
		// *cout << table[i][j]; *table[i][j] = value; .		

		// Constructors

		Table() = delete;

		// Должен быть конструктор, получающий на входе два целых числа — количество строк и столбцов соответственно.

		Table(int rows, int cols)
		{
			_rows = rows;
			_cols = cols;

			_table = new Array<T> * [_rows];

			for (int i = 0; i < _rows; ++i)
			{
				_table[i] = new Array<T>(_cols);
			}
		}

		// Destructor

		~Table()
		{
			for (int i = 0; i < _rows; ++i) 
			{
				delete [] _table[i];
				_table[i] = nullptr;
			} // for (int i = 0; i < rows; ++i)
			
			_table = nullptr;
		}

	protected:
		// PROTECTED AREA

	private:
		// PRIVATE AREA

		Array<T> ** _table = nullptr;
		int _rows = -1;
		int _cols = -1;

	}; // END OF class Table

// ----------------------------------------------------------------------------------------------------------------------
} // END OF jinx