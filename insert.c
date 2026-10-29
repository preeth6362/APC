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

int compare_lists(List **head1,List **tail1,List **head2,List **tail2)
{
int len1=0,len2=0;
List *temp1=*head1,*temp2=*head2;
while(temp1!=NULL)
{
    len1++;
    temp1=temp1->next;
}
while(temp2!=NULL)
{
    len2++;
    temp2=temp2->next;
}
if(len1<len2)
return SWAP;
else if(len1==len2)
{
    temp1=*head1;
    temp2=*head2;
    while(temp1!=NULL)
    {
        if(temp1->data<temp2->data)
        return SWAP;
        else if(temp1->data>temp2->data)
        return 1;
        else{
        temp1=temp1->next;
        temp2=temp2->next;
        }
    }
}
return 1;
}

int delete_list(List **head,List **tail)
{
    List *temp=*head;
    while(temp!=NULL)
    {
        *head=(*head)->next;
        free(temp);
        temp=*head;
    }
    *tail=NULL;
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