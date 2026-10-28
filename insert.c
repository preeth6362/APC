#include "apc.h"

int insert_last(List **head,List **tail,int data)
{
    List *nnode=malloc(sizeof(List));
    if(nnode==NULL)return FAILURE;
    nnode->data=data;
    nnode->prev=NULL;
    nnode->next=NULL;
    if(*head==NULL)
    {
        *head=nnode;
        *tail=nnode;
        return SUCCESS;
    }
    nnode->prev=*tail;
    (*tail)->next=nnode;
    *tail=nnode;
    return SUCCESS;
}
int insert_first(List **head,List **tail,int data)
{
    List *nnode=malloc(sizeof(List));
    if(nnode==NULL)return FAILURE;
    nnode->data=data;
    nnode->prev=NULL;
    nnode->next=NULL;
     if(*head==NULL)
    {
        *head=nnode;
        *tail=nnode;
        return SUCCESS;
    }
    nnode->next=*head;
    (*head)->prev=nnode;
    *head=nnode;
    return SUCCESS;
}
int print_list(List **head)
{
    if(*head==NULL)return FAILURE;
    List *temp=*head;
    printf("head-> %d",temp->data);
    temp=temp->next;
    while(temp!=NULL)
    {
        printf(" <-> %d",temp->data);
        temp=temp->next;
    }
    printf(" <-tail\n");
    return SUCCESS;
}