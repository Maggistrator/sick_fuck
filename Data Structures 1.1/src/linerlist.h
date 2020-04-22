/*
 * linerlist.h
 *
 *  Created on: 22 апр. 2020 г.
 *      Author: Сова
 */

#ifndef LINERLIST_H_
#define LINERLIST_H_
#include <iostream>
#include "Patient.h"

class LinearList {
private:
	int size = 0;
	Patient * arr;

public:
	LinearList(){}

	//добавление элемента в начало и в конец списка на выбор
	void add(Patient& p)
	{
		Patient * temp = new Patient[size+1];
		for(int i = 0; i < size; i++) temp[i] = arr[i];
		temp[size] = p;
		arr = temp;
		size++;
	}

	void print()
	{
		std::cout << "--- Список пациентов ---" << '\n';
		for(int i = 0; i < size; i++)
		{
			arr[i].print();
			std::cout << "------------------------" << '\n';
		}
	}

};
#endif /* LINERLIST_H_ */
