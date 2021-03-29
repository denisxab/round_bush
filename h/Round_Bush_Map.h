#pragma once
#include <iostream>
#include <map>
#include <list>
using namespace std;



typedef int  my_key; //Изменять на int,string,float,double
typedef int  my_value; //Изменять на int,string,float,double


typedef map<my_key,my_value> _my_array_map; //Изменять на multimap,map



typedef unsigned int _tr_int;//unsigned: short,int,long,
typedef unsigned int _int_crb;//unsigned: short,int,long,



class Round_Bush_Map
{
public:
	Round_Bush_Map(_int_crb model, _int_crb len_bush_array = 0);
	~Round_Bush_Map();

	void insert(my_key key,my_value value, _tr_int translat_int);
	void remov(my_key key, _tr_int translat_int);
	bool search(my_key key, _tr_int translat_int);


	void clear();
	unsigned int size();
	void print_debag();
	void print_array();

	unsigned int get_mod() { return this->_model; }
	unsigned int get_len_bush_array() { return this->_len_bush_array; }
	void get_sortArray_list(list<my_value>& res_array_list);


private:
	struct Sets_RoundB
	{
		_int_crb remainder;
		_my_array_map pArray;
		Sets_RoundB() {
			this->remainder = 0;
		}

		~Sets_RoundB() {
			this->pArray.clear();
		}
		void insert(my_key key,my_value value) {
			this->pArray[key] = value;
		}

		void remov(my_key key) {
			this->pArray.erase(key);
		}

		unsigned int size() {
			return this->pArray.size();
		}
		void print() {
			for (auto it : this->pArray)
			{
				cout << it.first << ':' << it.second << ", ";
			}
		}

		void get_array_toList(list<my_value>& list_add) {
			for (auto it : this->pArray)
			{
				list_add.push_back(it.first);
			}
		}


		bool search(my_value value) {
			return 	this->pArray.find(value) != this->pArray.end() ? true : false;
		}


	};

	_int_crb _model;
	_int_crb _len_bush_array;
	Sets_RoundB** _main_array;
	unsigned int _size;
};

