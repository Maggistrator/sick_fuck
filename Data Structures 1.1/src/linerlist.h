/*
 * linerlist.h
 *
 *  Created on: 22 ���. 2020 �.
 *      Author: ����
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
	static const int BACK = 0;
	static const int FRONT = 1;

	LinearList(){}

	//���������� �������� � ������ � � ����� ������ �� �����
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



	void print()
	{
		std::cout << "--- ������ ��������� ---" << '\n';
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
#endif /* LINERLIST_H_ */
