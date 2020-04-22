/*
 *  Patient.h
 *
 *  Created on: 22 апр. 2020 г.
 *      Author: Сова
 */

#ifndef PATIENT_H_
#define PATIENT_H_
#include <string>
#include <iostream>

class Patient {
public:
	static const int MALE = 0;
	static const int FEMALE = 1;

	int sex = 0;
	int age = 0;
	std::string last_name = "Unknown";
	std::string hometown = "Unknown";
	std::string diagnosis = "Unknown";

	Patient(){}

    Patient(int s, int a, std::string ln, std::string ht, std::string d)
    {
    	sex = s;
    	age = a;
    	last_name = ln;
    	hometown = ht;
    	diagnosis = d;
    }

    void print()
    {
    	std::cout << "Фамилия: "<< last_name << '\n';
    	std::cout << "Возраст: "<< age << '\n';
    	std::cout << "Пол: "<< (sex == 0 ? "Мужской" : "Женский") << '\n';
    	std::cout << "Диагноз: "<< diagnosis << '\n';
    	std::cout << "Место проживания: "<< hometown << '\n';
    }
};

#endif /* PATIENT_H_ */
