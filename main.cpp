#include <iostream>
using namespace std;
#include"Round_Bush_Set.h"
#include"Round_Bush_Vector.h"
#include "Round_Bush_Map.h"


#define DEBAG



int main() {
	setlocale(LC_ALL, "Russian");
	srand(111); // ������������ ���������� ��������� �����

	size_t ln = 30; // ������ �������
	unsigned int start_time; // ��������� �����
	unsigned int count = 0;// ������ ��������� ����
	unsigned int mid = 0; // ������ �������� �������


	unsigned int len_mid = 10; // ���������� ���������� ����� ������
	unsigned int len_search = 10000;// ������ ������

	vector<int> test_array;
	for (size_t i = 0; i < ln; i++)
		test_array.push_back(rand() % 80);



// ����  Round_Bush_Map
#ifdef DEBAG_

	Round_Bush_Map round_bush_map(10, 2);
	cout << "=============\n";

	for (size_t i = 0; i < ln; i++) {
		round_bush_map.insert(test_array[i],111, test_array[i]);
		cout << test_array[i] << ", ";
	}
	cout << "\n=============";

	round_bush_map.print_debag();
	round_bush_map.print_array();

	list<my_value> tmp;

	round_bush_map.get_sortArray_list(tmp);

	cout << "=============\n";

	for (auto x : tmp)
	{
		cout << x << ", ";
	}

	cout << "\n=============";
#endif



// ���� ���������� Round_Bush_Vector
#ifdef DEBAG

	Round_Bush_Vector round_bush_vector(10, 2);
	cout << "=============\n";

	for (size_t i = 0; i < ln; i++) {
		round_bush_vector.insert(test_array[i], test_array[i]);
		cout << test_array[i] << ", ";
	}
	cout << "\n=============";

	round_bush_vector.print_debag();
	round_bush_vector.print_array();

	list<my_value> tmp;

	round_bush_vector.get_sortArray_list(tmp);

	cout << "=============\n";

	for (auto x : tmp)
	{
		cout << x << ", ";
	}

	cout << "\n=============";
#endif


// ���� ���������� Round_Bush_Set
#ifdef DEBAG_

	Round_Bush_Set round_bush_set(10, 2);

	cout << "=============\n";

	for (size_t i = 0; i < ln; i++) {
		round_bush_set.insert(test_array[i], test_array[i]);
		cout << test_array[i] << ", ";
}
	cout << "\n=============";

	round_bush_set.print_debag();
	round_bush_set.print_array();

	list<my_value> tmp;

	round_bush_set.get_sortArray_list(tmp);

	cout << "=============\n";

	for (auto x : tmp)
	{
		cout << x << ", ";
	}

	cout << "\n=============";
#endif



// ���� ��������� �� �������� � Round_Bush_Vector
#ifdef DEBAG_
	round_bush_vector.print_debag();

	for (size_t i = 0; i < ln; i++) {
		cout << round_bush_vector.index_vector(i) << ", ";
	}
	cout << '\n';

	round_bush_vector.index_vector(5) = 11111111;

	round_bush_vector.print_debag();
#endif


// ���� ��������� std::vector � Round_Bush.Vector_RoundB � ������ ������� ������ �������� ��������� ���� int
#ifdef DEBAG_


	unsigned int rnd;
	_int_crb model = 2097152; // �������� ������������ ����
	_int_crb len_bush_array = 2; // ������ �����
	Round_Bush round_bush_vector(model, len_bush_array);

	cout << "Round_Bush_Vector: " << "Mod: " << round_bush_vector.get_mod() << " Group: " << round_bush_vector.get_len_bush_array() << '\n';

	//
	start_time = clock(); // ��������� �����
	for (size_t i = 0; i < ln; i++)
		round_bush_vector.insert(test_array[i], test_array[i]);
	cout << "����� ��������: " << clock() - start_time << '\n';
	cout << "SIZE: " << round_bush_vector.size() << '\n';
	//
	for (size_t i = 0, tim; i < len_mid; i++)
	{
		start_time = clock(); // ��������� �����
		for (size_t zi = 0; zi < len_search; zi++)
		{
			rnd = rand() % ln;

			if (round_bush_vector.search(rnd, rnd))
				count++;
		}
		tim = clock() - start_time;
		cout << "����� ������:\t\t " << clock() - start_time << '\n';
		mid += tim;
	}
	cout << "������� �����:\t\t (" << mid / len_mid << ")\n";
	cout << "������� ���������: " << count << '\n';
	//
	start_time = clock(); // ��������� �����
	round_bush_vector.clear();
	cout << "����� ��������: " << clock() - start_time << '\n';
	cout << "=============\n";


	//round_bush_set.print_debag();
	cout << "=============\n";
	//////////////////////////////////////////////


	cout << "Vector:\n";
	vector<int> Vector;
	count = 0;
	mid = 0;
	//
	start_time = clock(); // ��������� �����
	for (size_t i = 0; i < ln; i++)
		Vector.push_back(test_array[i]);
	cout << "����� ��������: " << clock() - start_time << '\n';
	cout << "SIZE: " << Vector.size() << '\n';
	//
	for (size_t i = 0, tim; i < len_mid; i++)
	{
		start_time = clock(); // ��������� �����
		for (size_t zi = 0; zi < len_search; zi++)
		{
			rnd = rand() % ln;
			if (std::find(Vector.begin(), Vector.end(), rnd) != Vector.end())
				count++;
		}
		tim = clock() - start_time;
		cout << "����� ������:\t\t " << clock() - start_time << '\n';
		mid += tim;
	}
	cout << "������� �����:\t\t (" << mid / len_mid << ")\n";
	cout << "������� ���������: " << count << '\n';
	//
	start_time = clock(); // ��������� �����
	Vector.clear();
	cout << "����� ��������: " << clock() - start_time << '\n';
	cout << "=============\n";
#endif


// ���� ������ ���� int � Vector_RoundB
#ifdef DEBAG_
	Round_Bush round_bush_vector(6, 2);

	for (size_t i = 0; i < 100; i++)
	{
		round_bush_vector.insert(test_array[i], test_array[i]);
	}

	round_bush_vector.print_debag();
	round_bush_vector.print_array();
#endif


// ���� ������ ���� float
#ifdef DEBAG_
	float fl_array[7] = { 5.123,12.123,3232.232,7231.232,2212.23,887.56,434.34 };

	Round_Bush round_bush_set(6, 2);

	for (size_t i = 0; i < 7; i++)
	{
		round_bush_set.insert(fl_array[i], fl_array[i]);
	}

	round_bush_set.print_debag();
	round_bush_set.print_array();
#endif


// ���� ������ ���� string
#ifdef DEBAG_
	string input_string = { "� ���� �������� ������ � ���� ��� �����, ����� ������ ����." };

	Round_Bush round_bush_set(6, 2);


	string word = "";
	for (auto x : input_string)
	{
		if (x == ' ')
		{
			round_bush_set.insert(word, word.length());
			word = "";
		}
		else {
			word = word + x;
		}
	}

	round_bush_set.print_debag();
	round_bush_set.print_array();
#endif


// ���� ����������� ����������
#ifdef DEBAG_

	Round_Bush_Set round_bush_set(10, 2);




	cout << "=============\n";

	for (size_t i = 0; i < ln; i++) {
		round_bush_set.insert(test_array[i], test_array[i]);
		cout << test_array[i] << ", ";
	}
	cout << "\n=============";

	round_bush_set.print_debag();
	round_bush_set.print_array();

	cout << "\n=============";
#endif


// ���� ��������� multiset � Round_Bush_Set � ������ ������� ������ �������� ��������� ���� int
#ifdef DEBAG_
	



	_int_crb model = 32; // �������� ������������ ����
	_int_crb len_bush_array = 2; // ������ �����
	Round_Bush_Set round_bush_set(model, 0);
	cout << "Round_Bush_MultiSet: " << "Mod: " << round_bush_set.get_mod() << " Group: " << round_bush_set.get_len_bush_array() << '\n';

	//
	start_time = clock(); // ��������� �����
	for (size_t i = 0; i < ln; i++)
		round_bush_set.insert(test_array[i]);
	cout << "����� ��������: " << clock() - start_time << '\n';
	cout << "SIZE: " << round_bush_set.size() << '\n';
	//
	for (size_t i = 0, tim; i < len_mid; i++)
	{
		start_time = clock(); // ��������� �����
		for (size_t zi = 0; zi < len_search; zi++)
		{
			rnd = rand() % ln;
			if (round_bush_set.search(rnd, rnd))
				count++;
		}
		tim = clock() - start_time;
		cout << "����� ������:\t\t " << clock() - start_time << '\n';
		mid += tim;
	}
	cout << "������� �����:\t\t (" << mid / len_mid << ")\n";
	cout << "������� ���������: " << count << '\n';
	//
	start_time = clock(); // ��������� �����
	round_bush_set.clear();
	cout << "����� ��������: " << clock() - start_time << '\n';
	cout << "=============\n";


	//round_bush_set.print_debag();
	cout << "=============\n";
	//////////////////////////////////////////////


	cout << "MultiSet:\n";
	multiset<int> Set;
	count = 0;
	mid = 0;
	//
	start_time = clock(); // ��������� �����
	for (size_t i = 0; i < ln; i++)
		Set.insert(test_array[i]);
	cout << "����� ��������: " << clock() - start_time << '\n';
	cout << "SIZE: " << Set.size() << '\n';
	//
	for (size_t i = 0, tim; i < len_mid; i++)
	{
		start_time = clock(); // ��������� �����
		for (size_t zi = 0; zi < len_search; zi++)
		{
			rnd = rand() % ln;
			if (Set.find(rnd) != Set.end())
				count++;
		}
		tim = clock() - start_time;
		cout << "����� ������:\t\t " << clock() - start_time << '\n';
		mid += tim;
	}
	cout << "������� �����:\t\t (" << mid / len_mid << ")\n";
	cout << "������� ���������: " << count << '\n';
	//
	start_time = clock(); // ��������� �����
	Set.clear();
	cout << "����� ��������: " << clock() - start_time << '\n';
	cout << "=============\n";
#endif




	system("pause");
}
