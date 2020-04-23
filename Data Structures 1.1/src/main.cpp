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

//TODO: Определить количество иногородних пациентов, прибывших в клинику
//TODO: Вывести сведения о пациентах пенсионного возраста
int main()
{
	LinearList list;
	list.read("res\\hospital.dat");

	bool running = true;

	while (running)
	{

		int choice = 9;
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
				std::cout<< "Родной город: "; std::cin >> p.hometown;
				std::cout<< "Диагноз: "; std::cin >> p.diagnosis;
				list.add(p, (side == 0) ? LinearList::FRONT : LinearList::BACK);
				break;
			}
			case 2:
			{
				int side = 1;
				std::cout<< "С начала или с конца удалить запись? (начало - 0/конец - 1): ";
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
				std::cout<< "Иногородними считаются пациенты, проживающие вне Санкт-Петербурга." << '\n';
				for(int i = 0; i < list.lenght(); i++)
				{
					Patient p = list.get(i);
				    int rc = strcmp(p.hometown, "Санкт-Петербург");
				    if(rc != 0) count++;
				}
				std::cout<< "Иногородних пациентов в списке: " << count << '\n';
				break;
			}
			case 5:
			{
				std::cout<< "Пенсионный возраст для женщин составляет 55 лет, для мужчин - 60" << '\n';
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
				std::cout<< "Такой операции не существует." << '\n';
				break;
		}

//	Patient p(Patient::MALE, 10, "Сидоров", "Усть-Залупинск", "Рак жопы");
//	Patient p1(Patient::FEMALE, 50, "Палехова", "Санкт-Петербург", "Корона-чан");
//	Patient p2(Patient::MALE, 20, "Левихин", "Санкт-Петербург", "Заебался");
	}
}




