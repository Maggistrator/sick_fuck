/*
 * linerlist.h
 *
 *  Created on: 22 апр. 2020 г.
 *      Author: Сова
 */

#ifndef LINEARLIST_H_
#define LINEARLIST_H_
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Patient.h"

class LinearList {
private:
	int size = 0;
	Patient * arr;

public:
	static const int BACK = 1;
	static const int FRONT = 0;

	LinearList(){}

	//добавление элемента в начало и в конец списка на выбор
	void add(Patient& p, int side = BACK)
	{
		if(side == FRONT){
			Patient * temp = new Patient[size+1];
			for(int i = 0; i < size; i++) temp[i+1] = arr[i];
			temp[0] = p;
			arr = temp;
			size++;
		} else /*push back*/ {
			Patient * temp = new Patient[size+1];
			for(int i = 0; i < size; i++) temp[i] = arr[i];
			temp[size] = p;
			arr = temp;
			size++;
		}
	}

	const Patient& get(int i)
	{
		return arr[i];
	}

	int lenght()
	{
		return size;
	}

	void del(int side)
	{
		if(side == FRONT){
			Patient * temp = new Patient[size-1];
			for(int i = 1; i < size; i++) temp[i-1] = arr[i];
			arr = temp;
			size--;
		} else /*delete from back*/ {
			Patient * temp = new Patient[size-1];
			for(int i = 0; i < size-1; i++) temp[i] = arr[i];
			arr = temp;
			size--;
		}
	}

	void write(std::string file)
	{
		//Очищаем файл
		std::fstream ofs;
		ofs.open(file, std::ios::out | std::ios::trunc);
		ofs.close();

		//Записываем данные о пациентах
		for(int i = 0; i < size; i++)
		{
			arr[i].write(file);
		}
	}

	void read(std::string file)
	{
		std::fstream ts(file, std::ios::in | std::ios::binary);

		long offset = 0;

		while(true)
		{
			Patient temp;
			ts.seekg(offset, std::ios::beg);
			if(ts.peek() != EOF)
			{
				offset = temp.read(file, offset);
				add(temp);
			} else break;
		}
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

	~LinearList()
	{
		delete [] arr;
	}
};
#endif /* LINEARLIST_H_ */
