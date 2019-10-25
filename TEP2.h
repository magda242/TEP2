#pragma once

#include <string>
#include <iostream>

#include "constants.h"

class Table {
public:
	Table();
	Table(std::string Name, int Size);
	Table(Table &pcOther);
	~Table();

	void setName(std::string Name);
	bool setNewSize(int tableLength);
	bool append(Table *other);

	Table* clone();

	void print_table();

	int* table;

private:
	std::string name;
	int size;
};

void mod_tab(Table *pcTab, int iNewSize);
void mod_tab(Table cTab, int iNewSize);
