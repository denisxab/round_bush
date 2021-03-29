#pragma once
#include "Round_Bush_Set.h"


//				Logic
void Round_Bush_Set::insert(my_value value, _tr_int translat_int)
{
	// O(f)
	_int_crb tmp = translat_int % this->_model;
	_int_crb tmp_index_self = tmp % this->_len_bush_array;
	_int_crb tmp_index_arr = (tmp - tmp_index_self) / this->_len_bush_array;


	this->_main_array[tmp_index_arr][tmp_index_self].insert(value);
}

void Round_Bush_Set::remov(my_value value, _tr_int translat_int)
{
	// O(f)
	_int_crb tmp = translat_int % this->_model;
	_int_crb tmp_index_self = tmp % this->_len_bush_array;
	_int_crb tmp_index_arr = (tmp - tmp_index_self) / this->_len_bush_array;

	this->_main_array[tmp_index_arr][tmp_index_self].remov(value);
}

bool Round_Bush_Set::search(my_value value, _tr_int translat_int)
{
	// O(f/mod)
	_int_crb tmp = translat_int % this->_model;
	_int_crb tmp_index_self = tmp % this->_len_bush_array;
	_int_crb tmp_index_arr = (tmp - tmp_index_self) / this->_len_bush_array;

	return this->_main_array[tmp_index_arr][tmp_index_self].search(value);
}


//				Info
unsigned int Round_Bush_Set::size()
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

void Round_Bush_Set::print_debag()
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

void Round_Bush_Set::print_array()
{
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		for (_int_crb z = 0; z < this->_len_bush_array; z++) {
			this->_main_array[i][z].print();
		}
	}
	cout << '\n';

}

void Round_Bush_Set::get_sortArray_list(list<my_value>& res_array_list)
{
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		for (_int_crb z = 0; z < this->_len_bush_array; z++) {

			this->_main_array[i][z].get_array_toList(res_array_list);
		}
		res_array_list.sort();
	}
}

//				Data
Round_Bush_Set::Round_Bush_Set(_int_crb model, _int_crb len_bush_array)
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
	this->_main_array = new Sets_RoundB * [this->_model / this->_len_bush_array];


	_int_crb index_main_array = 0;
	Sets_RoundB* tmp = nullptr;
	for (_int_crb i = 0; i < this->_model; i++)
	{
		if (i % this->_len_bush_array == 0) //  аждый N раз раздел€ть
		{
			tmp = new Sets_RoundB[this->_len_bush_array];
			this->_main_array[index_main_array++] = tmp;
		}
		tmp[i % this->_len_bush_array].remainder = i;
	}
}

Round_Bush_Set::~Round_Bush_Set()
{
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		delete[] this->_main_array[i];
	}
	this->_size = 0;
	delete[] this->_main_array;
}

void Round_Bush_Set::clear() {
	for (_int_crb i = 0; i < this->_model / this->_len_bush_array; i++)
	{
		this->_main_array[i]->pArray.clear();
	}
	this->_size = 0;
}


