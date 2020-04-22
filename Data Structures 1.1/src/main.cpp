/*
 * main.cpp
 *
 *  Created on: 22 апр. 2020 г.
 *      Author: Сова
 */
#include "Patient.h"

int main()
{
	Patient p(Patient::MALE, 10, "Сидоров", "Усть-Залупинск", "Рак жопы");
	p.print();
}
