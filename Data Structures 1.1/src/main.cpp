/*
 * main.cpp
 *
 *  Created on: 22 ���. 2020 �.
 *      Author: ����
 */
#include "Patient.h"
#include "linerlist.h"
#include <iostream>

//TODO: ���������� ���������� ����������� ���������, ��������� � �������
//TODO: ������� �������� � ��������� ����������� ��������
int main()
{
	Patient p(Patient::MALE, 10, "�������", "����-���������", "��� ����");
	Patient p1(Patient::FEMALE, 50, "��������", "�����-���������", "������-���");
	Patient p2(Patient::MALE, 20, "�������", "�����-���������", "��������");

	LinearList list;

	list.add(p);
	list.add(p1, LinearList::FRONT);
	list.add(p2);

	//list.print();
	//list.write("res\\hospital.dat");


	LinearList kek;
	kek.read("res\\hospital.dat");
	kek.print();
}




