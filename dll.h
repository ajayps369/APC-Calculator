#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Dlist;

int print_list(Dlist *head);
int delete_zero(Dlist **head,Dlist**tail);
int delete_list(Dlist **head, Dlist **tail);
int insert_at_last(Dlist **head, Dlist **tail, int value);
int insert_at_first(Dlist **head, Dlist **tail, int value);
int character_to_int(Dlist **head, Dlist **tail, char *str);
int update(int num1,int num2,Dlist**head3,Dlist**tail3,int *borrow);
int compare_list(Dlist*op2_h,Dlist*op2_t,Dlist*op1_h,Dlist*op1_t,Dlist*temp);
void swap_list(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3);
int division_calc(Dlist**res1_h,Dlist**res1_t,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3);
void output(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3,char oper);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3);
int substraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3);
void mul_add(Dlist **res1_h, Dlist **res1_t, Dlist **res2_h, Dlist **res2_t, Dlist **res3_h, Dlist **res3_t);
int check_greater(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3,char *argv[]);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3,char oper);
int do_division(Dlist**head2,Dlist**tail2,Dlist*res1_h,Dlist*res1_t,Dlist**head3,Dlist**tail3,Dlist**Q_h,Dlist**Q_t,Dlist*temp);
int recursive_division(Dlist* res1_h, Dlist* res1_t, Dlist** head2, Dlist** tail2,Dlist**head3,Dlist**tail3,Dlist**Q_h,Dlist**Q_t,Dlist*temp);
int dl_delete_first(Dlist **head, Dlist **tail);


#endif
