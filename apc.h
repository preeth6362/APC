#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0;
#define FAILURE -1;

typedef struct list
{
    int data;
    struct list *prev;
    struct list*next;
}List;

int insert_last(List **head,List **tail,int data);
int print_list(List **head);
#endif