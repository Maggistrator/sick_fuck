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
#include "list.h"

//TODO: ���������� ���������� ����������� ���������, ��������� � �������
//TODO: ������� �������� � ��������� ����������� ��������
int main()
{
	List list;
	list.read("res\\hospital.dat");

	bool running = true;
	int choice = 9;

	while (running)
	{
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
				std::cout<< "����� ����������: "; std::cin >> p.hometown;
				std::cout<< "�������: "; std::cin >> p.diagnosis;
				if(!side) list.add_begin(p);
				else list.add_end(p);
				break;
			}
			case 2:
			{
				int side = 1;
				std::cout<< "� ������ ��� � ����� ������� ������? (������ - 0/����� - 1): ";
				std::cin >> side;
				if(!side) list.del_begin();
				else list.del_end();
				break;
			}

			case 3:
				list.print(list.begin);
				break;
			case 4:
			{
				int count = 0;
				std::cout<< "������������ ��������� ��������, ����������� ��� �����-����������." << '\n';

				List::node * temp = list.begin;
				while(temp)
				{
					Patient p = temp->data;
				    int rc = strcmp(p.hometown, "�����-���������");
				    if(rc != 0) count++;
				    temp = temp->next;
				}
				std::cout<< "����������� ��������� � ������: " << count << '\n';
				break;
			}
			case 5:
			{
				std::cout<< "���������� ������� ��� ������ ���������� 55 ���, ��� ������ - 60" << '\n';
				List::node * temp = list.begin;
				while(temp)
				{
					Patient p = temp->data;
					if((p.age >= 55 && p.sex == Patient::FEMALE) || p.age >= 65)
					{
						p.print();
						std::cout << "--------" << '\n';
					}
				    temp = temp->next;
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
	}
}




