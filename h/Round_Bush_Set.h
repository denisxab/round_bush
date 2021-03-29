#pragma once
#include <iostream>
#include <set>
#include <list>
using namespace std;


typedef int  my_value; //Изменять на int,string,float,double
typedef set<my_value> _my_array_set; //Изменять на  set,multiset



typedef unsigned int _tr_int;//unsigned: short,int,long,
typedef unsigned int _int_crb;//unsigned: short,int,long,



class Round_Bush_Set
{
public:
	Round_Bush_Set(_int_crb model, _int_crb len_bush_array = 0);
	~Round_Bush_Set();

	void insert(my_value value, _tr_int translat_int);
	void remov(my_value value, _tr_int translat_int);
	bool search(my_value value, _tr_int translat_int);


	void clear();
	unsigned int size();
	void print_debag();
	void print_array();

	unsigned int get_mod() {return this->_model;}
	unsigned int get_len_bush_array() { return this->_len_bush_array; }
	void get_sortArray_list(list<my_value>& res_array_list);


private:
	struct Sets_RoundB
	{
		_int_crb remainder;
		_my_array_set pArray;
		Sets_RoundB() {
			this->remainder = 0;
		}

		~Sets_RoundB() {
			this->pArray.clear();
		}
		void insert(my_value value) {
			this->pArray.insert(value);
		}

		void remov(my_value value) {
			this->pArray.erase(value);
		}

		unsigned int size() {
			return this->pArray.size();
		}
		void print() {
			for (auto it = this->pArray.begin(); it != this->pArray.end(); ++it)
			{
				cout << *it << ", ";
			}
		}

		void get_array_toList(list<my_value>& list_add) {
			for (auto it = this->pArray.begin(); it != this->pArray.end(); ++it)
			{
				list_add.push_back(*it);
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

