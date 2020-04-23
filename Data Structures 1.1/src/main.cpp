/*
 * main.cpp
 *
 *  Created on: 22 ���. 2020 �.
 *      Author: ����
 */
#include <iostream>
#include <string.h>
#include "Patient.h"
#include "linearlist.h"

//TODO: ���������� ���������� ����������� ���������, ��������� � �������
//TODO: ������� �������� � ��������� ����������� ��������
int main()
{
	LinearList list;
	list.read("res\\hospital.dat");

	bool running = true;

	while (running)
	{

		int choice = 9;
		std::cout<< "1 - �������� ������" << '\n';
		std::cout<< "2 - ������� ������" << '\n';
		std::cout<< "3 - ����������� ������" << '\n';
		std::cout<< "4 - ���������� ���������� ����������� ���������, ��������� � �������" << '\n';
		std::cout<< "5 - ������� �������� � ��������� ����������� ��������" << '\n';
		std::cout<< "0 - �����" << '\n';
		std::cout<< "�������� ��������: ";
		std::cin >> choice;

		switch(choice) {
			case 1:
			{
				int side = 1;
				std::cout<< "� ������ ��� � ����� �������� ������? (������ - 0/����� - 1): "; std::cin >> side;

				std::cout<< "--- ������� ������ �������� ---" << '\n';

				Patient p;
				std::cout<< "�������: "; std::cin >> p.last_name;
				std::cout<< "�������: "; std::cin >> p.age;
				std::cout<< "���: (� - " << p.MALE << "/ � - " << p.FEMALE << ") "; std::cin >> p.sex;
				std::cout<< "������ �����: "; std::cin >> p.hometown;
				std::cout<< "�������: "; std::cin >> p.diagnosis;
				list.add(p, (side == 0) ? LinearList::FRONT : LinearList::BACK);
				break;
			}
			case 2:
			{
				int side = 1;
				std::cout<< "� ������ ��� � ����� ������� ������? (������ - 0/����� - 1): ";
				std::cin >> side;
				list.del((side == 0) ? LinearList::FRONT : LinearList::BACK);
				break;
			}

			case 3:
				list.print();
				break;
			case 4:
			{
				int count = 0;
				std::cout<< "������������ ��������� ��������, ����������� ��� �����-����������." << '\n';
				for(int i = 0; i < list.lenght(); i++)
				{
					Patient p = list.get(i);
				    int rc = strcmp(p.hometown, "�����-���������");
				    if(rc != 0) count++;
				}
				std::cout<< "����������� ��������� � ������: " << count << '\n';
				break;
			}
			case 5:
			{
				std::cout<< "���������� ������� ��� ������ ���������� 55 ���, ��� ������ - 60" << '\n';
				for(int i = 0; i < list.lenght(); i++)
				{
					Patient p = list.get(i);
					if((p.age >= 55 && p.sex == Patient::FEMALE) || p.age >= 65)
					{
						p.print();
						std::cout << "--------" << '\n';
					}
				}
				break;
			}
			case 0:
				list.write("res\\hospital.dat");
				running = false;
				break;
			default:
				std::cout<< "����� �������� �� ����������." << '\n';
				break;
		}

//	Patient p(Patient::MALE, 10, "�������", "����-���������", "��� ����");
//	Patient p1(Patient::FEMALE, 50, "��������", "�����-���������", "������-���");
//	Patient p2(Patient::MALE, 20, "�������", "�����-���������", "��������");
	}
}




