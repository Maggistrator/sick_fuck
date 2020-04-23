/*
 * list.h
 *
 *  Created on: 23 ���. 2020 �.
 *      Author: ����
 */

#ifndef LIST_H_
#define LIST_H_
#include "Patient.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

class List
{
public:
	typedef
	struct element
	{
	   Patient data;
	   struct element * next;
	} node;

	node * begin = NULL;

	List(){}

	struct element * add_begin (Patient& x) /*���������� � ������*/
	{
	       struct element * temp;
	       temp = new node();
	       temp->data = x;
	       temp->next = begin;
	       begin = temp;
	       return temp;
	}

	struct element * add_end (Patient& x) /*���������� � �����*/
	{
	       struct element * temp = begin, * temp1;
	       temp1 = new node();
	       temp1->data = x;
	       temp1->next = NULL;
	       if (temp) /*���� ������ �� ����*/
	       {
	            while (temp->next) /*���� ���� ���� ����������*/
	               temp = temp->next; /*���������� ��������� �� ��������� ������� ������*/
	            temp->next = temp1; /*��������� ����� ������� � �����   */
	       }
	       else /*���� ����������� ������� ������*/
	            begin = temp1;
	       return begin;
	}

	struct element * del_begin () /*�������� ������� ��������*/
	{
	     struct element * temp;
	     if (begin) /*���� ������ �� ����*/
	     {
	           temp = begin;
	           begin = begin->next; /*������������ ��������� �� ��������� �������*/
	           free (temp); /*������ �������*/
	     }
	     return begin;
	}

	void del_end () /*�������� ����������*/
	{
	    node * prev = begin;
	    node * cur = begin;
		while(cur->next) {
			prev = cur;
			cur = cur->next;
		}
		delete cur;
		prev->next = NULL;
	}

	void write(std::string file)
		{
			//������� ����
			std::fstream ofs;
			ofs.open(file, std::ios::out | std::ios::trunc);
			ofs.close();

			node * temp = begin;
			while(temp){
				temp->data.write(file);
				temp = temp->next;
			}
		}

		void read(std::string file)
		{
			std::fstream ts(file, std::ios::in | std::ios::binary);

			long offset = 0;

			while(true)
			{
				Patient temp;
				ts.seekg(offset, std::ios::beg);
				if(ts.peek() != EOF)
				{
					offset = temp.read(file, offset);
					add_end(temp);
				} else break;
			}
		}

		void print (struct element * begin) /*������ ������*/
		{
		     if (!begin) /*���� ������ ����*/
		     {
		           printf ("Empty\n");
		           return;
		     }
		     while (begin) /*���� � ������ ���� ��������*/
		     {
		           begin->data.print();
		           std::cout << "----------" << '\n';
		           begin = begin->next; /*������������ ��������� �� ��������� �������*/
		     }
		}
};

#endif /* LIST_H_ */
