/*����������� �������� ������*/

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

void print (DataType x)
{
     printf ("%d ", x);
}

/*struct element
{
       DataType data;
       struct element * next;
};*/
typedef
struct element
{
   DataType data;
   struct element * next;
} node;

struct element * add_begin (struct element * begin, DataType x) /*���������� � ������*/
{
       struct element * temp;
       temp = (struct element *) malloc (sizeof (struct element));
       temp->data = x;
       temp->next = begin;
       return temp;
}

void insert (struct element * cur, DataType x) /*���������� ����� ��������*/
{
       struct element * temp;
       temp = (struct element *) malloc (sizeof (struct element));
       temp->data = x;
       temp->next = cur->next;
       cur->next = temp;
}

struct element * add_end (struct element * begin, DataType x) /*���������� � �����*/
{
       struct element * temp = begin, * temp1;
       temp1 = (struct element *) malloc (sizeof (struct element));
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

void del_list (struct element * begin) /*�������� ����� ������*/
{
     struct element * temp;
     while (begin) /*���� � ������ ���� ��������*/
     {
           temp = begin;
           begin = begin->next; /*������������ ��������� �� ��������� �������*/
           free (temp); /*������ �������*/
     }
}

struct element * del_begin (struct element * begin) /*�������� ������� ��������*/
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

void del_element (struct element * cur) /*�������� ����� ��������*/
{
       struct element * temp;
       temp = cur->next; /*���������� ����� ���������� ��������*/
       cur->next = temp->next; /*������������ ��������� � ����������� �� ��������� �� ��������� �������*/
       free (temp); /*�������*/
}

node * find_node (node * cur, DataType x) /*����� �������� �� ��������� �*/
{
     while (cur && cur->data != x) /*���� � ������ ���� �������� � ��� �� ����� �*/
           cur = cur->next; /*������������ ��������� �� ��������� �������*/
     return cur;
}

void print_list (struct element * begin) /*������ ������*/
{
     if (!begin) /*���� ������ ����*/
     {
           printf ("Empty\n");
           return;
     }
     while (begin) /*���� � ������ ���� ��������*/
     {
           print (begin->data);
           begin = begin->next; /*������������ ��������� �� ��������� �������*/
     }
}

void print_list_recursive (struct element * begin) /*����������� ������� ������ ������*/
{
     if (begin) /*���� ���� ��� ��������*/
     {
        print (begin->data); /*������� ������� ��������*/
        print_list_recursive (begin->next); /*�������� ������, ������������ �� ���������� ��������*/
     }
}

void print_list_recursive_back (struct element * begin) /*����������� ������� ������ ������ � �������� �������*/
{
     if (begin) /*���� ���� ������*/
     {
        print_list_recursive_back (begin->next); /*�������� ������, ������������ �� ���������� ��������*/
        print (begin->data); /*�������� ������� ��������*/
     }
}

int maind(int argc, char *argv[])
{
  struct element * begin = NULL;
  int a;

  for (a=1; a<5; a++)
      begin = add_begin (begin, a);
  print_list (begin);
  printf ("\n");
  for (a=10; a<15; a++)
      begin = add_end (begin, a);
  print_list (begin);
  printf ("\n");
  begin = del_begin (begin); /*������� ������ �������*/
  print_list (begin);
  printf ("\n");
  del_element (begin);/*������� ������ �������*/
  print_list (begin);
  printf ("\n");
  del_element (begin->next);/*������� ������ �������*/
  print_list (begin);
  printf ("\n");
  del_list (begin);
  begin = NULL; /*�������� ��������� ����� �������� ������ !*/
  for (a=10; a<15; a++)
      begin = add_end (begin, a);
  print_list (begin);
  printf ("\n");
  print_list_recursive (begin);
  printf ("\n");
  print_list_recursive_back (begin);
  printf ("\n");
  del_list (begin);
  system("PAUSE");
  return 0;
}
