/*
 * main.cpp
 *
 *  Created on: 22 апр. 2020 г.
 *      Author: Сова
 */
#include "Patient.h"
#include "linerlist.h"
#include <iostream>

//TODO: Определить количество иногородних пациентов, прибывших в клинику
//TODO: Вывести сведения о пациентах пенсионного возраста
int main()
{
	Patient p(Patient::MALE, 10, "Сидоров", "Усть-Залупинск", "Рак жопы");
	Patient p1(Patient::FEMALE, 50, "Палехова", "Санкт-Петербург", "Корона-чан");
	Patient p2(Patient::MALE, 20, "Левихин", "Санкт-Петербург", "Заебался");

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




