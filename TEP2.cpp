#include "pch.h"
#include "TEP2.h"

#include <iostream>

using namespace std;


//konstruktor bezparametrowy
Table::Table() {
	setNewSize(DEFAULT_SIZE);
	name = DEFAULT_NAME;

	cout << "bezp:" + name << endl;
}

//konstruktor z parametrami
Table::Table(std::string Name, int TableLen) {
	setNewSize(TableLen);
	name = Name;

	cout << "parametr: " + name << endl;
}



//konstruktor kopiujący
Table::Table(Table &Other) {
	name = Other.name + "_copy";

	table = new int[Other.size];

//	Kopiuje tablicę int
	for (int i = 0; i < Other.size; i++)
	{
		table[i] = Other.table[i];
	}

	size = Other.size;

	cout << "kopiuj: " + name << endl;

}

Table::~Table() {
	if (table != nullptr)
	{
		delete[] table;
	}

	cout << "usuwam " + name << endl;
}


void Table::setName(string Name) {
	name = Name;
}

bool Table::setNewSize(int tableLength) {
	if (tableLength <= 0)
	{
		return false;
	}

	int* temp = new int[tableLength];

	if (temp == nullptr)
	{
		return false;
	}

	if (table != nullptr)
	{ // byla juz zainicjalizowana
		if (tableLength <= size)
		{
			for (int i = 0; i < tableLength; i++)
			{
				temp[i] = table[i];
			}
		}
		else if (tableLength > size)
		{
			for (int i = 0; i < size; i++)
			{
				temp[i] = table[i];
			}

			for (int i = size; i < tableLength; i++)
			{
				temp[i] = DEFAULT_VALUE;
			}
		}
	}
	else
	{ // inicjalizowanie pierwszy raz
		for (int i = 0; i < tableLength; i++)
		{
			temp[i] = DEFAULT_VALUE;
		}
	}

	if (table != nullptr)
	{
		delete[] table;
	}

	table = temp;
	size = tableLength;
	return true;
}



/*
Metodę, CTable *pcClone(), która zwraca nowy obiekt klasy CTable, będący klonem
obiektu dla którego pcClone() zostało wywołane.Na przykład:
CTable c_tab;
CTable *pc_new_tab;
pc_new_tab = c_tab.pcClone();*/

Table* Table::clone() {
	/*
	CTable c_tab;
	CTable *pc_new_tab;
	pc_new_tab = c_tab.pcClone();

	*/
		
	return new Table(*this);
}

// Table* a;
// a->b();
// (*a).b();

void mod_tab(Table *pcTab, int iNewSize) {
	pcTab->setNewSize(iNewSize);
}

void mod_tab(Table cTab, int iNewSize) {
	cTab.setNewSize(iNewSize);
}

void Table::print_table()
{
	cout << "[";
	for (int i = 0; i < size; i++)
	{
		cout << table[i] << " ";
	}
	cout << "]" << endl;
}


bool Table::append(Table *other) {
	setNewSize(other->size + size);
	for (int i = size; i < size + other->size; i++){
		table[i] = other->table[i];

	}
	return true;
}
int main()
{
	Table* table1 = new Table("tabela", 8);
	table1->print_table();
	table1->table[0] = 5;
	table1->table[3] = 6;
	table1->print_table();

	table1->setNewSize(3);
	table1->print_table();
	table1->setNewSize(9);
	table1->print_table();
	table1->setName("aaa");

	Table table2(*table1);

	table2.print_table();
	table2.setName("bbb");

	delete table1;

	// procedury

	mod_tab(&table2, 1);
	table2.print_table();

	mod_tab(table2, 2);
	table2.print_table();
}
