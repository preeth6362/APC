#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1
#define SMALL -2
#define LARGE -3
#define EQUAL -4


typedef struct list
{
    int data;
    struct list *prev;
    struct list*next;
}List;

int validate(char *str);
int insert_last(List **head,List **tail,int data);
int print_list(List **head);
int insert_first(List **head,List **tail,int data);
int addition(List **tail1,List **tail2,List **headr,List **tailr,int sign);
int subraction(List **tail1,List **tail2,List **headr,List **tailr,int sign);
int compare_lists(List **head1,List **head2);
int multiply(List **tail1,List **tail2,List **headr,List **tailr,int sign);
int delete_list(List **head,List **tail);
int delete_zero(List **head,List **tail);
int divide(List **head1,List **head2,List **tail2,List **headr,List **tailr,int sign);
#endif