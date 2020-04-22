/*
 * main.cpp
 *
 *  Created on: 22 ���. 2020 �.
 *      Author: ����
 */
#include "Patient.h"
#include "linerlist.h"
#include <iostream>

int main()
{
	Patient p(Patient::MALE, 10, "�������", "����-���������", "��� ����");
	Patient p1(Patient::FEMALE, 10, "��������", "�����-���������", "������-���");
	Patient p2(Patient::MALE, 10, "�������", "�����-���������", "��������");

	LinearList list;

	list.add(p);
	list.add(p1, LinearList::FRONT);
	list.add(p2);

	list.print();

	list.del(LinearList::BACK);
	std::cout << "DELETED BACK" << '\n';
	list.print();

	list.del(LinearList::FRONT);
	std::cout << "DELETED FRONT" << '\n';
	list.print();
}
