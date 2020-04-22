/*
 *  Patient.h
 *
 *  Created on: 22 ���. 2020 �.
 *      Author: ����
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
    	std::cout << "�������: "<< last_name << '\n';
    	std::cout << "�������: "<< age << '\n';
    	std::cout << "���: "<< (sex == 0 ? "�������" : "�������") << '\n';
    	std::cout << "�������: "<< diagnosis << '\n';
    	std::cout << "����� ����������: "<< hometown << '\n';
    }
};

#endif /* PATIENT_H_ */
