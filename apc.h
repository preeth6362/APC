#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define SWAP -2

typedef struct list
{
    int data;
    struct list *prev;
    struct list*next;
}List;

int insert_last(List **head,List **tail,int data);
int print_list(List **head);
int insert_first(List **head,List **tail,int data);
int addition(List **tail1,List **tail2,List **headr,List **tailr);
int subraction(List **tail1,List **tail2,List **headr,List **tailr,char sign);
int compare_lists(List **head1,List **tail1,List **head2,List **tail2);
#endif