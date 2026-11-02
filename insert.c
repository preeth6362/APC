#include "apc.h"

int validate(char *str)
{
    if(strlen(str)>1 && str[0]=='0' && str[1]!='0')return FAILURE;
    if(strlen(str)>1 && (str[0]=='+'||str[0]=='-') && str[1]=='0' && str[2]!='0')return FAILURE;
    for(int i=0;str[i]!=0;i++)
    {
        if(i==0)
        {
        if(str[i]=='+'||str[i]=='-'||(str[i]>='0'&&str[i]<='9'))continue;
        else return FAILURE;
        }
        else if(str[i]>='0'&&str[i]<='9')continue;
        else return FAILURE;
    }
    return SUCCESS;
}
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

int compare_lists(List **head1,List **head2)
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
return SMALL;
else if(len1==len2)
{
    temp1=*head1;
    temp2=*head2;
    while(temp1!=NULL)
    {
        if(temp1->data<temp2->data)
        return SMALL;
        else if(temp1->data>temp2->data)
        return LARGE;
        else{
        temp1=temp1->next;
        temp2=temp2->next;
        }
    }
    return EQUAL;
}
return LARGE;
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
int delete_zero(List **head,List **tail)
{
  List *temp1=*head;
while(temp1!=*tail&&temp1->data==0)
{
    temp1=temp1->next;
    free(temp1->prev);
    temp1->prev=NULL;
    *head=temp1;
}
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