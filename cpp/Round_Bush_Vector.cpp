#pragma once
#include "Round_Bush_Vector.h"



//				Logic
void Round_Bush_Vector::insert(my_value value, _tr_int translat_int)
{
	// O(f)
	_int_crb tmp = translat_int % this->_model;
	_int_crb tmp_index_self = tmp % this->_len_bush_array;
	_int_crb tmp_index_arr = (tmp - tmp_index_self) / this->_len_bush_array;


	this->_main_array[tmp_index_arr][tmp_index_self].insert(value);
}

void Round_Bush_Vector::remov(my_value value, _tr_int translat_int)
{
	// O(f)
	_int_crb tmp = translat_int % this->_model;
	_int_crb tmp_index_self = tmp % this->_len_bush_array;
	_int_crb tmp_index_arr = (tmp - tmp_index_self) / this->_len_bush_array;

	this->_main_array[tmp_index_arr][tmp_index_self].remov(value);
}

bool Round_Bush_Vector::search(my_value value, _tr_int translat_int)
{
	// O(f/mod)
	_int_crb tmp = translat_int % this->_model;
	_int_crb tmp_index_self = tmp % this->_len_bush_array;
	_int_crb tmp_index_arr = (tmp - tmp_index_self) / this->_len_bush_array;

	return this->_main_array[tmp_index_arr][tmp_index_self].search(value);
}

my_value& Round_Bush_Vector::operator[] (const _int_crb index)
{
	_int_crb main_index_array = 0;
	_int_crb tmp_last = 0;

	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		for (_int_crb z = 0; z < this->_len_bush_array; z++) {

			main_index_array += this->_main_array[i][z].size();
			if (index < main_index_array)
			{
				return this->_main_array[i][z].pArray[index - tmp_last];
			}
			tmp_last = main_index_array;
		}
	}

	throw - 1;
	exit(0);
}

//				Info

void Round_Bush_Vector::get_sortArray_list(list<my_value>& res_array_list)
{
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		for (_int_crb z = 0; z < this->_len_bush_array; z++) {

			this->_main_array[i][z].get_array_toList(res_array_list);
		}
		res_array_list.sort();
	}
}

unsigned int Round_Bush_Vector::size()
{
	this->_size = 0;
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		for (_int_crb z = 0; z < this->_len_bush_array; z++) {
			this->_size += this->_main_array[i][z].size();
		}
	}
	return this->_size;
}

void Round_Bush_Vector::print_debag()
{
	cout << "=============\n";
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		for (_int_crb z = 0; z < this->_len_bush_array; z++) {
			cout << this->_main_array[i][z].remainder << "\t:{";
			this->_main_array[i][z].print();
			cout << "}\t";
			cout << this->_main_array[i][z].size() << '\n';

		}
		cout << "-----------\n";
	}
	cout << "SIZE: " << size() << '\n';
	cout << "=============\n";
}

void Round_Bush_Vector::print_array()
{
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		for (_int_crb z = 0; z < this->_len_bush_array; z++) {
			this->_main_array[i][z].print();
		}
	}
	cout << '\n';

}

//				Data
Round_Bush_Vector::Round_Bush_Vector(_int_crb model, _int_crb len_bush_array)
{
	if (len_bush_array == 0)// јвто определение разделителей
	{
		for (size_t i = 2; i < model; i++) // „ем меньше разделителей тем быстрее поиск
		{
			if (model % i == 0)
			{
				len_bush_array = i;
				break;
			}
		}
	}
	else if (model % len_bush_array != 0)//ѕри условии что они модуль и разделители сравнимы
	{
		throw - 1;
		exit(0);
	}

	this->_size = 0;
	this->_model = model;
	this->_len_bush_array = len_bush_array;
	this->_main_array = new Vector_RoundB * [this->_model / this->_len_bush_array];


	_int_crb index_main_array = 0;
	Vector_RoundB* tmp = nullptr;
	for (_int_crb i = 0; i < this->_model; i++)
	{
		if (i % this->_len_bush_array == 0) //  аждый N раз раздел€ть
		{
			tmp = new Vector_RoundB[this->_len_bush_array];
			this->_main_array[index_main_array++] = tmp;
		}
		tmp[i % this->_len_bush_array].remainder = i;
	}
}

Round_Bush_Vector::~Round_Bush_Vector()
{
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		delete[] this->_main_array[i];
	}
	this->_size = 0;
	delete[] this->_main_array;
}

void Round_Bush_Vector::clear() {
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		this->_main_array[i]->pArray.clear();
	}
	this->_size = 0;
}


