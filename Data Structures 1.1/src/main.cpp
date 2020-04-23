/*
 * main.cpp
 *
 *  Created on: 22 апр. 2020 г.
 *      Author: Сова
 */
#include <iostream>
#include <string.h>
#include "Patient.h"
#include "linearlist.h"
#include "list.h"

//TODO: Определить количество иногородних пациентов, прибывших в клинику
//TODO: Вывести сведения о пациентах пенсионного возраста
int main()
{
	List list;
	list.read("res\\hospital.dat");

	bool running = true;
	int choice = 9;

	while (running)
	{
		std::cout<< "1 - Добавить запись" << '\n';
		std::cout<< "2 - Удалить запись" << '\n';
		std::cout<< "3 - Распечатать список" << '\n';
		std::cout<< "4 - Определить количество иногородних пациентов, прибывших в клинику" << '\n';
		std::cout<< "5 - Вывести сведения о пациентах пенсионного возраста" << '\n';
		std::cout<< "0 - Выход" << '\n';
		std::cout<< "Выберите действие: ";
		std::cin >> choice;

		switch(choice) {
			case 1:
			{
				int side = 1;
				std::cout<< "С начала или с конца добавить запись? (начало - 0/конец - 1): "; std::cin >> side;

				std::cout<< "--- Введите данные пациента ---" << '\n';

				Patient p;
				std::cout<< "Фамилия: "; std::cin >> p.last_name;
				std::cout<< "Возраст: "; std::cin >> p.age;
				std::cout<< "Пол: (м - " << p.MALE << "/ ж - " << p.FEMALE << ") "; std::cin >> p.sex;
				std::cout<< "Место проживания: "; std::cin >> p.hometown;
				std::cout<< "Диагноз: "; std::cin >> p.diagnosis;
				if(!side) list.add_begin(p);
				else list.add_end(p);
				break;
			}
			case 2:
			{
				int side = 1;
				std::cout<< "С начала или с конца удалить запись? (начало - 0/конец - 1): ";
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
				std::cout<< "Иногородними считаются пациенты, проживающие вне Санкт-Петербурга." << '\n';

				List::node * temp = list.begin;
				while(temp)
				{
					Patient p = temp->data;
				    int rc = strcmp(p.hometown, "Санкт-Петербург");
				    if(rc != 0) count++;
				    temp = temp->next;
				}
				std::cout<< "Иногородних пациентов в списке: " << count << '\n';
				break;
			}
			case 5:
			{
				std::cout<< "Пенсионный возраст для женщин составляет 55 лет, для мужчин - 60" << '\n';
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
				std::cout<< "Такой операции не существует." << '\n';
				break;
		}
	}
}




