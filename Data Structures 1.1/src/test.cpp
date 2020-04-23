/*односвязный линейный список*/

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

struct element * add_begin (struct element * begin, DataType x) /*добавление в начало*/
{
       struct element * temp;
       temp = (struct element *) malloc (sizeof (struct element));
       temp->data = x;
       temp->next = begin;
       return temp;
}

void insert (struct element * cur, DataType x) /*добавление после текущего*/
{
       struct element * temp;
       temp = (struct element *) malloc (sizeof (struct element));
       temp->data = x;
       temp->next = cur->next;
       cur->next = temp;
}

struct element * add_end (struct element * begin, DataType x) /*добавление в конец*/
{
       struct element * temp = begin, * temp1;
       temp1 = (struct element *) malloc (sizeof (struct element));
       temp1->data = x;
       temp1->next = NULL;
       if (temp) /*если список не пуст*/
       {
            while (temp->next) /*пока есть куда переходить*/
               temp = temp->next; /*перемещаем указатель на последний элемент списка*/
            temp->next = temp1; /*добавляем новый элемент в конец   */
       }
       else /*если добавляемый элемент первый*/
            begin = temp1;
       return begin;
}

void del_list (struct element * begin) /*удаление всего списка*/
{
     struct element * temp;
     while (begin) /*пока в списке есть элементы*/
     {
           temp = begin;
           begin = begin->next; /*переставляем указатель на следующий элемент*/
           free (temp); /*первый удаляем*/
     }
}

struct element * del_begin (struct element * begin) /*удаление первого элемента*/
{
     struct element * temp;
     if (begin) /*если список не пуст*/
     {
           temp = begin;
           begin = begin->next; /*переставляем указатель на следующий элемент*/
           free (temp); /*первый удаляем*/
     }
     return begin;
}

void del_element (struct element * cur) /*удаление после текущего*/
{
       struct element * temp;
       temp = cur->next; /*запоминаем адрес удаляемого элемента*/
       cur->next = temp->next; /*переставляем указатель с предыдущего на следующий за удаляемым элемент*/
       free (temp); /*удаляем*/
}

node * find_node (node * cur, DataType x) /*поиск элемента со значением х*/
{
     while (cur && cur->data != x) /*пока в списке есть элементы и они не равны х*/
           cur = cur->next; /*переставляем указатель на следующий элемент*/
     return cur;
}

void print_list (struct element * begin) /*печать списка*/
{
     if (!begin) /*если список пуст*/
     {
           printf ("Empty\n");
           return;
     }
     while (begin) /*пока в списке есть элементы*/
     {
           print (begin->data);
           begin = begin->next; /*переставляем указатель на следующий элемент*/
     }
}

void print_list_recursive (struct element * begin) /*рекурсивная функция печати списка*/
{
     if (begin) /*если есть что выводить*/
     {
        print (begin->data); /*выводим текущее значение*/
        print_list_recursive (begin->next); /*печатаем список, начинающийся со следующего элемента*/
     }
}

void print_list_recursive_back (struct element * begin) /*рекурсивная функция печати списка в обратном порядке*/
{
     if (begin) /*если есть список*/
     {
        print_list_recursive_back (begin->next); /*печатаем список, начинающийся со следующего элемента*/
        print (begin->data); /*печатаем текущее значение*/
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
  begin = del_begin (begin); /*удаляем первый элемент*/
  print_list (begin);
  printf ("\n");
  del_element (begin);/*удаляем второй элемент*/
  print_list (begin);
  printf ("\n");
  del_element (begin->next);/*удаляем третий элемент*/
  print_list (begin);
  printf ("\n");
  del_list (begin);
  begin = NULL; /*обнуляем указатель после удаления списка !*/
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
